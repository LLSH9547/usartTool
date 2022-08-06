#include "widget.h"
#include "ui_widget.h"
#include <QMovie>
#include <QCoreApplication>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QTextCursor>
#include "mystring.h"
#include <QDebug>
#include <string.h>
#include <qfile.h>
#include <qpushbutton.h>





/**
 * @brief
 * @param parent
 */
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setMinimumWidth(600);
    this->setMinimumHeight(700);
    this->setWindowTitle("串口工具");
    this->setWindowIcon(QIcon(":/new/prefix1/logo.ico"));
    messagebox.setWindowIcon(QIcon(":/new/prefix1/logo.ico"));


    ui->lineEdit_2->setText("3606000000009917");
    Time1_2S = new myTimer(2000);
    Time2_5S = new myTimer(5000);

    Time1_2S->myTimerStop();
    Time2_5S->myTimerStop();

    ui->spinBox_5->setValue(10);


    ui->spinBox_4->setValue(0);
    ui->spinBox_2->setValue(30);
    ui->spinBox->setValue(1);
    ui->spinBox_3->setMaximum(10000);
    ui->spinBox_2->setMaximum(24*60);
    serialPort = new QSerialPort(this);

    for(const QSerialPortInfo &inf0:QSerialPortInfo::availablePorts()){
        serialNamePortDisplay<<inf0.portName()+"("+inf0.description()+")";
    }
    ui->serialBox->addItems(serialNamePortDisplay);
    ui->lineEdit->setFocusPolicy(Qt::NoFocus);
    connect(ui->serialBox,&myCombox::sendComboBoxPress,this,&Widget::upSerialCOMData);
    connect(serialPort,&QSerialPort::readyRead,this,&Widget::ReadRecData);


    connect(this->Time1_2S,&myTimer::sendTimeOut,this,&Widget::SendEnFlag);
    connect(this->Time2_5S,&myTimer::sendTimeOut,this,&Widget::SetErrorFlag);
    connect(this,&Widget::stopRun,this,&Widget::setComplete);
}

/**
 * @brief 变形2014设置流量指令
 * @param array 数据段首地址
 * @return 数据长度
 */
uint16_t Widget::setVol_2014(uint8_t array[])
{
    uint16_t index=0;

    array[index++]=0x68;

    array[index++]=0x00;
    array[index++]=0x12;

    array[index++]=0x68;

    array[index++]=0x81;
    array[index++]=0x01;

    array[index++]=motor_address[7];
    array[index++]=motor_address[6];
    array[index++]=motor_address[5];
    array[index++]=motor_address[4];
    array[index++]=motor_address[3];
    array[index++]=motor_address[2];
    array[index++]=motor_address[1];
    array[index++]=motor_address[0];

    array[index++]=0x01;
    array[index++]=0x01;

    array[index++]=0x05;
    array[index++]=0x01;//小数点位数

    array[index++]=(vol>>24)&0xff;
    array[index++]=(vol>>16)&0xff;
    array[index++]=(vol>>8)&0xff;
    array[index++]=(vol)&0xff;

    array[index]=arraySum(&array[4],index-4);
    index++;
    array[index++]=0x16;
    return index;

}

/**
 * @brief 编写2014设置时间指令
 * @param array 数据段首地址
 * @return 数据长度
 */
uint16_t Widget::setTime_2014(uint8_t array[])
{
    uint16_t index=0;

    array[index++]=0x68;

    array[index++]=0x00;
    array[index++]=0x14;

    array[index++]=0x68;

    array[index++]=0x81;
    array[index++]=0x01;

    array[index++]=motor_address[7];
    array[index++]=motor_address[6];
    array[index++]=motor_address[5];
    array[index++]=motor_address[4];
    array[index++]=motor_address[3];
    array[index++]=motor_address[2];
    array[index++]=motor_address[1];
    array[index++]=motor_address[0];

    array[index++]=0x00;
    array[index++]=0x06;

    array[index++]=0x07;

    array[index++]=0x20;
    if(currentTime>24*60)
    {
        curretDay++;

        this->rtc[2]=time.date().toString("d").toUInt() & 0xff;
        this->rtc[1]=time.date().toString("M").toUInt() & 0xff;
        this->rtc[0]=time.date().toString("yy").toUInt() & 0xff;

        this->rtc[0]=this->rtc[0]/10*16 + this->rtc[0]%10;
        this->rtc[1]=this->rtc[1]/10*16 + this->rtc[1]%10;
        this->rtc[2]=this->rtc[2]/10*16 + this->rtc[2]%10;
        currentTime-=24*60;
    }
    array[index++]=this->rtc[0];
    array[index++]=this->rtc[1];
    array[index++]=this->rtc[2];
    uint16_t temp1 = currentTime-1;
    uint8_t temp2=temp1/60;
    uint8_t temp3=temp1%60;
    array[index++]=temp2/10*16 + temp2%10;

    array[index++]=temp3/10*16 + temp3%10;
    array[index++]=0x59;

    array[index]=arraySum(&array[4],index-4);
    index++;
    array[index++]=0x16;
    return index;
}

