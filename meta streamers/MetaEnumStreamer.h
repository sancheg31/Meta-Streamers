#pragma once

#include <QMetaEnum>
#include <QIODevice>
#include <QScopedPointer>
class MetaEnumStreamer : public QObject
{
    Q_OBJECT
public:
    explicit MetaEnumStreamer(const QMetaEnum& metaEnum);

    void setEnum(const QMetaEnum& e);

    const QMetaEnum& getEnum() const;
    void stream(QIODevice* device) const;

    static void stream(const QMetaEnum& metaEnum, QIODevice* device);

signals:
    void enumChanged();

private:

    template <typename ...Tp>
    void writeData(QIODevice* device, Tp ... tp) const;

    QMetaEnum metaEnum;
};

