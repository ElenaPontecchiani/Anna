/****************************************************************************
** Meta object code from reading C++ file 'tastiera.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "tastiera.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tastiera.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Tastiera_t {
    QByteArrayData data[11];
    char stringdata0[71];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Tastiera_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Tastiera_t qt_meta_stringdata_Tastiera = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Tastiera"
QT_MOC_LITERAL(1, 9, 9), // "trasposta"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 5), // "gauss"
QT_MOC_LITERAL(4, 26, 6), // "gaussj"
QT_MOC_LITERAL(5, 33, 4), // "radX"
QT_MOC_LITERAL(6, 38, 5), // "coeff"
QT_MOC_LITERAL(7, 44, 4), // "powX"
QT_MOC_LITERAL(8, 49, 5), // "plusX"
QT_MOC_LITERAL(9, 55, 7), // "sendRad"
QT_MOC_LITERAL(10, 63, 7) // "sendPow"

    },
    "Tastiera\0trasposta\0\0gauss\0gaussj\0radX\0"
    "coeff\0powX\0plusX\0sendRad\0sendPow"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tastiera[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    0,   56,    2, 0x06 /* Public */,
       5,    1,   57,    2, 0x06 /* Public */,
       7,    1,   60,    2, 0x06 /* Public */,
       8,    1,   63,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   66,    2, 0x0a /* Public */,
      10,    0,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Tastiera::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Tastiera *_t = static_cast<Tastiera *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->trasposta(); break;
        case 1: _t->gauss(); break;
        case 2: _t->gaussj(); break;
        case 3: _t->radX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->powX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->plusX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->sendRad(); break;
        case 7: _t->sendPow(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Tastiera::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Tastiera::trasposta)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Tastiera::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Tastiera::gauss)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Tastiera::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Tastiera::gaussj)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Tastiera::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Tastiera::radX)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Tastiera::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Tastiera::powX)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Tastiera::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Tastiera::plusX)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject Tastiera::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Tastiera.data,
      qt_meta_data_Tastiera,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Tastiera::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tastiera::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Tastiera.stringdata0))
        return static_cast<void*>(const_cast< Tastiera*>(this));
    return QWidget::qt_metacast(_clname);
}

int Tastiera::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Tastiera::trasposta()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Tastiera::gauss()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Tastiera::gaussj()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Tastiera::radX(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Tastiera::powX(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Tastiera::plusX(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
