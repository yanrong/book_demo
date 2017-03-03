/****************************************************************************
** Meta object code from reading C++ file 'smileyitem.hpp'
**
** Created: Fri Apr 11 18:12:21 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../pagedesigner1/smileyitem.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'smileyitem.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SmileyItem[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       6,   64, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      24,   20,   11,   11, 0x0a,
      43,   37,   11,   11, 0x0a,
      66,   60,   11,   11, 0x0a,
      99,   83,   11,   11, 0x0a,
     140,  126,   11,   11, 0x0a,
     195,  165,   11,   11, 0x0a,
     224,  219,   11,   11, 0x0a,
     241,  238,   11,   11, 0x0a,
     258,   11,   11,   11, 0x0a,

 // properties: name, type, flags
     273,  265, 0x1a095103,
      37,  277, 0x42095103,
      20,  284, 0x4d095103,
      60,  289, 0x06095103,
      83,  289, 0x06095103,
     126,  289, 0x06095103,

       0        // eod
};

static const char qt_meta_stringdata_SmileyItem[] = {
    "SmileyItem\0\0dirty()\0pen\0setPen(QPen)\0"
    "brush\0setBrush(QBrush)\0angle\0"
    "setAngle(double)\0shearHorizontal\0"
    "setShearHorizontal(double)\0shearVertical\0"
    "setShearVertical(double)\0"
    "shearHorizontal,shearVertical\0"
    "setShear(double,double)\0face\0setFace(Face)\0"
    "on\0setShowHat(bool)\0edit()\0QPointF\0"
    "pos\0QBrush\0QPen\0double\0"
};

void SmileyItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SmileyItem *_t = static_cast<SmileyItem *>(_o);
        switch (_id) {
        case 0: _t->dirty(); break;
        case 1: _t->setPen((*reinterpret_cast< const QPen(*)>(_a[1]))); break;
        case 2: _t->setBrush((*reinterpret_cast< const QBrush(*)>(_a[1]))); break;
        case 3: _t->setAngle((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->setShearHorizontal((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->setShearVertical((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->setShear((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 7: _t->setFace((*reinterpret_cast< Face(*)>(_a[1]))); break;
        case 8: _t->setShowHat((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->edit(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SmileyItem::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SmileyItem::staticMetaObject = {
    { &QGraphicsObject::staticMetaObject, qt_meta_stringdata_SmileyItem,
      qt_meta_data_SmileyItem, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SmileyItem::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SmileyItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SmileyItem::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SmileyItem))
        return static_cast<void*>(const_cast< SmileyItem*>(this));
    return QGraphicsObject::qt_metacast(_clname);
}

int SmileyItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QPointF*>(_v) = pos(); break;
        case 1: *reinterpret_cast< QBrush*>(_v) = brush(); break;
        case 2: *reinterpret_cast< QPen*>(_v) = pen(); break;
        case 3: *reinterpret_cast< double*>(_v) = angle(); break;
        case 4: *reinterpret_cast< double*>(_v) = shearHorizontal(); break;
        case 5: *reinterpret_cast< double*>(_v) = shearVertical(); break;
        }
        _id -= 6;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setPos(*reinterpret_cast< QPointF*>(_v)); break;
        case 1: setBrush(*reinterpret_cast< QBrush*>(_v)); break;
        case 2: setPen(*reinterpret_cast< QPen*>(_v)); break;
        case 3: setAngle(*reinterpret_cast< double*>(_v)); break;
        case 4: setShearHorizontal(*reinterpret_cast< double*>(_v)); break;
        case 5: setShearVertical(*reinterpret_cast< double*>(_v)); break;
        }
        _id -= 6;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void SmileyItem::dirty()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
