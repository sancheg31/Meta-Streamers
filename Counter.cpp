#include "Counter.h"


Counter::Counter(QObject* parent, int val): QObject(parent), value(val) { }

void Counter::increment() {
    ++value;
    emit counterChanged(value);
}

void Counter::decrement() {
    --value;
    emit counterChanged(value);
}
