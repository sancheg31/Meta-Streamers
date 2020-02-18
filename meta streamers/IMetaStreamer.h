#pragma once

#include <QObject>

class IMetaStreamer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString suffix MEMBER suffix READ getSuffix WRITE setSuffix NOTIFY suffixChanged)
    Q_PROPERTY(QString prefix MEMBER prefix READ getPrefix WRITE setPrefix NOTIFY prefixChanged)
public:
    explicit IMetaStreamer(const QString& prefix = "", const QString& suffix = "");

    void setSuffix(const QString& suffix);
    const QString& getSuffix() const;

    void setPrefix(const QString& prefix);
    const QString& getPrefix() const;

    virtual void stream(QIODevice* device) const = 0;

protected:
    template <typename ...Tp>
    void writeData(QIODevice* device, Tp ... tp) const;

signals:
    void suffixChanged();
    void prefixChanged();

private:
    QString prefix;
    QString suffix;
};

