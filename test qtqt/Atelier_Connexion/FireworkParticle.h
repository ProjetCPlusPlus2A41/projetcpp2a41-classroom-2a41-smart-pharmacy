#ifndef FIREWORKPARTICLE_H
#define FIREWORKPARTICLE_H
// FireworkParticle.h
#include <QGraphicsEllipseItem>
#include <QPropertyAnimation>
#include <QGraphicsScene>

class FireworkParticle : public QObject, public QGraphicsEllipseItem {
    Q_OBJECT
    Q_PROPERTY(qreal opacity READ opacity WRITE setOpacity)

public:
    FireworkParticle(qreal x, qreal y, qreal size, QColor color, QGraphicsScene *scene) {
        setRect(x, y, size, size);
        setBrush(color);
        setOpacity(1.0);
        scene->addItem(this);

        // Animation for the particle
        QPropertyAnimation *animation = new QPropertyAnimation(this, "opacity");
        animation->setDuration(1000 + rand() % 1000);
        animation->setStartValue(1.0);
        animation->setEndValue(0.0);
        animation->setEasingCurve(QEasingCurve::OutQuad);
        connect(animation, &QPropertyAnimation::finished, this, &FireworkParticle::deleteLater);

        // Movement animation
        QPropertyAnimation *moveAnimation = new QPropertyAnimation(this, "pos");
        moveAnimation->setDuration(1000 + rand() % 1000);
        moveAnimation->setStartValue(pos());
        moveAnimation->setEndValue(pos() + QPointF((rand() % 200 - 100), (rand() % 200 - 100)));
        moveAnimation->setEasingCurve(QEasingCurve::OutQuad);

        // Start animations
        animation->start(QPropertyAnimation::DeleteWhenStopped);
        moveAnimation->start(QPropertyAnimation::DeleteWhenStopped);
    }
};

#endif // FIREWORKPARTICLE_H
