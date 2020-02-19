#include "MetaPropertyStreamer.h"

#include "MetaEnumStreamer.h"
#include "MetaMethodStreamer.h"

MetaPropertyStreamer::MetaPropertyStreamer(const QMetaProperty& p, const QString& prefix, const QString& suffix):
    IMetaStreamer(prefix, suffix), property(p) {
    evaluateMacrosPresence();
}

void MetaPropertyStreamer::setProperty(const QMetaProperty& p) {
    if (property.name() == p.name() && property.type() == p.type() &&
        property.propertyIndex() == p.propertyIndex())
        return;
    property = p;
    evaluateMacrosPresence();
    emit propertyChanged();
}

const QMetaProperty& MetaPropertyStreamer::getProperty() const {
    return property;
}

/*virtual*/ void MetaPropertyStreamer::stream(QIODevice* device) const {
    writeData(device, prefix.toLocal8Bit().data(), "Property: ", suffix.toLocal8Bit().data(), "\n");
    writeData(device, "\t", prefix.toLocal8Bit().data(), "type: ", property.typeName(), suffix.toLocal8Bit().data(), "\n");
    writeData(device, "\t", prefix.toLocal8Bit().data(), "name: ", property.name(), suffix.toLocal8Bit().data(), "\n");
    if (property.isEnumType()) {
        writeData(device, "\t", prefix.toLocal8Bit().data(), "enum: ", suffix.toLocal8Bit().data(), "\n");
        MetaEnumStreamer::stream(property.enumerator(), device, prefix + "\t", suffix);
    }
    for (const auto & macros: macrosPresence) {
        if (macros.first)
            writeData(device, "\t", prefix.toLocal8Bit().data(), macros.second, suffix.toLocal8Bit().data(), "\n");
        qDebug() << "t" << prefix.toLocal8Bit().data() << "t" << macros.second << "t" << suffix.toLocal8Bit().data() << "t";
        if ((strcmp(macros.second, "NOTIFY") == 0) && macros.first == true) {
            MetaMethodStreamer::stream(property.notifySignal(), device, prefix + "\t", suffix);
        }
        qDebug() << "t" << prefix.toLocal8Bit().data() << "t" << macros.second << "t" << suffix.toLocal8Bit().data() << "t";
    }

}

/*static*/ void MetaPropertyStreamer::stream(const QMetaProperty& property, QIODevice* device,
                                             const QString& prefix, const QString& suffix) {
    MetaPropertyStreamer streamer(property, prefix, suffix);
    streamer.stream(device);
}

void MetaPropertyStreamer::evaluateMacrosPresence() {
    macrosPresence.clear();
    macrosPresence << QPair<bool, const char*>{property.isReadable(), "READ"}
                   << QPair<bool, const char*>{property.isWritable(), "WRITE"}
                   << QPair<bool, const char*>{property.isResettable(), "RESET"}
                   << QPair<bool, const char*>{property.notifySignalIndex()!=-1, "NOTIFY"}
                   << QPair<bool, const char*>{property.isConstant(), "CONSTANT"}
                   << QPair<bool, const char*>{property.isFinal(), "FINAL"}
                   << QPair<bool, const char*>{property.isDesignable(), "DESIGNABLE"}
                   << QPair<bool, const char*>{property.isScriptable(), "SCRIPTABLE"}
                   << QPair<bool, const char*>{property.revision(), "REVISION"};

}

