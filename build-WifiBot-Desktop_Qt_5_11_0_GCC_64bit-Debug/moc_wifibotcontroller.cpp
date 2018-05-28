/****************************************************************************
** Meta object code from reading C++ file 'wifibotcontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../wifibot/wifibotcontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wifibotcontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WifiBotController_t {
    QByteArrayData data[8];
    char stringdata0[96];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WifiBotController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WifiBotController_t qt_meta_stringdata_WifiBotController = {
    {
QT_MOC_LITERAL(0, 0, 17), // "WifiBotController"
QT_MOC_LITERAL(1, 18, 13), // "whenConnected"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 16), // "whenDisconnected"
QT_MOC_LITERAL(4, 50, 16), // "whenBytesWritten"
QT_MOC_LITERAL(5, 67, 5), // "bytes"
QT_MOC_LITERAL(6, 73, 13), // "whenReadyRead"
QT_MOC_LITERAL(7, 87, 8) // "sendData"

    },
    "WifiBotController\0whenConnected\0\0"
    "whenDisconnected\0whenBytesWritten\0"
    "bytes\0whenReadyRead\0sendData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WifiBotController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    1,   41,    2, 0x08 /* Private */,
       6,    0,   44,    2, 0x08 /* Private */,
       7,    0,   45,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WifiBotController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WifiBotController *_t = static_cast<WifiBotController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->whenConnected(); break;
        case 1: _t->whenDisconnected(); break;
        case 2: _t->whenBytesWritten((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 3: _t->whenReadyRead(); break;
        case 4: _t->sendData(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WifiBotController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WifiBotController.data,
      qt_meta_data_WifiBotController,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *WifiBotController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WifiBotController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WifiBotController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int WifiBotController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
