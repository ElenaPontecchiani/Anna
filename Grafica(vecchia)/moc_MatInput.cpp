/****************************************************************************
** Meta object code from reading C++ file 'MatInput.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MatInput.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MatInput.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MatInput[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      23,   19,    9,    9, 0x0a,
      50,   42,    9,    9, 0x0a,
      82,    9,    9,    9, 0x0a,
      89,    9,    9,    9, 0x0a,
      97,    9,    9,    9, 0x0a,
     111,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MatInput[] = {
    "MatInput\0\0Update()\0r,c\0newMatrix(int,int)\0"
    "str,r,c\0setMatrixValue(QString,int,int)\0"
    "sqrt()\0Gauss()\0GaussJordan()\0Trasposta()\0"
};

void MatInput::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MatInput *_t = static_cast<MatInput *>(_o);
        switch (_id) {
        case 0: _t->Update(); break;
        case 1: _t->newMatrix((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->setMatrixValue((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->sqrt(); break;
        case 4: _t->Gauss(); break;
        case 5: _t->GaussJordan(); break;
        case 6: _t->Trasposta(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MatInput::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MatInput::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MatInput,
      qt_meta_data_MatInput, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MatInput::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MatInput::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MatInput::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MatInput))
        return static_cast<void*>(const_cast< MatInput*>(this));
    return QWidget::qt_metacast(_clname);
}

int MatInput::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void MatInput::Update()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
static const uint qt_meta_data_InputBox[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   10,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      57,   53,    9,    9, 0x0a,
      79,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_InputBox[] = {
    "InputBox\0\0str,rr,cc\0"
    "valueChangedSig(QString,int,int)\0str\0"
    "valueChanged(QString)\0Update()\0"
};

void InputBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        InputBox *_t = static_cast<InputBox *>(_o);
        switch (_id) {
        case 0: _t->valueChangedSig((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->valueChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->Update(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData InputBox::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject InputBox::staticMetaObject = {
    { &QLineEdit::staticMetaObject, qt_meta_stringdata_InputBox,
      qt_meta_data_InputBox, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &InputBox::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *InputBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *InputBox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_InputBox))
        return static_cast<void*>(const_cast< InputBox*>(this));
    return QLineEdit::qt_metacast(_clname);
}

int InputBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLineEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void InputBox::valueChangedSig(const QString & _t1, int _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
