/****************************************************************************
** Meta object code from reading C++ file 'pagedata.hpp'
**
** Created: Fri Apr 11 18:10:58 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "pagedata.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pagedata.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PageData[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      36,   10,    9,    9, 0x0a,
      71,   63,    9,    9, 0x2a,

       0        // eod
};

static const char qt_meta_stringdata_PageData[] = {
    "PageData\0\0printer,noUserInteraction\0"
    "paintPages(QPrinter*,bool)\0printer\0"
    "paintPages(QPrinter*)\0"
};

void PageData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PageData *_t = static_cast<PageData *>(_o);
        switch (_id) {
        case 0: _t->paintPages((*reinterpret_cast< QPrinter*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->paintPages((*reinterpret_cast< QPrinter*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PageData::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PageData::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PageData,
      qt_meta_data_PageData, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PageData::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PageData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PageData::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PageData))
        return static_cast<void*>(const_cast< PageData*>(this));
    return QObject::qt_metacast(_clname);
}

int PageData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
