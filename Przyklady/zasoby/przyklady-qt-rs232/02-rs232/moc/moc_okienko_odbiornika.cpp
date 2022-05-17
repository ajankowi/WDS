/****************************************************************************
** Meta object code from reading C++ file 'okienko_odbiornika.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../inc/okienko_odbiornika.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'okienko_odbiornika.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Kanwa_t {
    QByteArrayData data[8];
    char stringdata0[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Kanwa_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Kanwa_t qt_meta_stringdata_Kanwa = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Kanwa"
QT_MOC_LITERAL(1, 6, 26), // "on__wListaElem_itemClicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(4, 51, 5), // "wElem"
QT_MOC_LITERAL(5, 57, 29), // "on_EdycjaTekstu_returnPressed"
QT_MOC_LITERAL(6, 87, 27), // "on__wPrzycisk_Start_toggled"
QT_MOC_LITERAL(7, 115, 7) // "Checked"

    },
    "Kanwa\0on__wListaElem_itemClicked\0\0"
    "QListWidgetItem*\0wElem\0"
    "on_EdycjaTekstu_returnPressed\0"
    "on__wPrzycisk_Start_toggled\0Checked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Kanwa[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       5,    0,   32,    2, 0x0a /* Public */,
       6,    1,   33,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,

       0        // eod
};

void Kanwa::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Kanwa *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on__wListaElem_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 1: _t->on_EdycjaTekstu_returnPressed(); break;
        case 2: _t->on__wPrzycisk_Start_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Kanwa::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Kanwa.data,
    qt_meta_data_Kanwa,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Kanwa::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Kanwa::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Kanwa.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Kanwa::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
