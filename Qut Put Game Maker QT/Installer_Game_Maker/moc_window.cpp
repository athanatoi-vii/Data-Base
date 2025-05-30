/****************************************************************************
** Meta object code from reading C++ file 'window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GameMaker_DataBase/window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Window_t {
    QByteArrayData data[20];
    char stringdata0[329];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Window_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Window_t qt_meta_stringdata_Window = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Window"
QT_MOC_LITERAL(1, 7, 14), // "set_Table_view"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 1), // "S"
QT_MOC_LITERAL(4, 25, 28), // "on_CB_Select_Table_activated"
QT_MOC_LITERAL(5, 54, 4), // "arg1"
QT_MOC_LITERAL(6, 59, 30), // "on_LE_Search_Member_textEdited"
QT_MOC_LITERAL(7, 90, 21), // "on_PB_Refresh_clicked"
QT_MOC_LITERAL(8, 112, 17), // "on_PB_Add_clicked"
QT_MOC_LITERAL(9, 130, 16), // "on_PB_OK_clicked"
QT_MOC_LITERAL(10, 147, 20), // "on_PB_Delete_clicked"
QT_MOC_LITERAL(11, 168, 29), // "on_CB_Select_Search_activated"
QT_MOC_LITERAL(12, 198, 5), // "index"
QT_MOC_LITERAL(13, 204, 10), // "deleleMenu"
QT_MOC_LITERAL(14, 215, 18), // "on_PB_Save_clicked"
QT_MOC_LITERAL(15, 234, 18), // "on_PB_Edit_clicked"
QT_MOC_LITERAL(16, 253, 15), // "Show_C_L_LE_Add"
QT_MOC_LITERAL(17, 269, 24), // "on_TV_Table_Veiw_clicked"
QT_MOC_LITERAL(18, 294, 11), // "QModelIndex"
QT_MOC_LITERAL(19, 306, 22) // "on_CB_Filter_activated"

    },
    "Window\0set_Table_view\0\0S\0"
    "on_CB_Select_Table_activated\0arg1\0"
    "on_LE_Search_Member_textEdited\0"
    "on_PB_Refresh_clicked\0on_PB_Add_clicked\0"
    "on_PB_OK_clicked\0on_PB_Delete_clicked\0"
    "on_CB_Select_Search_activated\0index\0"
    "deleleMenu\0on_PB_Save_clicked\0"
    "on_PB_Edit_clicked\0Show_C_L_LE_Add\0"
    "on_TV_Table_Veiw_clicked\0QModelIndex\0"
    "on_CB_Filter_activated"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Window[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x08 /* Private */,
       4,    1,   87,    2, 0x08 /* Private */,
       6,    1,   90,    2, 0x08 /* Private */,
       7,    0,   93,    2, 0x08 /* Private */,
       8,    0,   94,    2, 0x08 /* Private */,
       9,    0,   95,    2, 0x08 /* Private */,
      10,    0,   96,    2, 0x08 /* Private */,
      11,    1,   97,    2, 0x08 /* Private */,
      13,    0,  100,    2, 0x08 /* Private */,
      14,    0,  101,    2, 0x08 /* Private */,
      15,    0,  102,    2, 0x08 /* Private */,
      16,    0,  103,    2, 0x08 /* Private */,
      17,    1,  104,    2, 0x08 /* Private */,
      19,    1,  107,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18,   12,
    QMetaType::Void, QMetaType::Int,   12,

       0        // eod
};

void Window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Window *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->set_Table_view((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_CB_Select_Table_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_LE_Search_Member_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_PB_Refresh_clicked(); break;
        case 4: _t->on_PB_Add_clicked(); break;
        case 5: _t->on_PB_OK_clicked(); break;
        case 6: _t->on_PB_Delete_clicked(); break;
        case 7: _t->on_CB_Select_Search_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->deleleMenu(); break;
        case 9: _t->on_PB_Save_clicked(); break;
        case 10: _t->on_PB_Edit_clicked(); break;
        case 11: _t->Show_C_L_LE_Add(); break;
        case 12: _t->on_TV_Table_Veiw_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 13: _t->on_CB_Filter_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Window::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_Window.data,
    qt_meta_data_Window,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Window::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Window.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
