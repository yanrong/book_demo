/****************************************************************************
** Meta object code from reading C++ file 'rsscombobox.hpp'
**
** Created: Fri Apr 11 18:08:40 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "rsscombobox.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rsscombobox.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RssComboBox[] = {

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
      18,   13,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      46,   12,   12,   12, 0x0a,
      60,   56,   12,   12, 0x0a,
      81,   73,   12,   12, 0x0a,
     105,   12,   12,   12, 0x08,
     125,  119,   12,   12, 0x08,
     156,  150,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_RssComboBox[] = {
    "RssComboBox\0\0text\0updatedDescription(QString)\0"
    "openUrl()\0url\0setUrl(QUrl)\0minutes\0"
    "setIntervalMinutes(int)\0requestFeed()\0"
    "reply\0readFeed(QNetworkReply*)\0index\0"
    "updateDescription(int)\0"
};

void RssComboBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RssComboBox *_t = static_cast<RssComboBox *>(_o);
        switch (_id) {
        case 0: _t->updatedDescription((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->openUrl(); break;
        case 2: _t->setUrl((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 3: _t->setIntervalMinutes((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->requestFeed(); break;
        case 5: _t->readFeed((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 6: _t->updateDescription((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData RssComboBox::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RssComboBox::staticMetaObject = {
    { &QComboBox::staticMetaObject, qt_meta_stringdata_RssComboBox,
      qt_meta_data_RssComboBox, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RssComboBox::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RssComboBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RssComboBox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RssComboBox))
        return static_cast<void*>(const_cast< RssComboBox*>(this));
    return QComboBox::qt_metacast(_clname);
}

int RssComboBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QComboBox::qt_metacall(_c, _id, _a);
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
void RssComboBox::updatedDescription(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
