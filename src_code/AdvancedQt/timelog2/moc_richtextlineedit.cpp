/****************************************************************************
** Meta object code from reading C++ file 'richtextlineedit.hpp'
**
** Created: Fri Apr 11 18:09:56 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../timelog1/richtextlineedit.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'richtextlineedit.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RichTextLineEdit[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      34,   17,   17,   17, 0x0a,
      49,   17,   17,   17, 0x0a,
      66,   62,   17,   17, 0x08,
     101,   17,   17,   17, 0x08,
     126,  119,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_RichTextLineEdit[] = {
    "RichTextLineEdit\0\0returnPressed()\0"
    "toggleItalic()\0toggleBold()\0pos\0"
    "customContextMenuRequested(QPoint)\0"
    "applyTextEffect()\0action\0applyColor(QAction*)\0"
};

void RichTextLineEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RichTextLineEdit *_t = static_cast<RichTextLineEdit *>(_o);
        switch (_id) {
        case 0: _t->returnPressed(); break;
        case 1: _t->toggleItalic(); break;
        case 2: _t->toggleBold(); break;
        case 3: _t->customContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 4: _t->applyTextEffect(); break;
        case 5: _t->applyColor((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData RichTextLineEdit::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RichTextLineEdit::staticMetaObject = {
    { &QTextEdit::staticMetaObject, qt_meta_stringdata_RichTextLineEdit,
      qt_meta_data_RichTextLineEdit, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RichTextLineEdit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RichTextLineEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RichTextLineEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RichTextLineEdit))
        return static_cast<void*>(const_cast< RichTextLineEdit*>(this));
    return QTextEdit::qt_metacast(_clname);
}

int RichTextLineEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void RichTextLineEdit::returnPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
