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
    QByteArrayData data[23];
    char stringdata0[168];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Matrice_Input_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Matrice_Input_t qt_meta_stringdata_Matrice_Input = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Matrice_Input"
QT_MOC_LITERAL(1, 14, 7), // "plusRow"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 10), // "plusColumn"
QT_MOC_LITERAL(4, 34, 8), // "minusRow"
QT_MOC_LITERAL(5, 43, 11), // "minusColumn"
QT_MOC_LITERAL(6, 55, 5), // "upMat"
QT_MOC_LITERAL(7, 61, 5), // "modEl"
QT_MOC_LITERAL(8, 67, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(9, 85, 4), // "item"
QT_MOC_LITERAL(10, 90, 6), // "newMat"
QT_MOC_LITERAL(11, 97, 1), // "r"
QT_MOC_LITERAL(12, 99, 1), // "c"
QT_MOC_LITERAL(13, 101, 9), // "changeCol"
QT_MOC_LITERAL(14, 111, 2), // "qs"
QT_MOC_LITERAL(15, 114, 9), // "changeRow"
QT_MOC_LITERAL(16, 124, 9), // "trasposta"
QT_MOC_LITERAL(17, 134, 5), // "gauss"
QT_MOC_LITERAL(18, 140, 11), // "gaussJordan"
QT_MOC_LITERAL(19, 152, 4), // "radX"
QT_MOC_LITERAL(20, 157, 1), // "d"
QT_MOC_LITERAL(21, 159, 4), // "powX"
QT_MOC_LITERAL(22, 164, 3) // "inv"

    },
    "Matrice_Input\0plusRow\0\0plusColumn\0"
    "minusRow\0minusColumn\0upMat\0modEl\0"
    "QTableWidgetItem*\0item\0newMat\0r\0c\0"
    "changeCol\0qs\0changeRow\0trasposta\0gauss\0"
    "gaussJordan\0radX\0d\0powX\0inv"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Matrice_Input[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x0a /* Public */,
       3,    0,   90,    2, 0x0a /* Public */,
       4,    0,   91,    2, 0x0a /* Public */,
       5,    0,   92,    2, 0x0a /* Public */,
       6,    0,   93,    2, 0x0a /* Public */,
       7,    1,   94,    2, 0x0a /* Public */,
      10,    2,   97,    2, 0x0a /* Public */,
      13,    1,  102,    2, 0x0a /* Public */,
      15,    1,  105,    2, 0x0a /* Public */,
      16,    0,  108,    2, 0x0a /* Public */,
      17,    0,  109,    2, 0x0a /* Public */,
      18,    0,  110,    2, 0x0a /* Public */,
      19,    1,  111,    2, 0x0a /* Public */,
      21,    1,  114,    2, 0x0a /* Public */,
      22,    0,  117,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   12,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   20,
    QMetaType::Void, QMetaType::Double,   20,
    QMetaType::Void,

       0        // eod
};

void Matrice_Input::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Matrice_Input *_t = static_cast<Matrice_Input *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->plusRow(); break;
        case 1: _t->plusColumn(); break;
        case 2: _t->minusRow(); break;
        case 3: _t->minusColumn(); break;
        case 4: _t->upMat(); break;
        case 5: _t->modEl((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 6: _t->newMat((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->changeCol((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->changeRow((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->trasposta(); break;
        case 10: _t->gauss(); break;
        case 11: _t->gaussJordan(); break;
        case 12: _t->radX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: _t->powX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: _t->inv(); break;
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
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
