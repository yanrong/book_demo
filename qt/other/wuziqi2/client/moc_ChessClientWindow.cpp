/****************************************************************************
** Meta object code from reading C++ file 'ChessClientWindow.h'
**
** Created: Fri May 30 21:31:43 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ChessClientWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ChessClientWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ChessClientWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x05,
      44,   40,   18,   18, 0x05,
      75,   18,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      85,   18,   18,   18, 0x0a,
     100,   40,   18,   18, 0x0a,
     129,  127,   18,   18, 0x0a,
     154,   18,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ChessClientWindow[] = {
    "ChessClientWindow\0\0victorySignal(Chess)\0"
    "x,y\0myCoordinateAvailable(int,int)\0"
    "restart()\0restart(Chess)\0"
    "getPeerCoordinate(int,int)\0,\0"
    "doStart(QString,QString)\0quitClient()\0"
};

void ChessClientWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ChessClientWindow *_t = static_cast<ChessClientWindow *>(_o);
        switch (_id) {
        case 0: _t->victorySignal((*reinterpret_cast< Chess(*)>(_a[1]))); break;
        case 1: _t->myCoordinateAvailable((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->restart(); break;
        case 3: _t->restart((*reinterpret_cast< Chess(*)>(_a[1]))); break;
        case 4: _t->getPeerCoordinate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->doStart((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 6: _t->quitClient(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ChessClientWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ChessClientWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ChessClientWindow,
      qt_meta_data_ChessClientWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ChessClientWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ChessClientWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ChessClientWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ChessClientWindow))
        return static_cast<void*>(const_cast< ChessClientWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int ChessClientWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void ChessClientWindow::victorySignal(Chess _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ChessClientWindow::myCoordinateAvailable(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ChessClientWindow::restart()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
