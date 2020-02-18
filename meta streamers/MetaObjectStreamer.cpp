#include "MetaObjectStreamer.h"




MetaObjectStreamer::MetaObjectStreamer(QObject* obj, const QString& pre, const QString& suf):
    object(obj), prefix(pre), suffix(suf) { }


/*static*/ void MetaObjectStreamer::stream(QObject* object, QIODevice* device, const QString& prefix, const QString suffix) {
    MetaObjectStreamer streamer(object, prefix, suffix);
    streamer.stream(device);
}

void MetaObjectStreamer::stream(QIODevice* device) const {
    if (device->isOpen())
        device->close();

    device->open(QIODevice::OpenModeFlag::Text | QIODevice::OpenModeFlag::WriteOnly);
    if (!device->isOpen())
        return;

    const QMetaObject* metaObject = object->metaObject();
    streamClassDetails(metaObject, device);
    streamClassInfo(metaObject, device);
    streamProperties(metaObject, device);
    streamMethods(metaObject, device);
    streamEnums(metaObject, device);

    device->close();
}

template<typename ...Tp>
void MetaObjectStreamer::writeData(QIODevice* device, Tp ... tp) const {
    ((device->write(tp), ...));
}

void MetaObjectStreamer::streamClassDetails(const QMetaObject* metaObject, QIODevice* device) const {
    writeData(device, "class: ", metaObject->className(), "\n");
    const QMetaObject* superClass = metaObject->superClass();
    if (superClass != nullptr) {
        writeData(device, "superclass: ", superClass->className(), "\n");
    }
}

void MetaObjectStreamer::streamMethods(const QMetaObject* metaObject, QIODevice* device) const {
    for (int i = metaObject->methodOffset(); i < metaObject->methodCount(); ++i)
        MetaMethodStreamer::stream(metaObject->method(i), device);
}

void MetaObjectStreamer::streamProperties(const QMetaObject* metaObject, QIODevice* device) const {
    for (int i = metaObject->propertyOffset(); i < metaObject->propertyCount(); ++i)
        MetaPropertyStreamer::stream(metaObject->property(i), device);
}

void MetaObjectStreamer::streamEnums(const QMetaObject* metaObject, QIODevice* device) const {
    for (int i = metaObject->enumeratorOffset(); i < metaObject->enumeratorCount(); ++i)
        MetaEnumStreamer::stream(metaObject->enumerator(i), device);
}

void MetaObjectStreamer::streamClassInfo(const QMetaObject* metaObject, QIODevice* device) const {
    for (int i = metaObject->classInfoOffset(); i < metaObject->classInfoCount(); ++i);
}


void MetaObjectStreamer::setObject(QObject* obj) {
    if (object.data() != obj) {
        object.take();
        object.reset(obj);
        emit objectChanged();
    }
}

QObject* MetaObjectStreamer::getObject() const {
    return object.data();
}

void MetaObjectStreamer::setSuffix(const QString& s) {
    if (s != suffix) {
        suffix = s;
        emit suffixChanged();
    }
}

const QString& MetaObjectStreamer::getSuffix() const {
    return suffix;
}

void MetaObjectStreamer::setPrefix(const QString& p) {
    if (p != prefix) {
        prefix = p;
        emit prefixChanged();
    }
}

const QString& MetaObjectStreamer::getPrefix() const {
    return prefix;
}




