/****************************************************************************
** Meta object code from reading C++ file 'converter.h'
**
** Created: Mon Dec 16 15:41:19 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "converter.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'converter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ConverterDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x08,
      37,   16,   16,   16, 0x08,
      57,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ConverterDialog[] = {
    "ConverterDialog\0\0decChanged(QString)\0"
    "hexChanged(QString)\0binChanged(QString)\0"
};

void ConverterDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ConverterDialog *_t = static_cast<ConverterDialog *>(_o);
        switch (_id) {
        case 0: _t->decChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->hexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->binChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ConverterDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ConverterDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ConverterDialog,
      qt_meta_data_ConverterDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ConverterDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ConverterDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ConverterDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ConverterDialog))
        return static_cast<void*>(const_cast< ConverterDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ConverterDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