bool Widget::isInTimeRang(QDateTime &bTest, QDateTime &rangeStart, QDateTime &rangeStop)
{
    if((bTest.toString("H").toUInt()*60+bTest.toString("m").toUInt())<((rangeStart.toString("H").toUInt()*60+rangeStart.toString("m").toUInt())))
    {
        return false;
    }
    else if((bTest.toString("H").toUInt()*60+bTest.toString("m").toUInt())>=(rangeStop.toString("H").toUInt()*60+rangeStop.toString("m").toUInt()))
    {
        return false;
    }
    return true;
}
/**
 * @brief 打点错误执行函数
 */
void Widget::SetErrorFlag()
{
    switch(ui->tabWidget->currentIndex())
    {
        case 0:
        on_stopButton_clicked();
        displaySubWindow("警告","打点失败");
        break;
        case 2:
        this->Time2_5S->myTimerStop();
        ui->readTimepushButton->setEnabled(true);
        ui->setTimepushButton->setEnabled(true);
        displaySubWindow("警告","指令失败");
        break;
        default:
        break;
    }
    
}

/**
 * @brief 发送设置指令
 */
void Widget::SendEnFlag()
{
    myString mystring;
    uint16_t len=0;
    qDebug()<<"SendEnFlag\n";


    if(curretDay>=totalDay)
    {
        this->stopRun();
        return;
    }

    if(successFlag==true)
    {
        if(this->totalCount%2)
        {
            this->vol+=volIncremental;
        }
        else
        {
            if(isInTimeRang(time,mjStart,mjStop)==false)
            {
                this->currentTime+=this->interval;
                time=time.addSecs(this->interval*60);
            }
            else
            {
                this->currentTime+=5;
                time=time.addSecs(5*60);
            }
        }
        this->totalCount++;
    }
    successFlag = false;
    if(!(this->totalCount%2))
    {
        len=setVol_2014((uint8_t*)mystring.array);
    }
    else
    {
        len=setTime_2014((uint8_t*)mystring.array);
    }
    sendFlag=true;

    Time2_5S->myTimerStart(5000);
    Time1_2S->myTimerStop();

    mystring.HexToString((uint8_t*)mystring.string,(uint8_t*)mystring.array,len);
    QString string2;
    string2.append("发送:");
    string2.append(mystring.string);
    if((this->totalCount%2))
    {
        string2.append("(时间)");
    }
    else
    {
        string2.append("(流量)");
    }

    ui->progressBar->setValue(totalCount);
    string2.append("\n");
    QTextCursor tc = ui->textBrowser->textCursor();
    tc.movePosition(QTextCursor::End);
    tc.insertText(string2);
    string2.clear();

    QString string1;
    string1.append("当前设置流量:");
    string1.append(QString("%1").arg(vol));
    string1.append("\t");
    string1.append("当前设置时间:");
    string1.append(time.addSecs(-1).toString());
    ui->lineEdit->clear();
    ui->lineEdit->setText(string1);

    serialPort->write(mystring.array,len);


}


/**
 * @brief 计算求和校验
 * @param array 需要校验的数据段首地址
 * @param len 数据段长度
 * @return 校验结果
 */
uint8_t Widget::arraySum(uint8_t array[], uint16_t len)
{
    uint8_t sum = 0;
    uint16_t loop_i = 0;
    for(loop_i; loop_i < len; loop_i++)
    {
        sum += array[loop_i];
    }
    return sum;
}


