/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.hpp'
**
** Created: Fri Apr 11 18:12:27 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../pagedesigner1/mainwindow.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   12,   11,   11, 0x0a,
      30,   11,   11,   11, 0x2a,
      41,   11,   11,   11, 0x08,
      51,   11,   11,   11, 0x08,
      67,   11,   62,   11, 0x08,
      78,   11,   62,   11, 0x08,
      91,   11,   11,   11, 0x08,
     104,   11,   11,   11, 0x08,
     116,   11,   11,   11, 0x08,
     135,   11,   11,   11, 0x08,
     149,   11,   11,   11, 0x08,
     160,   11,   11,   11, 0x08,
     170,   11,   11,   11, 0x08,
     182,   11,   11,   11, 0x08,
     194,   11,   11,   11, 0x08,
     216,   11,   11,   11, 0x08,
     227,   12,   11,   11, 0x08,
     246,   11,   11,   11, 0x08,
     265,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on\0setDirty(bool)\0setDirty()\0"
    "fileNew()\0fileOpen()\0bool\0fileSave()\0"
    "fileSaveAs()\0fileExport()\0filePrint()\0"
    "editSelectedItem()\0editAddItem()\0"
    "editCopy()\0editCut()\0editPaste()\0"
    "editAlign()\0editClearTransforms()\0"
    "updateUi()\0viewShowGrid(bool)\0"
    "selectionChanged()\0loadFile()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->setDirty((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->setDirty(); break;
        case 2: _t->fileNew(); break;
        case 3: _t->fileOpen(); break;
        case 4: { bool _r = _t->fileSave();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: { bool _r = _t->fileSaveAs();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: _t->fileExport(); break;
        case 7: _t->filePrint(); break;
        case 8: _t->editSelectedItem(); break;
        case 9: _t->editAddItem(); break;
        case 10: _t->editCopy(); break;
        case 11: _t->editCut(); break;
        case 12: _t->editPaste(); break;
        case 13: _t->editAlign(); break;
        case 14: _t->editClearTransforms(); break;
        case 15: _t->updateUi(); break;
        case 16: _t->viewShowGrid((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->selectionChanged(); break;
        case 18: _t->loadFile(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
