/****************************************************************************
** Meta object code from reading C++ file 'OknoGlowneApp.hh'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../inc/OknoGlowneApp.hh"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OknoGlowneApp.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OknoGlowneAplikacji_t {
    QByteArrayData data[7];
    char stringdata0[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OknoGlowneAplikacji_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OknoGlowneAplikacji_t qt_meta_stringdata_OknoGlowneAplikacji = {
    {
QT_MOC_LITERAL(0, 0, 19), // "OknoGlowneAplikacji"
QT_MOC_LITERAL(1, 20, 24), // "on_action_Open_triggered"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 7), // "checked"
QT_MOC_LITERAL(4, 54, 24), // "on_action_Exit_triggered"
QT_MOC_LITERAL(5, 79, 28), // "on__wPrzycisk_Koniec_clicked"
QT_MOC_LITERAL(6, 108, 36) // "on__wWyborJezyka_currentIndex..."

    },
    "OknoGlowneAplikacji\0on_action_Open_triggered\0"
    "\0checked\0on_action_Exit_triggered\0"
    "on__wPrzycisk_Koniec_clicked\0"
    "on__wWyborJezyka_currentIndexChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OknoGlowneAplikacji[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       4,    1,   37,    2, 0x0a /* Public */,
       5,    0,   40,    2, 0x0a /* Public */,
       6,    1,   41,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void OknoGlowneAplikacji::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<OknoGlowneAplikacji *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_action_Open_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->on_action_Exit_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on__wPrzycisk_Koniec_clicked(); break;
        case 3: _t->on__wWyborJezyka_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject OknoGlowneAplikacji::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_OknoGlowneAplikacji.data,
    qt_meta_data_OknoGlowneAplikacji,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *OknoGlowneAplikacji::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OknoGlowneAplikacji::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OknoGlowneAplikacji.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::OknoGlowne"))
        return static_cast< Ui::OknoGlowne*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int OknoGlowneAplikacji::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
