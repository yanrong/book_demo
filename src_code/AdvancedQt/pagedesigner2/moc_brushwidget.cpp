/****************************************************************************
** Meta object code from reading C++ file 'brushwidget.hpp'
**
** Created: Fri Apr 11 18:12:25 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../pagedesigner1/brushwidget.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'brushwidget.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BrushWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   13,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      40,   13,   12,   12, 0x0a,
      63,   57,   12,   12, 0x08,
      80,   57,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_BrushWidget[] = {
    "BrushWidget\0\0brush\0brushChanged(QBrush)\0"
    "setBrush(QBrush)\0index\0updateColor(int)\0"
    "updateStyle(int)\0"
};

void BrushWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BrushWidget *_t = static_cast<BrushWidget *>(_o);
        switch (_id) {
        case 0: _t->brushChanged((*reinterpret_cast< const QBrush(*)>(_a[1]))); break;
        case 1: _t->setBrush((*reinterpret_cast< const QBrush(*)>(_a[1]))); break;
        case 2: _t->updateColor((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->updateStyle((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData BrushWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BrushWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BrushWidget,
      qt_meta_data_BrushWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BrushWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BrushWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BrushWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BrushWidget))
        return static_cast<void*>(const_cast< BrushWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int BrushWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void BrushWidget::brushChanged(const QBrush & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
