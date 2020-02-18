#pragma once

#include <QObject>

class Counter : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int value MEMBER value NOTIFY counterChanged)
public:
    explicit Counter(QObject *parent = nullptr, int value = 0);

private:
    int value;

private slots:
    void increment();
    void decrement();

signals:
    void counterChanged(int);
};

