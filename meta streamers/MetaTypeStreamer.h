#pragma once

#include <QMetaType>
#include <QIODevice>

#include "IMetaStreamer.h"

/*
class MetaTypeStreamer : public IMetaStreamer
{
    Q_OBJECT
    Q_PROPERTY(QMetaType metaType MEMBER metaType READ getType WRITE setType NOTIFY typeChanged)
public:
    explicit MetaTypeStreamer(const QMetaType& type,
                       const QString& prefix = "", const QString suffix = "");

    void setType(QMetaType type);
    const QMetaType& getType() const;
    void stream(QIODevice* device) const;

    static void stream(const QMetaType& type, QIODevice* device,
                       const QString& prefix = "", const QString suffix = "");

signals:
    void typeChanged();
private:
    QMetaType metaType;
};

*/
