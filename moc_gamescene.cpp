/****************************************************************************
** Meta object code from reading C++ file 'gamescene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "include/gamescene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamescene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GameScene_t {
    QByteArrayData data[14];
    char stringdata0[150];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameScene_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameScene_t qt_meta_stringdata_GameScene = {
    {
QT_MOC_LITERAL(0, 0, 9), // "GameScene"
QT_MOC_LITERAL(1, 10, 10), // "endOfLevel"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 5), // "score"
QT_MOC_LITERAL(4, 28, 13), // "helpRequested"
QT_MOC_LITERAL(5, 42, 14), // "pauseRequested"
QT_MOC_LITERAL(6, 57, 13), // "exitRequested"
QT_MOC_LITERAL(7, 71, 6), // "killed"
QT_MOC_LITERAL(8, 78, 10), // "npcCreated"
QT_MOC_LITERAL(9, 89, 3), // "num"
QT_MOC_LITERAL(10, 93, 8), // "printMap"
QT_MOC_LITERAL(11, 102, 22), // "QVector<QVector<int> >"
QT_MOC_LITERAL(12, 125, 13), // "matrixOfLevel"
QT_MOC_LITERAL(13, 139, 10) // "npcFactory"

    },
    "GameScene\0endOfLevel\0\0score\0helpRequested\0"
    "pauseRequested\0exitRequested\0killed\0"
    "npcCreated\0num\0printMap\0QVector<QVector<int> >\0"
    "matrixOfLevel\0npcFactory"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameScene[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    0,   57,    2, 0x06 /* Public */,
       5,    0,   58,    2, 0x06 /* Public */,
       6,    0,   59,    2, 0x06 /* Public */,
       7,    0,   60,    2, 0x06 /* Public */,
       8,    1,   61,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   64,    2, 0x0a /* Public */,
      13,    0,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,

       0        // eod
};

void GameScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GameScene *_t = static_cast<GameScene *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->endOfLevel((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->helpRequested(); break;
        case 2: _t->pauseRequested(); break;
        case 3: _t->exitRequested(); break;
        case 4: _t->killed(); break;
        case 5: _t->npcCreated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->printMap((*reinterpret_cast< const QVector<QVector<int> >(*)>(_a[1]))); break;
        case 7: _t->npcFactory(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QVector<int> > >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GameScene::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameScene::endOfLevel)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GameScene::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameScene::helpRequested)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GameScene::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameScene::pauseRequested)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (GameScene::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameScene::exitRequested)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (GameScene::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameScene::killed)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (GameScene::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameScene::npcCreated)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GameScene::staticMetaObject = { {
    &QGraphicsScene::staticMetaObject,
    qt_meta_stringdata_GameScene.data,
    qt_meta_data_GameScene,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GameScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameScene::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GameScene.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsScene::qt_metacast(_clname);
}

int GameScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void GameScene::endOfLevel(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GameScene::helpRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void GameScene::pauseRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void GameScene::exitRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void GameScene::killed()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void GameScene::npcCreated(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
