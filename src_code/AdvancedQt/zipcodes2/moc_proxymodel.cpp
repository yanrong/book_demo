/****************************************************************************
** Meta object code from reading C++ file 'proxymodel.hpp'
**
** Created: Fri Apr 11 18:09:32 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../zipcodes1/proxymodel.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'proxymodel.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ProxyModel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      42,   27,   11,   11, 0x0a,
      80,   65,   11,   11, 0x0a,
     110,  103,   11,   11, 0x0a,
     135,  129,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ProxyModel[] = {
    "ProxyModel\0\0clearFilters()\0minimumZipcode\0"
    "setMinimumZipcode(int)\0maximumZipcode\0"
    "setMaximumZipcode(int)\0county\0"
    "setCounty(QString)\0state\0setState(QString)\0"
};

void ProxyModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ProxyModel *_t = static_cast<ProxyModel *>(_o);
        switch (_id) {
        case 0: _t->clearFilters(); break;
        case 1: _t->setMinimumZipcode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setMaximumZipcode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setCounty((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->setState((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ProxyModel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ProxyModel::staticMetaObject = {
    { &QSortFilterProxyModel::staticMetaObject, qt_meta_stringdata_ProxyModel,
      qt_meta_data_ProxyModel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ProxyModel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ProxyModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ProxyModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ProxyModel))
        return static_cast<void*>(const_cast< ProxyModel*>(this));
    return QSortFilterProxyModel::qt_metacast(_clname);
}

int ProxyModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSortFilterProxyModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
