/****************************************************************************
** Meta object code from reading C++ file 'linkfetcher.hpp'
**
** Created: Fri Apr 11 18:08:51 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "linkfetcher.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'linkfetcher.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LinkFetcher[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      37,   28,   12,   12, 0x0a,
      74,   68,   12,   12, 0x0a,
      89,   12,   12,   12, 0x08,
     127,  124,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_LinkFetcher[] = {
    "LinkFetcher\0\0finished(bool)\0url,name\0"
    "addUrlAndName(QString,QString)\0value\0"
    "debug(QString)\0injectJavaScriptIntoWindowObject()\0"
    "ok\0fetchLinks(bool)\0"
};

void LinkFetcher::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LinkFetcher *_t = static_cast<LinkFetcher *>(_o);
        switch (_id) {
        case 0: _t->finished((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->addUrlAndName((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->debug((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->injectJavaScriptIntoWindowObject(); break;
        case 4: _t->fetchLinks((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LinkFetcher::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LinkFetcher::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_LinkFetcher,
      qt_meta_data_LinkFetcher, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LinkFetcher::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LinkFetcher::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LinkFetcher::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LinkFetcher))
        return static_cast<void*>(const_cast< LinkFetcher*>(this));
    return QObject::qt_metacast(_clname);
}

int LinkFetcher::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void LinkFetcher::finished(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
