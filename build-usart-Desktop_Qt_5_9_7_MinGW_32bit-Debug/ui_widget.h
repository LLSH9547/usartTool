/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>
#include "mycombox.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QPushButton *serialButton;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QComboBox *BaudRateBox;
    QLabel *label_11;
    QComboBox *DataBitsBox;
    QLabel *label_9;
    QComboBox *verifyBox;
    QLabel *label_10;
    QComboBox *StopBitsBox;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_12;
    QLineEdit *lineEdit_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *pushButton;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QDateEdit *dateEdit;
    QLabel *label_4;
    QSpinBox *spinBox_2;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *spinBox;
    QLabel *label;
    QHBoxLayout *horizontalLayout_4;
    QSpinBox *spinBox_3;
    QLabel *label_3;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_6;
    QTimeEdit *timeEdit;
    QLabel *label_5;
    QSpinBox *spinBox_4;
    QLabel *label_6;
    QSpinBox *spinBox_5;
    QLabel *label_7;
    QSpinBox *spinBox_6;
    QLabel *label_13;
    QLineEdit *lineEdit;
    QTextBrowser *textBrowser;
    QWidget *tab_2;
    QPushButton *query_2014_Button;
    QPushButton *add_2014_Button;
    QLineEdit *query_2014_lineEdit;
    QLineEdit *add_2014_lineEdit;
    QPushButton *send_2014_pushButton;
    QLineEdit *send_2014_lineEdit;
    QListView *listView;
    QPushButton *read_2014_pushButton;
    QLabel *label_14;
    QTextEdit *read_2014_textEdit;
    QWidget *tab_3;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_10;
    QLineEdit *setTimelineEdit;
    QLabel *label_15;
    QPushButton *setTimepushButton;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_11;
    QLineEdit *readTimelineEdit;
    QLabel *label_16;
    QPushButton *readTimepushButton;
    QProgressBar *progressBar;
    myCombox *serialBox;
    QHBoxLayout *horizontalLayout_8;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(725, 655);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        serialButton = new QPushButton(Widget);
        serialButton->setObjectName(QStringLiteral("serialButton"));

        gridLayout->addWidget(serialButton, 0, 1, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_8 = new QLabel(Widget);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_7->addWidget(label_8);

        BaudRateBox = new QComboBox(Widget);
        BaudRateBox->setObjectName(QStringLiteral("BaudRateBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BaudRateBox->sizePolicy().hasHeightForWidth());
        BaudRateBox->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(BaudRateBox);

        label_11 = new QLabel(Widget);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_7->addWidget(label_11);

        DataBitsBox = new QComboBox(Widget);
        DataBitsBox->setObjectName(QStringLiteral("DataBitsBox"));

        horizontalLayout_7->addWidget(DataBitsBox);

        label_9 = new QLabel(Widget);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_7->addWidget(label_9);

        verifyBox = new QComboBox(Widget);
        verifyBox->setObjectName(QStringLiteral("verifyBox"));

        horizontalLayout_7->addWidget(verifyBox);

        label_10 = new QLabel(Widget);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_7->addWidget(label_10);

        StopBitsBox = new QComboBox(Widget);
        StopBitsBox->setObjectName(QStringLiteral("StopBitsBox"));

        horizontalLayout_7->addWidget(StopBitsBox);


        gridLayout->addLayout(horizontalLayout_7, 1, 0, 1, 2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_12 = new QLabel(Widget);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_9->addWidget(label_12);

        lineEdit_2 = new QLineEdit(Widget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout_9->addWidget(lineEdit_2);


        gridLayout->addLayout(horizontalLayout_9, 2, 0, 1, 2);

        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 0, 681, 30));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        startButton = new QPushButton(layoutWidget);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setStyleSheet(QLatin1String("QPushButton#queenMenuButton:pressed{\n"
"background-color: rgba(255, 255, 255, 150);\n"
"border:2px solid white;border-radius:10px;\n"
"padding-left:6px;\n"
"padding-top:6px;\n"
"}"));

        horizontalLayout->addWidget(startButton);

        stopButton = new QPushButton(layoutWidget);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setStyleSheet(QLatin1String("QPushButton#queenMenuButton:pressed{\n"
"background-color: rgba(255, 255, 255, 150);\n"
"border:2px solid white;border-radius:10px;\n"
"padding-left:6px;\n"
"padding-top:6px;\n"
"}"));

        horizontalLayout->addWidget(stopButton);

        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 30, 681, 23));
        layoutWidget1 = new QWidget(tab);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 60, 681, 25));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        dateEdit = new QDateEdit(layoutWidget1);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setDateTime(QDateTime(QDate(2022, 1, 1), QTime(0, 0, 0)));
        dateEdit->setDate(QDate(2022, 1, 1));

        horizontalLayout_3->addWidget(dateEdit);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        spinBox_2 = new QSpinBox(layoutWidget1);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));

        horizontalLayout_3->addWidget(spinBox_2);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);


        horizontalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        spinBox = new QSpinBox(layoutWidget1);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        horizontalLayout_2->addWidget(spinBox);

        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);


        horizontalLayout_5->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        spinBox_3 = new QSpinBox(layoutWidget1);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));

        horizontalLayout_4->addWidget(spinBox_3);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);


        horizontalLayout_5->addLayout(horizontalLayout_4);

        layoutWidget2 = new QWidget(tab);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 90, 695, 23));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        timeEdit = new QTimeEdit(layoutWidget2);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));

        horizontalLayout_6->addWidget(timeEdit);

        label_5 = new QLabel(layoutWidget2);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_6->addWidget(label_5);

        spinBox_4 = new QSpinBox(layoutWidget2);
        spinBox_4->setObjectName(QStringLiteral("spinBox_4"));

        horizontalLayout_6->addWidget(spinBox_4);

        label_6 = new QLabel(layoutWidget2);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_6->addWidget(label_6);

        spinBox_5 = new QSpinBox(layoutWidget2);
        spinBox_5->setObjectName(QStringLiteral("spinBox_5"));

        horizontalLayout_6->addWidget(spinBox_5);

        label_7 = new QLabel(layoutWidget2);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_6->addWidget(label_7);

        spinBox_6 = new QSpinBox(layoutWidget2);
        spinBox_6->setObjectName(QStringLiteral("spinBox_6"));

        horizontalLayout_6->addWidget(spinBox_6);

        label_13 = new QLabel(layoutWidget2);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_6->addWidget(label_13);

        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 150, 681, 20));
        textBrowser = new QTextBrowser(tab);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(10, 180, 681, 341));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        query_2014_Button = new QPushButton(tab_2);
        query_2014_Button->setObjectName(QStringLiteral("query_2014_Button"));
        query_2014_Button->setGeometry(QRect(610, 10, 75, 23));
        add_2014_Button = new QPushButton(tab_2);
        add_2014_Button->setObjectName(QStringLiteral("add_2014_Button"));
        add_2014_Button->setGeometry(QRect(610, 40, 75, 23));
        query_2014_lineEdit = new QLineEdit(tab_2);
        query_2014_lineEdit->setObjectName(QStringLiteral("query_2014_lineEdit"));
        query_2014_lineEdit->setGeometry(QRect(0, 10, 611, 20));
        add_2014_lineEdit = new QLineEdit(tab_2);
        add_2014_lineEdit->setObjectName(QStringLiteral("add_2014_lineEdit"));
        add_2014_lineEdit->setGeometry(QRect(0, 40, 611, 20));
        send_2014_pushButton = new QPushButton(tab_2);
        send_2014_pushButton->setObjectName(QStringLiteral("send_2014_pushButton"));
        send_2014_pushButton->setGeometry(QRect(620, 280, 75, 23));
        send_2014_lineEdit = new QLineEdit(tab_2);
        send_2014_lineEdit->setObjectName(QStringLiteral("send_2014_lineEdit"));
        send_2014_lineEdit->setGeometry(QRect(0, 280, 611, 20));
        listView = new QListView(tab_2);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(0, 320, 641, 192));
        read_2014_pushButton = new QPushButton(tab_2);
        read_2014_pushButton->setObjectName(QStringLiteral("read_2014_pushButton"));
        read_2014_pushButton->setGeometry(QRect(620, 130, 75, 23));
        label_14 = new QLabel(tab_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(10, 300, 81, 16));
        read_2014_textEdit = new QTextEdit(tab_2);
        read_2014_textEdit->setObjectName(QStringLiteral("read_2014_textEdit"));
        read_2014_textEdit->setGeometry(QRect(0, 70, 611, 201));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        layoutWidget3 = new QWidget(tab_3);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(40, 50, 234, 30));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        setTimelineEdit = new QLineEdit(layoutWidget3);
        setTimelineEdit->setObjectName(QStringLiteral("setTimelineEdit"));

        horizontalLayout_10->addWidget(setTimelineEdit);

        label_15 = new QLabel(layoutWidget3);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout_10->addWidget(label_15);

        setTimepushButton = new QPushButton(layoutWidget3);
        setTimepushButton->setObjectName(QStringLiteral("setTimepushButton"));

        horizontalLayout_10->addWidget(setTimepushButton);

        layoutWidget4 = new QWidget(tab_3);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(40, 100, 234, 30));
        horizontalLayout_11 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        readTimelineEdit = new QLineEdit(layoutWidget4);
        readTimelineEdit->setObjectName(QStringLiteral("readTimelineEdit"));

        horizontalLayout_11->addWidget(readTimelineEdit);

        label_16 = new QLabel(layoutWidget4);
        label_16->setObjectName(QStringLiteral("label_16"));

        horizontalLayout_11->addWidget(label_16);

        readTimepushButton = new QPushButton(layoutWidget4);
        readTimepushButton->setObjectName(QStringLiteral("readTimepushButton"));

        horizontalLayout_11->addWidget(readTimepushButton);

        tabWidget->addTab(tab_3, QString());

        gridLayout->addWidget(tabWidget, 3, 0, 1, 2);

        progressBar = new QProgressBar(Widget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);
        progressBar->setTextVisible(false);
        progressBar->setFormat(QStringLiteral(""));

        gridLayout->addWidget(progressBar, 5, 0, 1, 1);

        serialBox = new myCombox(Widget);
        serialBox->setObjectName(QStringLiteral("serialBox"));

        gridLayout->addWidget(serialBox, 0, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));

        gridLayout->addLayout(horizontalLayout_8, 4, 0, 1, 1);


        retranslateUi(Widget);

        BaudRateBox->setCurrentIndex(1);
        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        serialButton->setText(QApplication::translate("Widget", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        label_8->setText(QApplication::translate("Widget", "\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        BaudRateBox->clear();
        BaudRateBox->insertItems(0, QStringList()
         << QApplication::translate("Widget", "1200", Q_NULLPTR)
         << QApplication::translate("Widget", "2400", Q_NULLPTR)
         << QApplication::translate("Widget", "4800", Q_NULLPTR)
         << QApplication::translate("Widget", "9600", Q_NULLPTR)
         << QApplication::translate("Widget", "19200", Q_NULLPTR)
         << QApplication::translate("Widget", "38400", Q_NULLPTR)
         << QApplication::translate("Widget", "57600", Q_NULLPTR)
         << QApplication::translate("Widget", "115200", Q_NULLPTR)
        );
        BaudRateBox->setCurrentText(QApplication::translate("Widget", "2400", Q_NULLPTR));
        label_11->setText(QApplication::translate("Widget", "\346\225\260\346\215\256\344\275\215", Q_NULLPTR));
        DataBitsBox->clear();
        DataBitsBox->insertItems(0, QStringList()
         << QApplication::translate("Widget", "8", Q_NULLPTR)
        );
        DataBitsBox->setCurrentText(QApplication::translate("Widget", "8", Q_NULLPTR));
        label_9->setText(QApplication::translate("Widget", "\346\240\241\351\252\214\344\275\215", Q_NULLPTR));
        verifyBox->clear();
        verifyBox->insertItems(0, QStringList()
         << QApplication::translate("Widget", "No", Q_NULLPTR)
         << QApplication::translate("Widget", "Even", Q_NULLPTR)
         << QApplication::translate("Widget", "Odd", Q_NULLPTR)
         << QApplication::translate("Widget", "Space", Q_NULLPTR)
         << QApplication::translate("Widget", "Mark", Q_NULLPTR)
        );
        verifyBox->setCurrentText(QApplication::translate("Widget", "No", Q_NULLPTR));
        label_10->setText(QApplication::translate("Widget", "\345\201\234\346\255\242\344\275\215", Q_NULLPTR));
        StopBitsBox->clear();
        StopBitsBox->insertItems(0, QStringList()
         << QApplication::translate("Widget", "1", Q_NULLPTR)
         << QApplication::translate("Widget", "1.5", Q_NULLPTR)
         << QApplication::translate("Widget", "2", Q_NULLPTR)
        );
        StopBitsBox->setCurrentText(QApplication::translate("Widget", "1", Q_NULLPTR));
        label_12->setText(QApplication::translate("Widget", "\350\241\250\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        startButton->setText(QApplication::translate("Widget", "\345\274\200\345\247\213", Q_NULLPTR));
        stopButton->setText(QApplication::translate("Widget", "\347\273\223\346\235\237", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Widget", "\346\270\205\347\251\272", Q_NULLPTR));
        label_4->setText(QApplication::translate("Widget", "\350\265\267\345\247\213\346\227\245\345\255\220", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "\351\227\264\351\232\224\346\227\266\351\227\264(min)", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "\345\244\251\346\225\260", Q_NULLPTR));
        label_3->setText(QApplication::translate("Widget", "\345\210\235\345\247\213\346\265\201\351\207\217", Q_NULLPTR));
        label_5->setText(QApplication::translate("Widget", "\345\257\206\351\233\206\350\265\267\345\247\213\346\227\266\351\227\264", Q_NULLPTR));
        label_6->setText(QApplication::translate("Widget", "\345\257\206\351\233\206\346\227\266\351\225\277(\345\260\217\346\227\266)", Q_NULLPTR));
        label_7->setText(QApplication::translate("Widget", "\346\265\201\351\207\217\345\242\236\351\207\217", Q_NULLPTR));
        label_13->setText(QApplication::translate("Widget", "\345\257\206\351\233\206\351\207\207\346\240\267\351\227\264\351\232\224\346\227\266\351\227\264\357\274\210\345\210\206\351\222\237\357\274\211", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Widget", "\346\265\201\351\207\217\346\211\223\347\202\271", Q_NULLPTR));
        query_2014_Button->setText(QApplication::translate("Widget", "\346\237\245\350\257\242\346\214\207\344\273\244", Q_NULLPTR));
        add_2014_Button->setText(QApplication::translate("Widget", "\346\267\273\345\212\240\346\214\207\344\273\244", Q_NULLPTR));
        send_2014_pushButton->setText(QApplication::translate("Widget", "\345\217\221\351\200\201\346\214\207\344\273\244", Q_NULLPTR));
        read_2014_pushButton->setText(QApplication::translate("Widget", "\350\257\273\345\217\226\346\214\207\344\273\244", Q_NULLPTR));
        label_14->setText(QApplication::translate("Widget", "\346\214\207\344\273\244\350\247\243\346\236\220", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Widget", "2014\345\215\217\350\256\256", Q_NULLPTR));
        label_15->setText(QApplication::translate("Widget", "ms", Q_NULLPTR));
        setTimepushButton->setText(QApplication::translate("Widget", "\350\256\276\347\275\256\346\227\266\351\227\264", Q_NULLPTR));
        label_16->setText(QApplication::translate("Widget", "ms", Q_NULLPTR));
        readTimepushButton->setText(QApplication::translate("Widget", "\350\257\273\345\217\226\346\227\266\351\227\264", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Widget", " \350\223\235\347\211\231\345\271\277\346\222\255\351\227\264\351\232\224", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
