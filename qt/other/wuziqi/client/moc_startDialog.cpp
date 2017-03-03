/****************************************************************************
** Meta object code from reading C++ file 'startDialog.h'
**
** Created: Fri May 9 15:27:38 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "startDialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'startDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_StartDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   13,   12,   12, 0x05,
      38,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      51,   12,   12,   12, 0x0a,
      61,   12,   12,   12, 0x0a,
      81,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_StartDialog[] = {
    "StartDialog\0\0,\0start(QString,QString)\0"
    "quitClient()\0doStart()\0enableStartButton()\0"
    "doQuit()\0"
};

void StartDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        StartDialog *_t = static_cast<StartDialog *>(_o);
        switch (_id) {
        case 0: _t->start((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->quitClient(); break;
        case 2: _t->doStart(); break;
        case 3: _t->enableStartButton(); break;
        case 4: _t->doQuit(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData StartDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject StartDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_StartDialog,
      qt_meta_data_StartDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &StartDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *StartDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *StartDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_StartDialog))
        return static_cast<void*>(const_cast< StartDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int StartDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void StartDialog::start(const QString & _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void StartDialog::quitClient()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