/**
 * @brief 2014数据帧检测函数
 * @param m6310 数据帧首地址
 * @param len 数据帧总长度
 * @return 有效2014数据帧首地址
 */
uint8_t *Widget::M6310_FrameValidCheck(uint8_t *m6310,uint16_t len)
{
    uint16_t bytes, tmp;
    uint16_t flen;
    uint8_t vv;
    for(bytes = 0; bytes < len; bytes++)
    {
        if(bytes + 10 > len)
        {
            return NULL;
        }

        if(m6310[bytes] != 0x68)
        {
            continue;          //先找到0x68
        }
        if(m6310[bytes + 3] != 0x68)
        {
            continue;           //找到第二个0x68
        }

        tmp = ((uint16_t)m6310[bytes + 1] << 8) + m6310[bytes + 2];      //帧长度 从CTRLB开始到DATA止 执行到该步时bytes位为第一个68,bytes + 3为第二个68
        if( bytes + 3 + tmp + 2 >= len )     //若数据长度大于数据包长度，则跳出，往下继续查找
        {
            continue;
        }

        if(m6310[bytes + tmp + 5] != 0x16) //查找结束符0x16
        {
            continue;
        }

        flen = tmp;
        vv = 0;
        vv = arraySum(&m6310[bytes + 4], flen) & 0xff;
        if(vv == m6310[bytes + 4 + tmp]) //校验是否合格
        {
            return &m6310[bytes];  //CTRLB 所在字节数
        }
    }
    return NULL;
}


/**
 * @brief 串口数据接收处理函数
 */
void Widget::ReadRecData()
{
    static uint8_t temp_array[3000];
    static QString string23;
    myString mystring;

    uint8_t *pArray;

    data.append(serialPort->readAll());

    memcpy(mystring.array,data.data(),data.length());


    mystring.HexToString((uint8_t*)mystring.string,(uint8_t*)mystring.array,data.length());


    //mystring.stringToHex(0,data.length());
    pArray=M6310_FrameValidCheck((uint8_t*)mystring.array,data.length());
    if(pArray==NULL)
    {
        return;
    }
    data.clear();
    switch(ui->tabWidget->currentIndex())
    {
        case 0:
    {
                if(pArray[14]==1)
                {
                    successFlag=true;
                }
                else
                {
                    successFlag=false;
                }


                Time2_5S->myTimerStart(5000);

                QString string2;
                string2.append("接收:");
                string2.append(mystring.string);
                if(successFlag)
                {
                    string2.append("(成功)");
                }
                else
                {
                    string2.append("(失败)");
                }
                string2.append("\n");

                QTextCursor tc = ui->textBrowser->textCursor();
                tc.movePosition(QTextCursor::End);
                tc.insertText(string2);
                string2.clear();

                if(!(this->totalCount%2))
                {
                    Time1_2S->myTimerStart(50);
                }
                else
                {
                    Time1_2S->myTimerStart(2000);
                }
                break;
    }

         case 2:
    {

        ui->readTimepushButton->setEnabled(true);
        ui->setTimepushButton->setEnabled(true);
                 Time2_5S->myTimerStop();
                if((pArray[4]==01)&&(pArray[5])==01)
                {
                    if(pArray[14]==01)
                    {
                        displaySubWindow("提示"," 设置成功");
                    }
                    else
                    {
                        displaySubWindow("提示"," 设置失败");
                    }
                }
                if((pArray[4]==01)&&(pArray[5])==00)
                {
                   uint32_t t2=mystring.arraytoU32_Big((uint8_t*)&pArray[17]);
                   ui->readTimelineEdit->setText(QString("%1").arg(t2));
                }
        break;
    }
    default:break;
    }










}



Widget::~Widget()
{
    delete ui;
}


/**
 * @brief 刷新电脑端串口号
 */
void Widget::upSerialCOMData()
{
    for(uint8_t loop_i=0;loop_i<=serialNamePortDisplay.size();loop_i++)
        ui->serialBox->clear();// (serialNamePortDisplay.at(loop_i));
    QStringList list;
    serialNamePortDisplay.clear();
    for(const QSerialPortInfo &inf0:QSerialPortInfo::availablePorts())
    {
        list<<inf0.portName()+"("+inf0.description()+")";
        serialNamePortDisplay<<inf0.portName()+"("+inf0.description()+")";
    }
    ui->serialBox->addItems(list);
}


