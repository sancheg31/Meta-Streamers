#include "MetaMethodStreamer.h"

MetaMethodStreamer::MetaMethodStreamer(const QMetaMethod& m, const QString& prefix, const QString& suffix):
    IMetaStreamer(prefix, suffix), method(m) { }

void MetaMethodStreamer::setMethod(const QMetaMethod& m) {
    if (method.methodSignature() == m.methodSignature())
        return;
    method = m;
    emit methodChanged();
}

const QMetaMethod& MetaMethodStreamer::getMethod() const {
    return method;
}

/*virtual*/ void MetaMethodStreamer::stream(QIODevice* device) const {
    writeData(device, "meta method\n");
}

/*static*/ void MetaMethodStreamer::stream(const QMetaMethod& method, QIODevice* device, const QString& prefix, const QString suffix) {
    MetaMethodStreamer streamer(method, prefix, suffix);
    streamer.stream(device);
}

