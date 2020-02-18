#include "MetaObjectStreamer.h"

#include "MetaEnumStreamer.h"
#include "MetaMethodStreamer.h"
#include "MetaPropertyStreamer.h"

MetaObjectStreamer::MetaObjectStreamer(QObject* obj, const QString& pre, const QString& suf): IMetaStreamer(pre, suf), object(obj) { }

/*static*/ void MetaObjectStreamer::stream(QObject* object, QIODevice* device, const QString& prefix, const QString suffix) {
    MetaObjectStreamer streamer(object, prefix, suffix);
    streamer.stream(device);
}

/*virtual*/ void MetaObjectStreamer::stream(QIODevice* device) const {
    if (device->isOpen())
        device->close();

    device->open(QIODevice::Text | QIODevice::WriteOnly);
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



void MetaObjectStreamer::streamClassDetails(const QMetaObject* metaObject, QIODevice* device) const {
    const char* pref = prefix.toLocal8Bit().data();
    const char* suf = suffix.toLocal8Bit().data();
    writeData(device, pref, "class: ", metaObject->className(), suf, "\n");
    const QMetaObject* superClass = metaObject->superClass();
    if (superClass != nullptr) {
        writeData(device, pref, "superclass: ", superClass->className(), suf, "\n");
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
    if (object == obj)
        return;
    object = obj;
    emit objectChanged();
}

QObject* MetaObjectStreamer::getObject() const {
    return object;
}






