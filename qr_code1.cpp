#include "qr_code1.h"
#include <QPainter>
#include <QDir>
#include <QFileInfo>
#include <bitset>
QImage QRCodeGenerator::generateQRCode(const QString& data, int size) {
    const int gridSize = 21; // Exemple de QR Code simple avec une grille 21x21
    const int moduleSize = size / gridSize;

    QImage image(size, size, QImage::Format_ARGB32);
    image.fill(Qt::white);

    QPainter painter(&image);
    painter.setBrush(Qt::black);
    painter.setPen(Qt::NoPen);

    int x = 0, y = 0;
    for (QChar c : data) {
        std::bitset<8> bits(c.unicode());
        for (size_t i = 0; i < bits.size(); ++i) {
            if (bits[i]) {
                QRectF rect(x * moduleSize, y * moduleSize, moduleSize, moduleSize);
                painter.drawRect(rect);
            }
            ++x;
            if (x >= gridSize) {
                x = 0;
                ++y;
            }
            if (y >= gridSize) {
                break;
            }
        }
    }

    return image;
}

bool QRCodeGenerator::generateQRCode(const QString& data, const QString& outputPath) {
    if (data.isEmpty()) {
        return false;
    }

    QImage qrImage = generateQRCode(data);

    if (!outputPath.isEmpty()) {
        QDir dir = QFileInfo(outputPath).absoluteDir();
        if (!dir.exists()) {
            dir.mkpath("."); // Créer les répertoires si nécessaire
        }
        return qrImage.save(outputPath);
    }

    return false;
}
