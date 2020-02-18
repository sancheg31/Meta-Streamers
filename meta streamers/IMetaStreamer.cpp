#include "IMetaStreamer.h"

MetaStreamer::MetaStreamer(QString suf= "", QString pref = ""): QObject(), suffix(suf), prefix(pref) { }


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
