#pragma once


#include <QMetaMethod>
#include <QIODevice>
#include <QScopedPointer>

#include "IMetaStreamer.h"

class MetaMethodStreamer : public IMetaStreamer
{
    Q_OBJECT
public:
    explicit MetaMethodStreamer(const QMetaMethod& method, const QString& prefix = "", const QString& suffix = "");

    void setMethod(const QMetaMethod& method);
    const QMetaMethod& getMethod() const;

    void stream(QIODevice* device) const override;

    static void stream(const QMetaMethod& method, QIODevice* device);

signals:
    void methodChanged();

private:

    template <typename ...Tp>
    void writeData(QIODevice* device, Tp ... tp) const;

    QMetaMethod method;
};