/**
 * @brief 处理打点成功函数
 */
void Widget::setComplete()
{
    QString string;
    serialPort->close();
    ui->startButton->setEnabled(true);
    string.append("完成\t");
    string.append("已设置次数为:");
    string.append(QString("%1").arg(this->totalCount));
    ui->lineEdit->clear();
    ui->lineEdit->setText(string);
    Time1_2S->myTimerStop();
    Time2_5S->myTimerStop();
    displaySubWindow("通知","打点完成");
}

void Widget::on_stopButton_clicked()
{
    QString string;
    serialPort->close();
    ui->progressBar->setValue(0);//清零进度条
    ui->startButton->setEnabled(true);
    string.append("结束\t");
    string.append("已设置次数为:");
    string.append(QString("%1").arg(this->totalCount));
    ui->lineEdit->clear();
    ui->lineEdit->setText(string);
    Time1_2S->myTimerStop();
    Time2_5S->myTimerStop();
}



void Widget::on_startButton_clicked()
{
    serialPort->close();
    serialPort->setPortName(ui->serialBox->currentText().mid(0,ui->serialBox->currentText().indexOf("(")));
    ui->textBrowser->clear();

    myString mystring1;
    QString tempString = ui->lineEdit_2->text();
    if(tempString.length()!=16)
    {
        displaySubWindow("警告","帧长度不对");
        return;
    }
    mystring1.memcpy_string(tempString.toLocal8Bit().data());
    mystring1.stringToHex(0,tempString.length());
    for(uint8_t loop_i=0;loop_i<8;loop_i++)
    {
        motor_address[loop_i]=mystring1.array[loop_i];
    }


    //设置波特率
    switch (ui->BaudRateBox->currentIndex())
    {
        case 0:
            serialPort->setBaudRate(QSerialPort::Baud1200);break;
        case 1:
            serialPort->setBaudRate(QSerialPort::Baud2400);break;
        case 2:
            serialPort->setBaudRate(QSerialPort::Baud4800);break;
        case 3:
            serialPort->setBaudRate(QSerialPort::Baud9600);break;
        case 4:
            serialPort->setBaudRate(QSerialPort::Baud19200);break;
        case 5:
            serialPort->setBaudRate(QSerialPort::Baud38400);break;
        case 6:
            serialPort->setBaudRate(QSerialPort::Baud57600);break;
        case 7:
            serialPort->setBaudRate(QSerialPort::Baud115200);break;

    }


    //设置数据位
    switch (ui->DataBitsBox->currentIndex())
    {
        case 0:
            serialPort->setDataBits(QSerialPort::Data8);break;
    }



     //设置校验位
    switch (ui->verifyBox->currentIndex())
    {
        case 0:
            serialPort->setParity(QSerialPort::NoParity);break;
        case 1:
            serialPort->setParity(QSerialPort::EvenParity);break;
        case 2:
            serialPort->setParity(QSerialPort::OddParity);break;
        case 3:
            serialPort->setParity(QSerialPort::SpaceParity);break;
        case 4:
            serialPort->setParity(QSerialPort::MarkParity);break;
    }






    //设置停止位
    switch (ui->StopBitsBox->currentIndex())
    {
    case 0:
        serialPort->setStopBits(QSerialPort::OneStop);
    case 1:
        serialPort->setStopBits(QSerialPort::OneAndHalfStop);
    case 2:
        serialPort->setStopBits(QSerialPort::TwoStop);
    }




    if(true != serialPort->open(QIODevice::ReadWrite))
    {
        displaySubWindow("提示", "串口打开失败");
        return;
    }
    myString mystring;
    uint16_t len=setVol_2014((uint8_t*)mystring.array);
    if(M6310_FrameValidCheck((uint8_t*)mystring.array,100)==NULL)
    {
        displaySubWindow("提示", "帧错误");
        return;
    }


    this->totalCount=0;
    this->currentTime=0;
    this->ackFlag=true;
    this->successFlag=false;
    this->errorFlag=false;
    curretDay=0;


    this->vol=ui->spinBox_3->value();
    this->interval = ui->spinBox_2->value();
    totalDay = ui->spinBox->value();
    ui->progressBar->setRange(0,totalDay*20*60*2/interval+totalDay*4*60*2/5);
    ui->progressBar->setValue(0);//清零进度条

    ui->startButton->setEnabled(false);

    time=ui->dateEdit->dateTime();//获取起始时间

    this->rtc[2]=time.date().toString("d").toUInt() & 0xff;//获取天
    this->rtc[1]=time.date().toString("M").toUInt() & 0xff;//获取月
    this->rtc[0]=time.date().toString("yy").toUInt() & 0xff;//获取年

    this->rtc[0]=this->rtc[0]/10*16 + this->rtc[0]%10;
    this->rtc[1]=this->rtc[1]/10*16 + this->rtc[1]%10;
    this->rtc[2]=this->rtc[2]/10*16 + this->rtc[2]%10;


    mjStart = ui->timeEdit->dateTime();
    mjInterval = ui->spinBox_4->value();
    mjStop = ui->timeEdit->dateTime().addSecs(mjInterval*60*60);

    volIncremental = ui->spinBox_5->value();

    qDebug()<<mjStop.toString("H").toUInt();

    ui->lineEdit->clear();
    Time2_5S->myTimerStart(5000);


    serialPort->write(mystring.array,len);
    data.clear();

    mystring.HexToString((uint8_t*)mystring.string,(uint8_t*)mystring.array,len);
    QString string2;
    string2.append("发送:");
    string2.append(mystring.string);
    string2.append("(流量)");
    string2.append("\n");
    QTextCursor tc = ui->textBrowser->textCursor();
    tc.movePosition(QTextCursor::End);
    tc.insertText(string2);
    string2.clear();


}

