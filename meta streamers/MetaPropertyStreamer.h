#pragma once

#include <QObject>
#include <QMetaProperty>
#include <QIODevice>
#include <QScopedPointer>

class MetaPropertyStreamer : public QObject
{
    Q_OBJECT
public:
    explicit MetaPropertyStreamer(const QMetaProperty& property);

    void setProperty(const QMetaProperty& property);

    const QMetaProperty& getProperty() const;
    void stream(QIODevice* device) const;

    static void stream(const QMetaProperty& property, QIODevice* device);

signals:
    void propertyChanged();

private:
    template <typename ...Tp>
    void writeData(QIODevice* device, Tp ... tp) const;

    QMetaProperty property;
};

