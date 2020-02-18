#pragma once

#include <QMetaObject>
#include <QIODevice>
#include <QScopedPointer>

#include "IMetaStreamer.h"
#include "MetaEnumStreamer.h"
#include "MetaMethodStreamer.h"
#include "MetaPropertyStreamer.h"

class MetaObjectStreamer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QObject* object READ getObject WRITE setObject NOTIFY objectChanged);

public:
    explicit MetaObjectStreamer(QObject* object, const QString& prefix = "", const QString& suffix = "");

    void stream(QIODevice* device) const;

    static void stream(QObject* object, QIODevice* device,
                       const QString& prefix = nullptr, const QString suffix = nullptr);

    void setObject(QObject* object);
    QObject* getObject() const;

signals:
    void objectChanged();

private:

    void streamClassDetails(const QMetaObject* metaObject, QIODevice* device) const;
    void streamMethods(const QMetaObject* metaObject, QIODevice* device) const;
    void streamProperties(const QMetaObject* metaObject, QIODevice* device) const;
    void streamEnums(const QMetaObject* metaObject, QIODevice* device) const;
    void streamClassInfo(const QMetaObject* metaObject, QIODevice* device) const;

    template <typename ...Tp>
    void writeData(QIODevice* device, Tp ... tp) const;

    QScopedPointer<QObject> object;
};












