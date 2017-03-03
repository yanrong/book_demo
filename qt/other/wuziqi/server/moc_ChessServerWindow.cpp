/****************************************************************************
** Meta object code from reading C++ file 'ChessServerWindow.h'
**
** Created: Fri May 9 17:12:44 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ChessServerWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ChessServerWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ChessServerWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x05,
      42,   40,   18,   18, 0x05,
      73,   18,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      89,   18,   18,   18, 0x0a,
     108,  104,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ChessServerWindow[] = {
    "ChessServerWindow\0\0victorySignal(Chess)\0"
    ",\0myCoordinateAvailable(int,int)\0"
    "restartSignal()\0restart(Chess)\0x,y\0"
    "getPeerCoordinate(int,int)\0"
};

void ChessServerWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ChessServerWindow *_t = static_cast<ChessServerWindow *>(_o);
        switch (_id) {
        case 0: _t->victorySignal((*reinterpret_cast< Chess(*)>(_a[1]))); break;
        case 1: _t->myCoordinateAvailable((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->restartSignal(); break;
        case 3: _t->restart((*reinterpret_cast< Chess(*)>(_a[1]))); break;
        case 4: _t->getPeerCoordinate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ChessServerWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ChessServerWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ChessServerWindow,
      qt_meta_data_ChessServerWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ChessServerWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ChessServerWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ChessServerWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ChessServerWindow))
        return static_cast<void*>(const_cast< ChessServerWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int ChessServerWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void ChessServerWindow::victorySignal(Chess _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ChessServerWindow::myCoordinateAvailable(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ChessServerWindow::restartSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
