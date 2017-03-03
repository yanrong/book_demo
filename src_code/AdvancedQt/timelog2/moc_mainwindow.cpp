/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.hpp'
**
** Created: Fri Apr 11 18:09:58 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../timelog1/mainwindow.hpp"
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
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      25,   11,   11,   11, 0x08,
      35,   11,   11,   11, 0x08,
      51,   11,   46,   11, 0x08,
      62,   11,   46,   11, 0x08,
      75,   11,   11,   11, 0x08,
      85,   11,   11,   11, 0x08,
      98,   11,   11,   11, 0x08,
     108,   11,   11,   11, 0x08,
     120,   11,   11,   11, 0x08,
     133,   11,   11,   11, 0x08,
     148,   11,   11,   11, 0x08,
     162,   11,   11,   11, 0x08,
     181,  175,   11,   11, 0x08,
     208,  203,   11,   11, 0x08,
     244,  238,   11,   11, 0x08,
     259,   11,   11,   11, 0x28,
     288,  270,   11,   11, 0x08,
     323,  314,   11,   11, 0x28,
     337,   11,   11,   11, 0x08,
     353,  347,   11,   11, 0x08,
     369,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0stopTiming()\0fileNew()\0"
    "fileOpen()\0bool\0fileSave()\0fileSaveAs()\0"
    "editAdd()\0editDelete()\0editCut()\0"
    "editPaste()\0editMoveUp()\0editMoveDown()\0"
    "editPromote()\0editDemote()\0start\0"
    "editStartOrStop(bool)\0hide\0"
    "editHideOrShowDoneTasks(bool)\0dirty\0"
    "setDirty(bool)\0setDirty()\0filename,taskPath\0"
    "load(QString,QStringList)\0filename\0"
    "load(QString)\0timeout()\0frame\0"
    "updateIcon(int)\0updateUi()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->stopTiming(); break;
        case 1: _t->fileNew(); break;
        case 2: _t->fileOpen(); break;
        case 3: { bool _r = _t->fileSave();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: { bool _r = _t->fileSaveAs();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: _t->editAdd(); break;
        case 6: _t->editDelete(); break;
        case 7: _t->editCut(); break;
        case 8: _t->editPaste(); break;
        case 9: _t->editMoveUp(); break;
        case 10: _t->editMoveDown(); break;
        case 11: _t->editPromote(); break;
        case 12: _t->editDemote(); break;
        case 13: _t->editStartOrStop((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->editHideOrShowDoneTasks((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->setDirty((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->setDirty(); break;
        case 17: _t->load((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2]))); break;
        case 18: _t->load((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 19: _t->timeout(); break;
        case 20: _t->updateIcon((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->updateUi(); break;
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
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
