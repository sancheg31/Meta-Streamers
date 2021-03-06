#pragma once

#include <QMetaEnum>
#include <QIODevice>

#include "IMetaStreamer.h"

class MetaEnumStreamer : public IMetaStreamer
{
    Q_OBJECT
public:
    explicit MetaEnumStreamer(const QMetaEnum& metaEnum, const QString& prefix = "", const QString& suffix = "");

    void setEnum(const QMetaEnum& e);
    const QMetaEnum& getEnum() const;

    void stream(QIODevice* device) const override;

    static void stream(const QMetaEnum& metaEnum, QIODevice* device,
                       const QString& prefix = "", const QString& suffix = "");

signals:
    void enumChanged();

private:
    QMetaEnum metaEnum;
};

