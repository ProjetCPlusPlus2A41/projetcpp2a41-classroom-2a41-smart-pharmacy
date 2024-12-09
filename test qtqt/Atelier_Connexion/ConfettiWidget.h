#ifndef CONFETTIWIDGET_H
#define CONFETTIWIDGET_H
#include <QWidget>
#include <QLabel>
#include <QPropertyAnimation>
#include <QTimer>
#include <QVBoxLayout>
#include <QTime>
#include <QWidget>
#include <QLabel>
#include <QPropertyAnimation>
#include <QTimer>
#include <QVBoxLayout>
#include <QTime>

class ConfettiWidget : public QWidget {
    Q_OBJECT

public:
    ConfettiWidget(QWidget *parent = nullptr) : QWidget(parent) {
        setAttribute(Qt::WA_TranslucentBackground);
        setGeometry(0, 0, parent->width(), parent->height());

        qsrand(static_cast<unsigned int>(QTime::currentTime().msec()));

        for (int i = 0; i < 50; ++i) {
            QLabel *confetti = new QLabel(this);
            confetti->setStyleSheet(QString("background-color: %1;").arg(randomColor().name()));
            confetti->setGeometry(randomPosition());

            QPropertyAnimation *animation = new QPropertyAnimation(confetti, "geometry");
            animation->setDuration(3000);
            animation->setStartValue(confetti->geometry());
            animation->setEndValue(QRect(confetti->x(), height(), 10, 10));
            animation->start(QAbstractAnimation::DeleteWhenStopped);
        }

        QTimer::singleShot(3000, this, &ConfettiWidget::close);
    }

private:
    QColor randomColor() {
        return QColor::fromHsv(qrand() % 360, 255, 255);
    }

    QRect randomPosition() {
        int x = qrand() % (width() - 10);
        int y = qrand() % (height() - 10);
        return QRect(x, y, 10, 10);
    }
};


#endif // CONFETTIWIDGET_H
