/****************************************************************************
** Meta object code from reading C++ file 'victoryDialog.h'
**
** Created: Wed May 7 14:45:58 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "victoryDialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'victoryDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_victoryDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      28,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_victoryDialog[] = {
    "victoryDialog\0\0quitSignal()\0doQuit()\0"
};

void victoryDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        victoryDialog *_t = static_cast<victoryDialog *>(_o);
        switch (_id) {
        case 0: _t->quitSignal(); break;
        case 1: _t->doQuit(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData victoryDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject victoryDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_victoryDialog,
      qt_meta_data_victoryDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &victoryDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *victoryDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *victoryDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_victoryDialog))
        return static_cast<void*>(const_cast< victoryDialog*>(this));
    if (!strcmp(_clname, "Ui_Dialog"))
        return static_cast< Ui_Dialog*>(const_cast< victoryDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int victoryDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void victoryDialog::quitSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
