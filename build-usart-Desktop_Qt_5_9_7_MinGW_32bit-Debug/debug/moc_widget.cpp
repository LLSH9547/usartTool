/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../usart/widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[15];
    char stringdata0[293];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 7), // "stopRun"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 12), // "SetErrorFlag"
QT_MOC_LITERAL(4, 29, 10), // "SendEnFlag"
QT_MOC_LITERAL(5, 40, 11), // "setComplete"
QT_MOC_LITERAL(6, 52, 21), // "on_stopButton_clicked"
QT_MOC_LITERAL(7, 74, 22), // "on_startButton_clicked"
QT_MOC_LITERAL(8, 97, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(9, 119, 31), // "on_read_2014_pushButton_clicked"
QT_MOC_LITERAL(10, 151, 26), // "on_add_2014_Button_clicked"
QT_MOC_LITERAL(11, 178, 31), // "on_send_2014_pushButton_clicked"
QT_MOC_LITERAL(12, 210, 28), // "on_setTimepushButton_clicked"
QT_MOC_LITERAL(13, 239, 29), // "on_readTimepushButton_clicked"
QT_MOC_LITERAL(14, 269, 23) // "on_serialButton_clicked"

    },
    "Widget\0stopRun\0\0SetErrorFlag\0SendEnFlag\0"
    "setComplete\0on_stopButton_clicked\0"
    "on_startButton_clicked\0on_pushButton_clicked\0"
    "on_read_2014_pushButton_clicked\0"
    "on_add_2014_Button_clicked\0"
    "on_send_2014_pushButton_clicked\0"
    "on_setTimepushButton_clicked\0"
    "on_readTimepushButton_clicked\0"
    "on_serialButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    0,   84,    2, 0x08 /* Private */,
       8,    0,   85,    2, 0x08 /* Private */,
       9,    0,   86,    2, 0x08 /* Private */,
      10,    0,   87,    2, 0x08 /* Private */,
      11,    0,   88,    2, 0x08 /* Private */,
      12,    0,   89,    2, 0x08 /* Private */,
      13,    0,   90,    2, 0x08 /* Private */,
      14,    0,   91,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Int,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Widget *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->stopRun();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->SetErrorFlag(); break;
        case 2: _t->SendEnFlag(); break;
        case 3: _t->setComplete(); break;
        case 4: _t->on_stopButton_clicked(); break;
        case 5: _t->on_startButton_clicked(); break;
        case 6: _t->on_pushButton_clicked(); break;
        case 7: _t->on_read_2014_pushButton_clicked(); break;
        case 8: _t->on_add_2014_Button_clicked(); break;
        case 9: _t->on_send_2014_pushButton_clicked(); break;
        case 10: _t->on_setTimepushButton_clicked(); break;
        case 11: _t->on_readTimepushButton_clicked(); break;
        case 12: _t->on_serialButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef int (Widget::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Widget::stopRun)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget.data,
      qt_meta_data_Widget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
int Widget::stopRun()
{
    int _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
