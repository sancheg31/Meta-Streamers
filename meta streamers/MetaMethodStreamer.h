#pragma once


#include <QMetaMethod>
#include <QIODevice>

#include "IMetaStreamer.h"

class MetaMethodStreamer : public IMetaStreamer
{
    Q_OBJECT
public:
    explicit MetaMethodStreamer(const QMetaMethod& method, const QString& prefix = "", const QString& suffix = "");

    void setMethod(const QMetaMethod& method);
    const QMetaMethod& getMethod() const;

    void stream(QIODevice* device) const override;

    static void stream(const QMetaMethod& method, QIODevice* device,
                       QString prefix = "", QString suffix = "");

signals:
    void methodChanged();

private:

    void createAccessTranslation();
    void createMethodTypeTranslation();

    QHash<QMetaMethod::Access, const char*> accessTranslation;
    QHash<QMetaMethod::MethodType, const char*> methodTypeTranslation;
    QMetaMethod method;
};

