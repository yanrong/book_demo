/****************************************************************************
** Meta object code from reading C++ file 'weathertrayicon.hpp'
**
** Created: Fri Apr 11 18:08:34 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "weathertrayicon.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'weathertrayicon.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_WeatherTrayIcon[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x08,
      36,   30,   16,   16, 0x08,
      60,   30,   16,   16, 0x08,
      92,   85,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_WeatherTrayIcon[] = {
    "WeatherTrayIcon\0\0requestXml()\0reply\0"
    "readXml(QNetworkReply*)\0"
    "readIcon(QNetworkReply*)\0action\0"
    "setAirport(QAction*)\0"
};

void WeatherTrayIcon::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        WeatherTrayIcon *_t = static_cast<WeatherTrayIcon *>(_o);
        switch (_id) {
        case 0: _t->requestXml(); break;
        case 1: _t->readXml((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 2: _t->readIcon((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 3: _t->setAirport((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData WeatherTrayIcon::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject WeatherTrayIcon::staticMetaObject = {
    { &QSystemTrayIcon::staticMetaObject, qt_meta_stringdata_WeatherTrayIcon,
      qt_meta_data_WeatherTrayIcon, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &WeatherTrayIcon::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *WeatherTrayIcon::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *WeatherTrayIcon::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WeatherTrayIcon))
        return static_cast<void*>(const_cast< WeatherTrayIcon*>(this));
    return QSystemTrayIcon::qt_metacast(_clname);
}

int WeatherTrayIcon::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSystemTrayIcon::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
