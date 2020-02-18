


#include "MetaObjectStreamer.h"
#include "VolumeHandler.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QIODevice* device = new QFile("D:/Projects/Qt/shadow-builds/test-application/output.txt");
    device->open(QIODevice::ReadWrite | QIODevice::Text);
    VolumeHandler* vh = new VolumeHandler;
    vh->show();
    MetaObjectStreamer::stream(vh, device);

    //qDebug() << vh->property("objectName");

    return app.exec();
}







