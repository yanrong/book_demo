/****************************************************************************
** Meta object code from reading C++ file 'xmledit.hpp'
**
** Created: Fri Apr 11 18:11:11 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "xmledit.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'xmledit.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_XmlEdit[] = {

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
      31,    9,    8,    8, 0x08,
      73,   62,    8,    8, 0x28,
      99,    8,    8,    8, 0x08,
     122,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_XmlEdit[] = {
    "XmlEdit\0\0completion,singleWord\0"
    "insertCompletion(QString,bool)\0"
    "completion\0insertCompletion(QString)\0"
    "highlightCurrentLine()\0performCompletion()\0"
};

void XmlEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        XmlEdit *_t = static_cast<XmlEdit *>(_o);
        switch (_id) {
        case 0: _t->insertCompletion((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->insertCompletion((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->highlightCurrentLine(); break;
        case 3: _t->performCompletion(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData XmlEdit::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject XmlEdit::staticMetaObject = {
    { &QPlainTextEdit::staticMetaObject, qt_meta_stringdata_XmlEdit,
      qt_meta_data_XmlEdit, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &XmlEdit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *XmlEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *XmlEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_XmlEdit))
        return static_cast<void*>(const_cast< XmlEdit*>(this));
    return QPlainTextEdit::qt_metacast(_clname);
}

int XmlEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPlainTextEdit::qt_metacall(_c, _id, _a);
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
