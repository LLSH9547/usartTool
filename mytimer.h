#ifndef MYTIMER_H
#define MYTIMER_H
#include <QTimer>
#include <QDebug>
#include <stdint.h>

class myTimer : public QObject
{
    Q_OBJECT
public:
    myTimer(int ms);
    ~myTimer();
    void myTimerStart(int ms);
    void myTimerStop(void);
public slots:
    void handleTimeout();  //超时处理函数
signals:
    sendTimeOut(void);
private:
    QTimer *m_pTimer;
};

#endif // MYTIMER_H
