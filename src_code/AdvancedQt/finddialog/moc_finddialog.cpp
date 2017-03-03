/****************************************************************************
** Meta object code from reading C++ file 'finddialog.hpp'
**
** Created: Fri Apr 11 18:12:02 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "finddialog.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'finddialog.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FindDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      30,   11,   11,   11, 0x05,
      51,   11,   11,   11, 0x05,
      63,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      75,   11,   11,   11, 0x08,
     102,   97,   11,   11, 0x08,
     130,  127,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FindDialog[] = {
    "FindDialog\0\0findTextIsEmpty()\0"
    "findTextIsNonEmpty()\0showExtra()\0"
    "hideExtra()\0createStateMachines()\0"
    "text\0findTextChanged(QString)\0on\0"
    "showOrHideExtra(bool)\0"
};

void FindDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        FindDialog *_t = static_cast<FindDialog *>(_o);
        switch (_id) {
        case 0: _t->findTextIsEmpty(); break;
        case 1: _t->findTextIsNonEmpty(); break;
        case 2: _t->showExtra(); break;
        case 3: _t->hideExtra(); break;
        case 4: _t->createStateMachines(); break;
        case 5: _t->findTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->showOrHideExtra((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData FindDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject FindDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_FindDialog,
      qt_meta_data_FindDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FindDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FindDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FindDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FindDialog))
        return static_cast<void*>(const_cast< FindDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int FindDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void FindDialog::findTextIsEmpty()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void FindDialog::findTextIsNonEmpty()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void FindDialog::showExtra()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void FindDialog::hideExtra()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
