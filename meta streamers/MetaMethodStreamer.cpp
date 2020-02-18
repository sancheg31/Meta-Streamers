#include "MetaMethodStreamer.h"

MetaMethodStreamer::MetaMethodStreamer(const QMetaMethod& m): QObject(), method(m) { }

void MetaMethodStreamer::setMethod(const QMetaMethod& m) {

    if (method.methodSignature() == m.methodSignature())
        return;
    method = m;
    emit methodChanged();
}

const QMetaMethod& MetaMethodStreamer::getMethod() const {
    return method;
}

void MetaMethodStreamer::stream(QIODevice* device) const {
    writeData(device, "meta method streamer\n");
}

void MetaMethodStreamer::stream(const QMetaMethod& method, QIODevice* device) {
    MetaMethodStreamer streamer(method);
    streamer.stream(device);
}

template<typename ...Tp>
void MetaMethodStreamer::writeData(QIODevice* device, Tp ... tp) const {
    ((device->write(tp), ...));
}
