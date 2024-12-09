#ifndef ANIMATEDPOPUP_H
#define ANIMATEDPOPUP_H
// AnimatedPopup.h
#include <QWidget>
#include <QLabel>
#include <QPropertyAnimation>
#include <QVBoxLayout>
#include <QTimer>
#include <QScreen>
#include <QGuiApplication>

class AnimatedPopup : public QWidget {
    Q_OBJECT
    Q_PROPERTY(float opacity READ opacity WRITE setOpacity)

public:
    AnimatedPopup(const QString &message, QWidget *parent = nullptr) : QWidget(parent), m_opacity(1.0) {
        setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::Tool);
        setAttribute(Qt::WA_TranslucentBackground);

        QLabel *label = new QLabel(message, this);
        label->setAlignment(Qt::AlignCenter);
        label->setStyleSheet("QLabel { font-size: 24px; color: white; background-color: rgba(0, 0, 0, 200); padding: 15px; border-radius: 10px; border: 2px solid white; box-shadow: 0px 0px 15px rgba(0, 0, 0, 0.5); }");

        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(label);
        setLayout(layout);

        m_animation = new QPropertyAnimation(this, "opacity");
        m_animation->setDuration(1000);
        m_animation->setStartValue(0.0);
        m_animation->setEndValue(1.0);

        // Center the popup on the screen but move it slightly to the left
        QRect screenGeometry = QGuiApplication::primaryScreen()->geometry();
        int x = (screenGeometry.width() - this->width()) / 3; // Move to the left by setting x to a third of the screen width
        int y = (screenGeometry.height() - this->height()) / 2;
        setGeometry(x, y, 400, 200);  // Set the desired size for the popup

        // Auto close after 10 seconds
        QTimer::singleShot(10000, this, &QWidget::close);
    }

    void showAnimated() {
        show();
        m_animation->start();
    }

    float opacity() const { return m_opacity; }
    void setOpacity(float opacity) {
        m_opacity = opacity;
        setWindowOpacity(opacity);
    }

private:
    QPropertyAnimation *m_animation;
    float m_opacity;
};


#endif // ANIMATEDPOPUP_H
