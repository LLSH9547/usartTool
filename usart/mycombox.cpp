#include "mycombox.h"
#include <QMouseEvent>

myCombox::myCombox(QWidget *parent) : QComboBox(parent)
{

}

void myCombox::mousePressEvent(QMouseEvent *event)
{
    emit sendComboBoxPress();
    QComboBox::mousePressEvent(event);
}

