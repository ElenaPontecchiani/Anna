/****************************************************************************
** Meta object code from reading C++ file 'matrice_input.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Anna/matrice_input.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'matrice_input.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Matrice_Input_t {
    QByteArrayData data[13];
    char stringdata0[94];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Matrice_Input_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Matrice_Input_t qt_meta_stringdata_Matrice_Input = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Matrice_Input"
QT_MOC_LITERAL(1, 14, 5), // "upMat"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 5), // "modEl"
QT_MOC_LITERAL(4, 27, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(5, 45, 4), // "item"
QT_MOC_LITERAL(6, 50, 6), // "newMat"
QT_MOC_LITERAL(7, 57, 1), // "r"
QT_MOC_LITERAL(8, 59, 1), // "c"
QT_MOC_LITERAL(9, 61, 9), // "changeCol"
QT_MOC_LITERAL(10, 71, 2), // "qs"
QT_MOC_LITERAL(11, 74, 9), // "changeRow"
QT_MOC_LITERAL(12, 84, 9) // "trasposta"

    },
    "Matrice_Input\0upMat\0\0modEl\0QTableWidgetItem*\0"
    "item\0newMat\0r\0c\0changeCol\0qs\0changeRow\0"
    "trasposta"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Matrice_Input[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    1,   45,    2, 0x0a /* Public */,
       6,    2,   48,    2, 0x0a /* Public */,
       9,    1,   53,    2, 0x0a /* Public */,
      11,    1,   56,    2, 0x0a /* Public */,
      12,    0,   59,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,

       0        // eod
};

void Matrice_Input::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Matrice_Input *_t = static_cast<Matrice_Input *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->upMat(); break;
        case 1: _t->modEl((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->newMat((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->changeCol((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->changeRow((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->trasposta(); break;
        default: ;
        }
    }
}

const QMetaObject Matrice_Input::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Matrice_Input.data,
      qt_meta_data_Matrice_Input,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Matrice_Input::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Matrice_Input::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Matrice_Input.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Matrice_Input::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
