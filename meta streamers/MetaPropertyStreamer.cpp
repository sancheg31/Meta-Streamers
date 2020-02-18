#include "MetaPropertyStreamer.h"


MetaPropertyStreamer::MetaPropertyStreamer(const QMetaProperty& p, const QString& prefix, const QString& suffix):
    IMetaStreamer(prefix, suffix), property(p) { }

void MetaPropertyStreamer::setProperty(const QMetaProperty& p) {
    if (property.name() == p.name() && property.type() == p.type() &&
        property.propertyIndex() == p.propertyIndex())
        return;
    property = p;
    emit propertyChanged();
}

const QMetaProperty& MetaPropertyStreamer::getProperty() const {
    return property;
}

void MetaPropertyStreamer::stream(QIODevice* device) const {
    writeData(device, "meta property streamer\n");
}

void MetaPropertyStreamer::stream(const QMetaProperty& property, QIODevice* device) {
    MetaPropertyStreamer streamer(property);
    streamer.stream(device);
}

