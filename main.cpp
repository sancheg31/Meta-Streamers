


#include "MetaObjectStreamer.h"
#include "VolumeHandler.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QIODevice* device = new QFile("D:/Projects/Qt/shadow-builds/test-application/output.txt");
    device->open(QIODevice::ReadWrite | QIODevice::Text);
    MetaObjectStreamer::stream(new VolumeHandler, device);

    QWidget widget;
    widget.show();
    return app.exec();
}







