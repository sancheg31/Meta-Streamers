#include "VolumeHandler.h"

VolumeHandler::VolumeHandler(QWidget* wgt): QWidget(wgt) {
    minus = new QPushButton("-");
    plus = new QPushButton("+");
    slider = new QSlider(Qt::Horizontal);
    value = new QLabel("100");
    text = new QTextEdit("");
    setButtonSettings(minus);
    setButtonSettings(plus);
    setSliderSettings(slider);
    setLabelSettings(value);
    setConnections();
    createAndSetLayout();

    resize(200, 200);
}

void VolumeHandler::slotIncreaseVolume() {
    slider->setValue(slider->value() + slider->pageStep());
}

void VolumeHandler::slotDecreaseVolume() {
    slider->setValue(slider->value() - slider->pageStep());
}

void VolumeHandler::slotValueChanged(int val) {
    if (val > text->font().pointSize()) {
        text->zoomIn(val - text->font().pointSize());
    } else {
        text->zoomOut(text->font().pointSize() - val);
    }
    value->setText(QString::number(val) + "%");
}


void VolumeHandler::setButtonSettings(QPushButton* button) const {
    QFrame frame;
    frame.setFrameStyle(QFrame::Box | QFrame::Plain);
    button->setStyle(frame.style());
    button->setFlat(true);
    button->setFixedSize(30, 30);
}

void VolumeHandler::setSliderSettings(QSlider* slider) const {
    slider->setRange(0, 200);
    slider->setValue(100);
    slider->setSingleStep(5);
    slider->setPageStep(20);
    slider->setFixedHeight(30);
    slider->setMinimumWidth(450);
}

void VolumeHandler::setLabelSettings(QLabel* label) const {
    label->setFrameStyle(QFrame::Box | QFrame::Plain);
    label->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
    label->setFixedHeight(30);
    label->setMinimumWidth(450);
}

void VolumeHandler::setConnections() const {
    bool ok = true;
    ok &= (bool) QObject::connect(minus, &QPushButton::clicked, this, &VolumeHandler::slotDecreaseVolume);
    ok &= (bool) QObject::connect(plus, &QPushButton::clicked, this, &VolumeHandler::slotIncreaseVolume);
    ok &= (bool) QObject::connect(slider, &QSlider::valueChanged, this, &VolumeHandler::slotValueChanged);
    ok &= (bool) QObject::connect(slider, SIGNAL(valueChanged(int)), this, SLOT(slotValueChanged(int)));
    Q_ASSERT(ok);
}

void VolumeHandler::createAndSetLayout() {

    QGridLayout* l = new QGridLayout();
    l->addWidget(text, 0, 0, 5, 7);
    l->addWidget(value, 5, 1, 1, 5);
    l->addWidget(minus, 6, 0, 1, 1);
    l->addWidget(slider, 6, 1, 1, 5);
    l->addWidget(plus, 6, 6, 1, 1);
    l->setSpacing(15);
    l->setMargin(5);
    setLayout(l);
}


