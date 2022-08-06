#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSerialPort>
#include "mytimer.h"
#include <stdint.h>
#include <QMessageBox>
#include <QDateTime>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    void upSerialCOMData();
    ~Widget();
    void ReadRecData(void);

    uint8_t *M6310_FrameValidCheck(uint8_t *m6310,uint16_t len);
    uint8_t arraySum(uint8_t array[], uint16_t len);
    uint16_t setTime_2014(uint8_t array[]);
    uint16_t setVol_2014_0101(uint8_t array[]);
    uint16_t setVol_2014_1110(uint8_t array[]);
    void displaySubWindow (QString Title,QString Content);
    bool isInTimeRang(QDateTime &bTest,QDateTime &rangeStart,QDateTime &rangeStop);
private slots:
    void SetErrorFlag(void);
    void SendEnFlag(void);
    void setComplete(void);
    void on_stopButton_clicked();

    void on_startButton_clicked();

    void on_pushButton_clicked();

    void on_serialButton_clicked();


signals:
    stopRun();

private:
    Ui::Widget *ui;
    QSerialPort *serialPort;
    QString buffer;
    QStringList serialNamePortDisplay;
    myTimer *Time1_2S;
    myTimer *Time2_5S;
    uint8_t state;
    bool errorFlag;
    bool sendFlag;
    bool successFlag;
    bool ackFlag;
    uint16_t totalCount;
    uint32_t vol;
    uint16_t rtc[3];
    uint16_t totalDay;
    uint16_t curretDay;
    uint16_t interval;
    uint16_t currentTime;
    QMessageBox messagebox;
    QByteArray data;
    QDateTime time;
    QDateTime mjStart;
    QDateTime mjStop;
    uint16_t mjInterval;
    uint16_t volIncremental;
    uint8_t motor_address[8];

};

#endif // WIDGET_H
