#include "MetaEnumStreamer.h"

MetaEnumStreamer::MetaEnumStreamer(const QMetaEnum& e, const QString& prefix, const QString& suffix):
    IMetaStreamer(prefix, suffix), metaEnum(e) { }
void MetaEnumStreamer::setEnum(const QMetaEnum& e) {
    if (metaEnum.name() == e.name() && metaEnum.scope() == e.scope())
        return;
    metaEnum = e;
    emit enumChanged();
}

const QMetaEnum& MetaEnumStreamer::getEnum() const {
    return metaEnum;
}

/*virtual*/ void MetaEnumStreamer::stream(QIODevice* device) const {
    writeData(device, "meta enum streamer\n");
}

/*static*/ void MetaEnumStreamer::stream(const QMetaEnum& metaEnum, QIODevice* device, const QString& prefix, const QString suffix) {
    MetaEnumStreamer streamer(metaEnum, prefix, suffix);
    streamer.stream(device);
}


