/****************************************************************************
** Meta object code from reading C++ file 'uvision.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../uvision.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uvision.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_uVision[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x08,
      33,    8,    8,    8, 0x08,
      64,    8,    8,    8, 0x08,
      87,    8,    8,    8, 0x08,
     117,    8,    8,    8, 0x09,
     140,    8,    8,    8, 0x09,
     164,  155,    8,    8, 0x09,
     183,    8,    8,    8, 0x09,
     204,    8,    8,    8, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_uVision[] = {
    "uVision\0\0on_actPlayBtn_clicked()\0"
    "on_actVideoParameter_clicked()\0"
    "on_serialBtn_clicked()\0"
    "on_actImageInstitch_clicked()\0"
    "on_openFiles_clicked()\0deleteThread()\0"
    "filename\0showError(QString)\0"
    "addThumbnail(QImage)\0addInstitchImages(QImage)\0"
};

void uVision::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        uVision *_t = static_cast<uVision *>(_o);
        switch (_id) {
        case 0: _t->on_actPlayBtn_clicked(); break;
        case 1: _t->on_actVideoParameter_clicked(); break;
        case 2: _t->on_serialBtn_clicked(); break;
        case 3: _t->on_actImageInstitch_clicked(); break;
        case 4: _t->on_openFiles_clicked(); break;
        case 5: _t->deleteThread(); break;
        case 6: _t->showError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->addThumbnail((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 8: _t->addInstitchImages((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData uVision::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject uVision::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_uVision,
      qt_meta_data_uVision, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &uVision::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *uVision::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *uVision::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_uVision))
        return static_cast<void*>(const_cast< uVision*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int uVision::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
