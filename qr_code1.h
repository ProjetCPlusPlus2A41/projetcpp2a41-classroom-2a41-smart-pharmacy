#ifndef QR_CODE1_H
#define QR_CODE1_H

#include <QString>
#include <QImage>

class QRCodeGenerator {
public:
    // Génère un QR Code sous forme d'image à partir de données
    QImage generateQRCode(const QString& data, int size = 300);

    // Génère et sauvegarde un QR Code à partir de données et d'un chemin de sortie
    bool generateQRCode(const QString& data, const QString& outputPath);
};

#endif // QR_CODE1_H
