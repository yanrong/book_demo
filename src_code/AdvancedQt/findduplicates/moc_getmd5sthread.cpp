/****************************************************************************
** Meta object code from reading C++ file 'getmd5sthread.hpp'
**
** Created: Fri Apr 11 18:10:49 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "getmd5sthread.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'getmd5sthread.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GetMD5sThread[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_GetMD5sThread[] = {
    "GetMD5sThread\0\0readOneFile()\0"
};

void GetMD5sThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GetMD5sThread *_t = static_cast<GetMD5sThread *>(_o);
        switch (_id) {
        case 0: _t->readOneFile(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData GetMD5sThread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GetMD5sThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_GetMD5sThread,
      qt_meta_data_GetMD5sThread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GetMD5sThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GetMD5sThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GetMD5sThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GetMD5sThread))
        return static_cast<void*>(const_cast< GetMD5sThread*>(this));
    return QThread::qt_metacast(_clname);
}

int GetMD5sThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void GetMD5sThread::readOneFile()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
