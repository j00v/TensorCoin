/****************************************************************************
** Meta object code from reading C++ file 'send.h'
**
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qt/tensorcoin/send.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'send.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SendWidget_t {
    QByteArrayData data[25];
    char stringdata0[349];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SendWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SendWidget_t qt_meta_stringdata_SendWidget = {
    {
QT_MOC_LITERAL(0, 0, 10), // "SendWidget"
QT_MOC_LITERAL(1, 11, 11), // "receivedURI"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 3), // "uri"
QT_MOC_LITERAL(4, 28, 22), // "onChangeAddressClicked"
QT_MOC_LITERAL(5, 51, 24), // "onChangeCustomFeeClicked"
QT_MOC_LITERAL(6, 76, 20), // "onCoinControlClicked"
QT_MOC_LITERAL(7, 97, 16), // "onOpenUriClicked"
QT_MOC_LITERAL(8, 114, 14), // "onValueChanged"
QT_MOC_LITERAL(9, 129, 14), // "refreshAmounts"
QT_MOC_LITERAL(10, 144, 11), // "changeTheme"
QT_MOC_LITERAL(11, 156, 12), // "isLightTheme"
QT_MOC_LITERAL(12, 169, 8), // "QString&"
QT_MOC_LITERAL(13, 178, 5), // "theme"
QT_MOC_LITERAL(14, 184, 13), // "onSendClicked"
QT_MOC_LITERAL(15, 198, 17), // "onContactsClicked"
QT_MOC_LITERAL(16, 216, 13), // "SendMultiRow*"
QT_MOC_LITERAL(17, 230, 5), // "entry"
QT_MOC_LITERAL(18, 236, 13), // "onMenuClicked"
QT_MOC_LITERAL(19, 250, 17), // "onAddEntryClicked"
QT_MOC_LITERAL(20, 268, 12), // "clearEntries"
QT_MOC_LITERAL(21, 281, 8), // "clearAll"
QT_MOC_LITERAL(22, 290, 21), // "onContactMultiClicked"
QT_MOC_LITERAL(23, 312, 15), // "onDeleteClicked"
QT_MOC_LITERAL(24, 328, 20) // "onResetCustomOptions"

    },
    "SendWidget\0receivedURI\0\0uri\0"
    "onChangeAddressClicked\0onChangeCustomFeeClicked\0"
    "onCoinControlClicked\0onOpenUriClicked\0"
    "onValueChanged\0refreshAmounts\0changeTheme\0"
    "isLightTheme\0QString&\0theme\0onSendClicked\0"
    "onContactsClicked\0SendMultiRow*\0entry\0"
    "onMenuClicked\0onAddEntryClicked\0"
    "clearEntries\0clearAll\0onContactMultiClicked\0"
    "onDeleteClicked\0onResetCustomOptions"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SendWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,  102,    2, 0x0a /* Public */,
       5,    0,  103,    2, 0x0a /* Public */,
       6,    0,  104,    2, 0x0a /* Public */,
       7,    0,  105,    2, 0x0a /* Public */,
       8,    0,  106,    2, 0x0a /* Public */,
       9,    0,  107,    2, 0x0a /* Public */,
      10,    2,  108,    2, 0x0a /* Public */,
      14,    0,  113,    2, 0x08 /* Private */,
      15,    1,  114,    2, 0x08 /* Private */,
      18,    1,  117,    2, 0x08 /* Private */,
      19,    0,  120,    2, 0x08 /* Private */,
      20,    0,  121,    2, 0x08 /* Private */,
      21,    0,  122,    2, 0x08 /* Private */,
      22,    0,  123,    2, 0x08 /* Private */,
      23,    0,  124,    2, 0x08 /* Private */,
      24,    0,  125,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 12,   11,   13,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SendWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SendWidget *_t = static_cast<SendWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->receivedURI((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->onChangeAddressClicked(); break;
        case 2: _t->onChangeCustomFeeClicked(); break;
        case 3: _t->onCoinControlClicked(); break;
        case 4: _t->onOpenUriClicked(); break;
        case 5: _t->onValueChanged(); break;
        case 6: _t->refreshAmounts(); break;
        case 7: _t->changeTheme((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 8: _t->onSendClicked(); break;
        case 9: _t->onContactsClicked((*reinterpret_cast< SendMultiRow*(*)>(_a[1]))); break;
        case 10: _t->onMenuClicked((*reinterpret_cast< SendMultiRow*(*)>(_a[1]))); break;
        case 11: _t->onAddEntryClicked(); break;
        case 12: _t->clearEntries(); break;
        case 13: _t->clearAll(); break;
        case 14: _t->onContactMultiClicked(); break;
        case 15: _t->onDeleteClicked(); break;
        case 16: _t->onResetCustomOptions(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SendMultiRow* >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SendMultiRow* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (SendWidget::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SendWidget::receivedURI)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject SendWidget::staticMetaObject = {
    { &PWidget::staticMetaObject, qt_meta_stringdata_SendWidget.data,
      qt_meta_data_SendWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SendWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SendWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SendWidget.stringdata0))
        return static_cast<void*>(this);
    return PWidget::qt_metacast(_clname);
}

int SendWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void SendWidget::receivedURI(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
