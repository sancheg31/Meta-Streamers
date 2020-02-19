#pragma once

#include <QObject>
#include <QMetaProperty>
#include <QIODevice>

#include "IMetaStreamer.h"

class MetaPropertyStreamer : public IMetaStreamer
{
    Q_OBJECT
public:
    explicit MetaPropertyStreamer(const QMetaProperty& property, const QString& prefix = "", const QString& suffix = "");

    void setProperty(const QMetaProperty& property);
    const QMetaProperty& getProperty() const;

    void stream(QIODevice* device) const override;

    static void stream(const QMetaProperty& property, QIODevice* device,
                       const QString& prefix = "", const QString& suffix = "");

signals:
    void propertyChanged();

private:

    void evaluateMacrosPresence();

    QList<QPair<bool, const char*>> macrosPresence;
    QMetaProperty property;
};

