#pragma once

#include <QObject>

class MetaStreamer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString suffix MEMBER suffix READ getSuffix WRITE setSuffix NOTIFY suffixChanged)
    Q_PROPERTY(QString prefix MEMBER prefix READ getPrefix WRITE setPrefix NOTIFY prefixChanged)
public:
    explicit MetaStreamer(QObject *parent = nullptr);

    void setSuffix(const QString& suffix);
    const QString& getSuffix() const;

    void setPrefix(const QString& prefix);
    const QString& getPrefix() const;

signals:
    void suffixChanged();
    void prefixChanged();

private:
    QString prefix;
    QString suffix;

};

