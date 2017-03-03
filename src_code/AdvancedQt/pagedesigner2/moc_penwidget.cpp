/****************************************************************************
** Meta object code from reading C++ file 'penwidget.hpp'
**
** Created: Fri Apr 11 18:12:25 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../pagedesigner1/penwidget.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'penwidget.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PenWidget[] = {

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
      15,   11,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      32,   11,   10,   10, 0x0a,
      51,   45,   10,   10, 0x08,
      74,   68,   10,   10, 0x08,
      91,   45,   10,   10, 0x08,
     112,   45,   10,   10, 0x08,
     132,   45,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PenWidget[] = {
    "PenWidget\0\0pen\0penChanged(QPen)\0"
    "setPen(QPen)\0index\0updateColor(int)\0"
    "value\0updateWidth(int)\0updateLineStyle(int)\0"
    "updateCapStyle(int)\0updateJoinStyle(int)\0"
};

void PenWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PenWidget *_t = static_cast<PenWidget *>(_o);
        switch (_id) {
        case 0: _t->penChanged((*reinterpret_cast< const QPen(*)>(_a[1]))); break;
        case 1: _t->setPen((*reinterpret_cast< const QPen(*)>(_a[1]))); break;
        case 2: _t->updateColor((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->updateWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->updateLineStyle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->updateCapStyle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->updateJoinStyle((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PenWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PenWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PenWidget,
      qt_meta_data_PenWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PenWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PenWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PenWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PenWidget))
        return static_cast<void*>(const_cast< PenWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int PenWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void PenWidget::penChanged(const QPen & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
