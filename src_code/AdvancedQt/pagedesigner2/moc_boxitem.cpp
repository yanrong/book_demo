/****************************************************************************
** Meta object code from reading C++ file 'boxitem.hpp'
**
** Created: Fri Apr 11 18:12:21 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../pagedesigner1/boxitem.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'boxitem.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BoxItem[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       6,   49, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      21,   17,    8,    8, 0x0a,
      40,   34,    8,    8, 0x0a,
      63,   57,    8,    8, 0x0a,
      96,   80,    8,    8, 0x0a,
     137,  123,    8,    8, 0x0a,
     192,  162,    8,    8, 0x0a,

 // properties: name, type, flags
     224,  216, 0x1a095103,
      34,  228, 0x42095103,
      17,  235, 0x4d095103,
      57,  240, 0x06095103,
      80,  240, 0x06095103,
     123,  240, 0x06095103,

       0        // eod
};

static const char qt_meta_stringdata_BoxItem[] = {
    "BoxItem\0\0dirty()\0pen\0setPen(QPen)\0"
    "brush\0setBrush(QBrush)\0angle\0"
    "setAngle(double)\0shearHorizontal\0"
    "setShearHorizontal(double)\0shearVertical\0"
    "setShearVertical(double)\0"
    "shearHorizontal,shearVertical\0"
    "setShear(double,double)\0QPointF\0pos\0"
    "QBrush\0QPen\0double\0"
};

void BoxItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BoxItem *_t = static_cast<BoxItem *>(_o);
        switch (_id) {
        case 0: _t->dirty(); break;
        case 1: _t->setPen((*reinterpret_cast< const QPen(*)>(_a[1]))); break;
        case 2: _t->setBrush((*reinterpret_cast< const QBrush(*)>(_a[1]))); break;
        case 3: _t->setAngle((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->setShearHorizontal((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->setShearVertical((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->setShear((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData BoxItem::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BoxItem::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BoxItem,
      qt_meta_data_BoxItem, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BoxItem::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BoxItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BoxItem::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BoxItem))
        return static_cast<void*>(const_cast< BoxItem*>(this));
    if (!strcmp(_clname, "QGraphicsRectItem"))
        return static_cast< QGraphicsRectItem*>(const_cast< BoxItem*>(this));
    return QObject::qt_metacast(_clname);
}

int BoxItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
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
void BoxItem::dirty()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
