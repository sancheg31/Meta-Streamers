#pragma once

#include <QMetaType>
#include <QIODevice>
#include <QScopedPointer>

/*
class MetaTypeStreamer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QMetaType metaType MEMBER metaType READ getType WRITE setType NOTIFY typeChanged)
public:
    explicit MetaTypeStreamer(const QMetaType& type);

    void setType(QMetaType type);
    const QMetaType& getType() const;
    void stream(QIODevice* device) const;

    static void stream(const QMetaType& type, QIODevice* device);

signals:
    void typeChanged();
private:
    QMetaType metaType;
};

*/
