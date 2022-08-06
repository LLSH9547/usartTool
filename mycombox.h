#ifndef MYCOMBOX_H
#define MYCOMBOX_H

#include <QComboBox>

class myCombox : public QComboBox
{
    Q_OBJECT
public:
    explicit myCombox(QWidget *parent = nullptr);
protected:
    void mousePressEvent(QMouseEvent *event);

signals:
    sendComboBoxPress(void);
public slots:
};

#endif // MYCOMBOX_H