/**
 * @brief 弹出提示框
 * @param Title 提示框标题
 * @param Content 提示框内容
 */
void Widget::displaySubWindow (QString Title,QString Content)
{
    messagebox.setWindowTitle(Title);
    messagebox.setText(Content);
    messagebox.exec();

}

/**
 * @brief 清空信息框
 */
void Widget::on_pushButton_clicked()
{
    ui->textBrowser->clear();
    ui->lineEdit->clear();
    ui->progressBar->setValue(0);//清零进度条
}






void Widget::on_read_2014_pushButton_clicked()
{
    QString displayString;
    QString path = QCoreApplication::applicationDirPath();
    QFile file(path+"/2014.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {

        qDebug()<<"Can't open the file!"<<endl;
        displaySubWindow(" 警告","文件打开失败");

    }

    while(!file.atEnd())

    {

        QByteArray line = file.readLine();

        QString str(line);

        qDebug()<< str;

        displayString.append(str);

    }

       ui->read_2014_textEdit->clear();

       ui->read_2014_textEdit->setPlainText(displayString);
}




void Widget::on_add_2014_Button_clicked()
{
    QString path = QCoreApplication::applicationDirPath();
    QFile file(path+"/2014.txt");
    file.open(QIODevice::ReadWrite|QIODevice::Text);	//以读且写的方式打开
    QByteArray array=file.readAll();//读取原文件内容（必须先读出来，才不会被新内容## 标题覆盖掉)
    QString str=ui->add_2014_lineEdit->text().toUtf8();	//字符串，名字可变，这里只是举例
    QTextStream out(&file);		//输入流
    out<<"\n"<<str;			//写入内容
    displaySubWindow("提示"," 添加成功");
    file.close();              //关闭文件流

}

void Widget::on_send_2014_pushButton_clicked()
{

}

void Widget::on_setTimepushButton_clicked()
{
    QString s=ui->setTimelineEdit->text();
    uint32_t t1=s.toInt();
    uint8_t array[23];
    if(!serialPort->isOpen())
    {
        displaySubWindow("警告","串口未开");
        return;
    }
    array[0]=0x68;
    array[1]=0x00;
    array[2]=0x11;
    array[3]=0x68;
    array[4]=0x81;
    array[5]=0x01;
    array[6]=motor_address[7];
    array[7]=motor_address[6];
    array[8]=motor_address[5];
    array[9]=motor_address[4];
    array[10]=motor_address[3];
    array[11]=motor_address[2];
    array[12]=motor_address[1];
    array[13]=motor_address[0];
    array[14]=0x20;
    array[15]=0x59;
    array[16]=0x04;
    array[17]=(t1>>24)&0xff;
    array[18]=(t1>>16)&0xff;
    array[19]=(t1>>8)&0xff;
    array[20]=(t1)&0xff;
    array[21]=arraySum(&array[4],21-4);
    array[22]=0x16;

    serialPort->write((char*)array,23);
    
    Time2_5S->myTimerStart(5000);
    ui->setTimepushButton->setEnabled(false);
}

