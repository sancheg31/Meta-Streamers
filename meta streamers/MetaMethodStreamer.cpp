#include "MetaMethodStreamer.h"

MetaMethodStreamer::MetaMethodStreamer(const QMetaMethod& m, const QString& prefix, const QString& suffix):
    IMetaStreamer(prefix, suffix), method(m) {
    createAccessTranslation();
    createMethodTypeTranslation();
}

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
    const char* pref = prefix.toLocal8Bit().data();
    const char* suf = suffix.toLocal8Bit().data();
    writeData(device, pref, methodTypeTranslation[method.methodType()], ":\t", accessTranslation[method.access()], " ",
                method.typeName(), " ", method.methodSignature().data(), suf, "\n");
}

/*static*/ void MetaMethodStreamer::stream(const QMetaMethod& method, QIODevice* device, QString prefix, QString suffix) {
    MetaMethodStreamer streamer(method, prefix, suffix);
    streamer.stream(device);
}

void MetaMethodStreamer::createAccessTranslation() {
    accessTranslation.insert(QMetaMethod::Public, "public");
    accessTranslation.insert(QMetaMethod::Protected, "protected");
    accessTranslation.insert(QMetaMethod::Private, "private");
}

void MetaMethodStreamer::createMethodTypeTranslation() {
    methodTypeTranslation.insert(QMetaMethod::Method, "method");
    methodTypeTranslation.insert(QMetaMethod::Constructor, "constructor");
    methodTypeTranslation.insert(QMetaMethod::Slot, "slot");
    methodTypeTranslation.insert(QMetaMethod::Signal, "signal");
}

