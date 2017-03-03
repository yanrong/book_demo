/****************************************************************************
** Meta object code from reading C++ file 'textedit.hpp'
**
** Created: Fri Apr 11 18:12:20 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../textedit/textedit.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'textedit.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TextEdit[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      29,   24,    9,    9, 0x0a,
      49,   46,    9,    9, 0x08,
      63,    9,    9,    9, 0x08,
      80,   74,    9,    9, 0x08,
     107,  100,    9,    9, 0x08,
     137,  132,    9,    9, 0x08,
     165,  158,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TextEdit[] = {
    "TextEdit\0\0textChanged()\0html\0"
    "setHtml(QString)\0on\0setBold(bool)\0"
    "setColor()\0color\0updateColor(QColor)\0"
    "points\0setFontPointSize(double)\0font\0"
    "setFontFamily(QFont)\0format\0"
    "currentCharFormatChanged(QTextCharFormat)\0"
};

void TextEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TextEdit *_t = static_cast<TextEdit *>(_o);
        switch (_id) {
        case 0: _t->textChanged(); break;
        case 1: _t->setHtml((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->setBold((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->setColor(); break;
        case 4: _t->updateColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 5: _t->setFontPointSize((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->setFontFamily((*reinterpret_cast< const QFont(*)>(_a[1]))); break;
        case 7: _t->currentCharFormatChanged((*reinterpret_cast< const QTextCharFormat(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TextEdit::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TextEdit::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TextEdit,
      qt_meta_data_TextEdit, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TextEdit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TextEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TextEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TextEdit))
        return static_cast<void*>(const_cast< TextEdit*>(this));
    return QWidget::qt_metacast(_clname);
}

int TextEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void TextEdit::textChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
