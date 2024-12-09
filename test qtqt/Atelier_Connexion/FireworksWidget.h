#ifndef FIREWORKSWIDGET_H
#define FIREWORKSWIDGET_H
// FireworksWidget.h
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include "FireworkParticle.h"

class FireworksWidget : public QGraphicsView {
    Q_OBJECT

public:
    FireworksWidget(QWidget *parent = nullptr) : QGraphicsView(parent) {
        setScene(new QGraphicsScene(this));
        setSceneRect(0, 0, parent->width(), parent->height());
        setAttribute(Qt::WA_TranslucentBackground);
        setStyleSheet("background: transparent;");
        setFrameStyle(QFrame::NoFrame);

        // Timer to create fireworks
        QTimer *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &FireworksWidget::createFirework);
        timer->start(500); // Create a firework every 500ms

        // Auto close after 5 seconds
        QTimer::singleShot(5000, this, &FireworksWidget::close);
    }

public slots:
    void createFirework() {
        for (int i = 0; i < 10; ++i) {
            QColor color = QColor::fromHsv(rand() % 360, 255, 255);
            FireworkParticle *particle = new FireworkParticle(rand() % int(sceneRect().width()), rand() % int(sceneRect().height()), 5, color, scene());
        }
    }
};

#endif // FIREWORKSWIDGET_H
