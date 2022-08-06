#include "mytimer.h"


myTimer::myTimer(int ms)
{
    m_pTimer = new QTimer(this);
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(handleTimeout()));
    m_pTimer->start(ms);
}

myTimer::~myTimer()
{

}

void myTimer::myTimerStart(int ms)
{
    m_pTimer->start(ms);
}

void myTimer::myTimerStop()
{
    m_pTimer->stop();
}

void myTimer::handleTimeout()
{
   // static uint32_t loop_i=0;
    sendTimeOut();
//    qDebug()<<"Enter timeout processing function\n"<<loop_i;
//    loop_i++;
}











