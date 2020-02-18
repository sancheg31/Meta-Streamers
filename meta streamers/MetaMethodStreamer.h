#pragma once


#include <QMetaMethod>
#include <QIODevice>
#include <QScopedPointer>

class MetaMethodStreamer : public QObject
{
    Q_OBJECT
public:
    explicit MetaMethodStreamer(const QMetaMethod& method);

    void setMethod(const QMetaMethod& method);

    const QMetaMethod& getMethod() const;
    void stream(QIODevice* device) const;

    static void stream(const QMetaMethod& method, QIODevice* device);

signals:
    void methodChanged();

private:

    template <typename ...Tp>
    void writeData(QIODevice* device, Tp ... tp) const;

    QMetaMethod method;
};

