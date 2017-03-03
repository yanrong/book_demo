/****************************************************************************
** Meta object code from reading C++ file 'textitem.hpp'
**
** Created: Fri Apr 11 18:12:22 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../pagedesigner1/textitem.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'textitem.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TextItem[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       4,   44, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      24,   18,    9,    9, 0x0a,
      57,   41,    9,    9, 0x0a,
      98,   84,    9,    9, 0x0a,
     153,  123,    9,    9, 0x0a,
     177,    9,    9,    9, 0x0a,

 // properties: name, type, flags
     192,  184, 0x1a095103,
      18,  196, 0x06095103,
      41,  196, 0x06095103,
      84,  196, 0x06095103,

       0        // eod
};

static const char qt_meta_stringdata_TextItem[] = {
    "TextItem\0\0dirty()\0angle\0setAngle(double)\0"
    "shearHorizontal\0setShearHorizontal(double)\0"
    "shearVertical\0setShearVertical(double)\0"
    "shearHorizontal,shearVertical\0"
    "setShear(double,double)\0edit()\0QPointF\0"
    "pos\0double\0"
};

void TextItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TextItem *_t = static_cast<TextItem *>(_o);
        switch (_id) {
        case 0: _t->dirty(); break;
        case 1: _t->setAngle((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->setShearHorizontal((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->setShearVertical((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->setShear((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 5: _t->edit(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TextItem::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TextItem::staticMetaObject = {
    { &QGraphicsTextItem::staticMetaObject, qt_meta_stringdata_TextItem,
      qt_meta_data_TextItem, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TextItem::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TextItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TextItem::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TextItem))
        return static_cast<void*>(const_cast< TextItem*>(this));
    return QGraphicsTextItem::qt_metacast(_clname);
}

int TextItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsTextItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QPointF*>(_v) = pos(); break;
        case 1: *reinterpret_cast< double*>(_v) = angle(); break;
        case 2: *reinterpret_cast< double*>(_v) = shearHorizontal(); break;
        case 3: *reinterpret_cast< double*>(_v) = shearVertical(); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setPos(*reinterpret_cast< QPointF*>(_v)); break;
        case 1: setAngle(*reinterpret_cast< double*>(_v)); break;
        case 2: setShearHorizontal(*reinterpret_cast< double*>(_v)); break;
        case 3: setShearVertical(*reinterpret_cast< double*>(_v)); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void TextItem::dirty()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
