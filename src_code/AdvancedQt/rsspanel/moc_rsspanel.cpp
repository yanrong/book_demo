/****************************************************************************
** Meta object code from reading C++ file 'rsspanel.hpp'
**
** Created: Fri Apr 11 18:08:40 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "rsspanel.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rsspanel.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RssPanel[] = {

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
      14,   10,    9,    9, 0x0a,
      35,   27,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_RssPanel[] = {
    "RssPanel\0\0url\0setUrl(QUrl)\0minutes\0"
    "setIntervalMinutes(int)\0"
};

void RssPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RssPanel *_t = static_cast<RssPanel *>(_o);
        switch (_id) {
        case 0: _t->setUrl((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 1: _t->setIntervalMinutes((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData RssPanel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RssPanel::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_RssPanel,
      qt_meta_data_RssPanel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RssPanel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RssPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RssPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RssPanel))
        return static_cast<void*>(const_cast< RssPanel*>(this));
    return QWidget::qt_metacast(_clname);
}

int RssPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