void Widget::on_readTimepushButton_clicked()
{
    uint8_t array[18];
    if(!serialPort->isOpen())
    {
        displaySubWindow("警告","串口未开");
        return;
    }
    array[0]=0x68;
    array[1]=0x00;
    array[2]=0x0C;
    array[3]=0x68;
    array[4]=0x81;
    array[5]=0x00;
    array[6]=motor_address[7];
    array[7]=motor_address[6];
    array[8]=motor_address[5];
    array[9]=motor_address[4];
    array[10]=motor_address[3];
    array[11]=motor_address[2];
    array[12]=motor_address[1];
    array[13]=motor_address[0];
    array[14]=0x20;
    array[15]=0x59;
    array[16]=arraySum(&array[4],16-4);
    array[17]=0x16;
    serialPort->write((char*)array,18);

    Time2_5S->myTimerStart(5000);
    ui->readTimepushButton->setEnabled(false);
}

void Widget::on_serialButton_clicked()
{
     static  bool state = true;
     if(state==true)
     {
         serialPort->close();
         serialPort->setPortName(ui->serialBox->currentText().mid(0,ui->serialBox->currentText().indexOf("(")));

         myString mystring1;
         QString tempString = ui->lineEdit_2->text();
         if(tempString.length()!=16)
         {
             displaySubWindow("警告","帧长度不对");
             return;
         }
         mystring1.memcpy_string(tempString.toLocal8Bit().data());
         mystring1.stringToHex(0,tempString.length());
         for(uint8_t loop_i=0;loop_i<8;loop_i++)
         {
             motor_address[loop_i]=mystring1.array[loop_i];
         }

         //设置波特率
         switch (ui->BaudRateBox->currentIndex())
         {
             case 0:
                 serialPort->setBaudRate(QSerialPort::Baud1200);break;
             case 1:
                 serialPort->setBaudRate(QSerialPort::Baud2400);break;
             case 2:
                 serialPort->setBaudRate(QSerialPort::Baud4800);break;
             case 3:
                 serialPort->setBaudRate(QSerialPort::Baud9600);break;
             case 4:
                 serialPort->setBaudRate(QSerialPort::Baud19200);break;
             case 5:
                 serialPort->setBaudRate(QSerialPort::Baud38400);break;
             case 6:
                 serialPort->setBaudRate(QSerialPort::Baud57600);break;
             case 7:
                 serialPort->setBaudRate(QSerialPort::Baud115200);break;

         }


         //设置数据位
         switch (ui->DataBitsBox->currentIndex())
         {
             case 0:
                 serialPort->setDataBits(QSerialPort::Data8);break;
         }



          //设置校验位
         switch (ui->verifyBox->currentIndex())
         {
             case 0:
                 serialPort->setParity(QSerialPort::NoParity);break;
             case 1:
                 serialPort->setParity(QSerialPort::EvenParity);break;
             case 2:
                 serialPort->setParity(QSerialPort::OddParity);break;
             case 3:
                 serialPort->setParity(QSerialPort::SpaceParity);break;
             case 4:
                 serialPort->setParity(QSerialPort::MarkParity);break;
         }

         //设置停止位
         switch (ui->StopBitsBox->currentIndex())
         {
         case 0:
             serialPort->setStopBits(QSerialPort::OneStop);
         case 1:
             serialPort->setStopBits(QSerialPort::OneAndHalfStop);
         case 2:
             serialPort->setStopBits(QSerialPort::TwoStop);
         }


         if(true != serialPort->open(QIODevice::ReadWrite))
         {
             displaySubWindow("提示", "串口打开失败");
             return;
         }
         ui->serialButton->setText("关闭串口");
         state = false;
     }
     else
     {
        ui->serialButton->setText("打开串口");
        serialPort->close();
        state = true;
     }
}
