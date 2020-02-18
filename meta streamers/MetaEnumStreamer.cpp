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

void MetaEnumStreamer::stream(QIODevice* device) const {
    writeData(device, "meta enum streamer\n");
}

void MetaEnumStreamer::stream(const QMetaEnum& metaEnum, QIODevice* device) {
    MetaEnumStreamer streamer(metaEnum);
    streamer.stream(device);
}

template<typename ...Tp>
void MetaEnumStreamer::writeData(QIODevice* device, Tp ... tp) const {
    ((device->write(tp), ...));
}

