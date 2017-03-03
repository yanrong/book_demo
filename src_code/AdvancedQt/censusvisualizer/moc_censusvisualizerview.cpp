/****************************************************************************
** Meta object code from reading C++ file 'censusvisualizerview.hpp'
**
** Created: Fri Apr 11 18:10:10 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "censusvisualizerview.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'censusvisualizerview.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CensusVisualizerView[] = {

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
      22,   21,   21,   21, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_CensusVisualizerView[] = {
    "CensusVisualizerView\0\0clicked(QModelIndex)\0"
};

void CensusVisualizerView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CensusVisualizerView *_t = static_cast<CensusVisualizerView *>(_o);
        switch (_id) {
        case 0: _t->clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CensusVisualizerView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CensusVisualizerView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CensusVisualizerView,
      qt_meta_data_CensusVisualizerView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CensusVisualizerView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CensusVisualizerView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CensusVisualizerView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CensusVisualizerView))
        return static_cast<void*>(const_cast< CensusVisualizerView*>(this));
    return QWidget::qt_metacast(_clname);
}

int CensusVisualizerView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void CensusVisualizerView::clicked(const QModelIndex & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
