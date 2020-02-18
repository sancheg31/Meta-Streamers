#include "IMetaStreamer.h"

IMetaStreamer::IMetaStreamer(const QString& pref, const QString& suf): QObject(), prefix(pref), suffix(suf) { }

void IMetaStreamer::setSuffix(const QString& s) {
    if (s != suffix) {
        suffix = s;
        emit suffixChanged();
    }
}

const QString& IMetaStreamer::getSuffix() const {
    return suffix;
}

void IMetaStreamer::setPrefix(const QString& p) {
    if (p != prefix) {
        prefix = p;
        emit prefixChanged();
    }
}

const QString& IMetaStreamer::getPrefix() const {
    return prefix;
}


