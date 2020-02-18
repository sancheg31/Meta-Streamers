#pragma once


class VolumeHandler: public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QLabel* value MEMBER value NOTIFY valueChanged)
public:
    VolumeHandler(QWidget* = nullptr);

private slots:
    void slotIncreaseVolume();
    void slotDecreaseVolume();
    void slotValueChanged(int);

signals:
    void valueChanged(int);

private:

    void setButtonSettings(QPushButton*) const;
    void setSliderSettings(QSlider*) const;
    void setLabelSettings(QLabel*) const;
    void setConnections() const;
    void createAndSetLayout();

    QLabel* value{nullptr};
    QTextEdit* text{nullptr};
    QPushButton* plus{nullptr};
    QPushButton* minus{nullptr};
    QSlider* slider{nullptr};
};

