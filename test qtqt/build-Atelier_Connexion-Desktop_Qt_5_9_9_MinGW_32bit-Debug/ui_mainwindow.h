/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_3;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;
    QFrame *frame_2;
    QLineEdit *lineEdit_39;
    QLineEdit *lineEdit_40;
    QLineEdit *lineEdit_41;
    QLineEdit *lineEdit_42;
    QLineEdit *lineEdit_43;
    QLineEdit *lineEdit_44;
    QLineEdit *prnom;
    QLineEdit *nom;
    QLineEdit *gender;
    QLineEdit *age;
    QLineEdit *mail;
    QLineEdit *nbrphone;
    QLineEdit *lineEdit_51;
    QLineEdit *lineEdit_52;
    QLabel *label_37;
    QLineEdit *lineEdit_53;
    QLineEdit *lineEdit_54;
    QPushButton *modifier;
    QPushButton *ajouter;
    QLabel *pdf_3;
    QLineEdit *lineEdit_73;
    QLineEdit *adresse;
    QLineEdit *cin;
    QFrame *frame_3;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_33;
    QLabel *label_34;
    QLabel *label_35;
    QLabel *label_36;
    QLabel *label_31;
    QLabel *label_32;
    QPushButton *ajouter_4;
    QWidget *page_3;
    QFrame *frame_4;
    QLabel *label_47;
    QLabel *label_48;
    QLabel *label_49;
    QLabel *label_50;
    QLabel *label_51;
    QLabel *label_52;
    QLabel *label_54;
    QPushButton *ajouter_5;
    QFrame *frame_5;
    QPushButton *supprimer;
    QTableView *tableView;
    QLineEdit *id;
    QLabel *label_53;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(974, 628);
        MainWindow->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(-90, 0, 291, 591));
        frame->setStyleSheet(QLatin1String("QFrame {\n"
"    background-color: white;\n"
"    width: 10px;\n"
"    border: 2px solid #00a388;\n"
"    border-radius: 15px;\n"
"}"));
        frame->setFrameShape(QFrame::NoFrame);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 220, 161, 41));
        label_2->setStyleSheet(QLatin1String("QFrame {\n"
"	background-color: rgb(68, 170, 148);\n"
"	background-color: #00a388;\n"
"    width: 10px;\n"
"    border: 2px solid #00a388;\n"
"    border-radius: 15px;\n"
"}\n"
"QLabel{\n"
"	\n"
"	font: 700 12pt \"Segoe UI\";\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
""));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 10, 111, 91));
        label->setStyleSheet(QStringLiteral("border-color: rgb(255, 255, 255);"));
        label->setPixmap(QPixmap(QString::fromUtf8("../../../image icon/image icon/WhatsApp Image 2024-10-20 \303\240 01.50.20_eeb96e69.jpg")));
        label->setScaledContents(true);
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(90, 160, 151, 41));
        label_4->setStyleSheet(QLatin1String("QFrame {\n"
"	background-color: white;\n"
"    width: 10px;\n"
"    border: 2px solid white;\n"
"    border-radius: 15px;\n"
"}\n"
"QLabel{\n"
"	\n"
"	font: 700 12pt \"Segoe UI\";\n"
"	color: black;\n"
"}\n"
""));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(90, 290, 151, 41));
        label_5->setStyleSheet(QLatin1String("QFrame {\n"
"	background-color: white;\n"
"    width: 10px;\n"
"    border: 2px solid white;\n"
"    border-radius: 15px;\n"
"}\n"
"QLabel{\n"
"	\n"
"	font: 700 12pt \"Segoe UI\";\n"
"	color: black;\n"
"}\n"
""));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(100, 350, 171, 41));
        label_6->setStyleSheet(QLatin1String("QFrame {\n"
"	background-color: white;\n"
"    width: 10px;\n"
"    border: 2px solid white;\n"
"    border-radius: 15px;\n"
"}\n"
"QLabel{\n"
"	\n"
"	font: 700 12pt \"Segoe UI\";\n"
"	color: black;\n"
"}\n"
""));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(90, 220, 51, 41));
        label_3->setPixmap(QPixmap(QString::fromUtf8("../pharmasoin/image icon/Male_patient_icon-removebg-preview (1).png")));
        label_3->setScaledContents(true);
        label_16 = new QLabel(frame);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(110, 90, 131, 51));
        label_16->setStyleSheet(QLatin1String("border-color: rgb(255, 255, 255);\n"
"border: 4px solid white;"));
        label_16->setPixmap(QPixmap(QString::fromUtf8("../../../image icon/image icon/Pharmasoin-20-10-2024.png")));
        label_16->setScaledContents(true);
        label_16->setWordWrap(false);
        label_17 = new QLabel(frame);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(100, 400, 171, 41));
        label_17->setStyleSheet(QLatin1String("QFrame {\n"
"	background-color: white;\n"
"    width: 10px;\n"
"    border: 2px solid white;\n"
"    border-radius: 15px;\n"
"}\n"
"QLabel{\n"
"	\n"
"	font: 700 12pt \"Segoe UI\";\n"
"	color: black;\n"
"}\n"
""));
        label_18 = new QLabel(frame);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(100, 450, 171, 41));
        label_18->setStyleSheet(QLatin1String("QFrame {\n"
"	background-color: white;\n"
"    width: 10px;\n"
"    border: 2px solid white;\n"
"    border-radius: 15px;\n"
"}\n"
"QLabel{\n"
"	\n"
"	font: 700 12pt \"Segoe UI\";\n"
"	color: black;\n"
"}\n"
""));
        label_19 = new QLabel(centralwidget);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(-8, 0, 991, 601));
        label_19->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/a0347ea5-2b67-4a59-8f79-3035b5b3f92b.jpg")));
        label_19->setScaledContents(true);
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(219, 9, 751, 561));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        frame_2 = new QFrame(page_2);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(20, 70, 671, 511));
        frame_2->setStyleSheet(QLatin1String("QFrame {\n"
"	background-color: rgb(202, 255, 193);\n"
"    background-color: white;\n"
"    width: 10px;\n"
"    border: 2px solid #00a388;\n"
"    border-radius: 15px;\n"
"}"));
        frame_2->setFrameShape(QFrame::NoFrame);
        lineEdit_39 = new QLineEdit(frame_2);
        lineEdit_39->setObjectName(QStringLiteral("lineEdit_39"));
        lineEdit_39->setGeometry(QRect(50, 120, 111, 20));
        lineEdit_39->setStyleSheet(QLatin1String("QLineEdit{\n"
"	 color:#00a388;\n"
"	font: 700 12pt \"Segoe UI\";\n"
"	\n"
"	;\n"
"}"));
        lineEdit_39->setFrame(false);
        lineEdit_40 = new QLineEdit(frame_2);
        lineEdit_40->setObjectName(QStringLiteral("lineEdit_40"));
        lineEdit_40->setGeometry(QRect(50, 170, 111, 20));
        lineEdit_40->setStyleSheet(QLatin1String("QLineEdit{\n"
"	 color:#00a388;\n"
"	font: 700 12pt \"Segoe UI\";\n"
"	\n"
"	;\n"
"}"));
        lineEdit_40->setFrame(false);
        lineEdit_41 = new QLineEdit(frame_2);
        lineEdit_41->setObjectName(QStringLiteral("lineEdit_41"));
        lineEdit_41->setGeometry(QRect(50, 220, 111, 20));
        lineEdit_41->setStyleSheet(QLatin1String("QLineEdit{\n"
"	 color:#00a388;\n"
"	font: 700 12pt \"Segoe UI\";\n"
"	\n"
"	;\n"
"}"));
        lineEdit_41->setFrame(false);
        lineEdit_42 = new QLineEdit(frame_2);
        lineEdit_42->setObjectName(QStringLiteral("lineEdit_42"));
        lineEdit_42->setGeometry(QRect(50, 270, 111, 20));
        lineEdit_42->setStyleSheet(QLatin1String("QLineEdit{\n"
"	 color:#00a388;\n"
"	font: 700 12pt \"Segoe UI\";\n"
"	\n"
"	;\n"
"}"));
        lineEdit_42->setFrame(false);
        lineEdit_43 = new QLineEdit(frame_2);
        lineEdit_43->setObjectName(QStringLiteral("lineEdit_43"));
        lineEdit_43->setGeometry(QRect(50, 320, 111, 20));
        lineEdit_43->setStyleSheet(QLatin1String("QLineEdit{\n"
"	 color:#00a388;\n"
"	font: 700 12pt \"Segoe UI\";\n"
"	\n"
"	;\n"
"}"));
        lineEdit_43->setFrame(false);
        lineEdit_44 = new QLineEdit(frame_2);
        lineEdit_44->setObjectName(QStringLiteral("lineEdit_44"));
        lineEdit_44->setGeometry(QRect(20, 370, 151, 20));
        lineEdit_44->setStyleSheet(QLatin1String("QLineEdit{\n"
"	 color:#00a388;\n"
"	font: 700 12pt \"Segoe UI\";\n"
"	\n"
"	;\n"
"}"));
        lineEdit_44->setFrame(false);
        prnom = new QLineEdit(frame_2);
        prnom->setObjectName(QStringLiteral("prnom"));
        prnom->setGeometry(QRect(180, 120, 131, 21));
        prnom->setStyleSheet(QLatin1String("QLineEdit {\n"
"	background-color: rgb(196, 255, 238);\n"
"    border: 2px solid  #00a388;; /* Bordure rose */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 2px;\n"
"}"));
        nom = new QLineEdit(frame_2);
        nom->setObjectName(QStringLiteral("nom"));
        nom->setGeometry(QRect(180, 170, 131, 21));
        nom->setStyleSheet(QLatin1String("QLineEdit {\n"
"	background-color: rgb(196, 255, 238);\n"
"    border: 2px solid  #00a388;; /* Bordure rose */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 2px;\n"
"}"));
        gender = new QLineEdit(frame_2);
        gender->setObjectName(QStringLiteral("gender"));
        gender->setGeometry(QRect(180, 220, 131, 21));
        gender->setStyleSheet(QLatin1String("QLineEdit {\n"
"	background-color: rgb(196, 255, 238);\n"
"    border: 2px solid  #00a388;; /* Bordure rose */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 2px;\n"
"}"));
        age = new QLineEdit(frame_2);
        age->setObjectName(QStringLiteral("age"));
        age->setGeometry(QRect(180, 270, 131, 21));
        age->setStyleSheet(QLatin1String("QLineEdit {\n"
"	background-color: rgb(196, 255, 238);\n"
"    border: 2px solid  #00a388;; /* Bordure rose */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 2px;\n"
"}"));
        mail = new QLineEdit(frame_2);
        mail->setObjectName(QStringLiteral("mail"));
        mail->setGeometry(QRect(180, 320, 131, 21));
        mail->setStyleSheet(QLatin1String("QLineEdit {\n"
"	background-color: rgb(196, 255, 238);\n"
"    border: 2px solid  #00a388;; /* Bordure rose */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 2px;\n"
"}"));
        nbrphone = new QLineEdit(frame_2);
        nbrphone->setObjectName(QStringLiteral("nbrphone"));
        nbrphone->setGeometry(QRect(180, 370, 131, 21));
        nbrphone->setStyleSheet(QLatin1String("QLineEdit {\n"
"	background-color: rgb(196, 255, 238);\n"
"    border: 2px solid  #00a388;; /* Bordure rose */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 2px;\n"
"}"));
        lineEdit_51 = new QLineEdit(frame_2);
        lineEdit_51->setObjectName(QStringLiteral("lineEdit_51"));
        lineEdit_51->setGeometry(QRect(430, 119, 181, 31));
        lineEdit_51->setStyleSheet(QLatin1String("QLineEdit{\n"
"	 color:#00a388;\n"
"	font: 700 12pt \"Segoe UI\";\n"
"	\n"
"	;\n"
"}"));
        lineEdit_51->setFrame(false);
        lineEdit_52 = new QLineEdit(frame_2);
        lineEdit_52->setObjectName(QStringLiteral("lineEdit_52"));
        lineEdit_52->setGeometry(QRect(440, 160, 171, 131));
        lineEdit_52->setStyleSheet(QLatin1String("QLineEdit {\n"
"	background-color:white;\n"
"    border: 2px solid  #00a388;; /* Bordure rose */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 2px;\n"
"}"));
        label_37 = new QLabel(frame_2);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setGeometry(QRect(470, 180, 101, 91));
        label_37->setStyleSheet(QStringLiteral("border-color: rgb(255, 255, 255);"));
        label_37->setPixmap(QPixmap(QString::fromUtf8("../pharmasoin/image icon/97ec0abf-3ba8-4ee5-99f5-cf02780b30aa.jpg")));
        label_37->setScaledContents(true);
        lineEdit_53 = new QLineEdit(frame_2);
        lineEdit_53->setObjectName(QStringLiteral("lineEdit_53"));
        lineEdit_53->setGeometry(QRect(450, 300, 151, 31));
        lineEdit_53->setStyleSheet(QLatin1String("QLineEdit{\n"
"	 color:#00a388;\n"
"	font: 700 12pt \"Segoe UI\";\n"
"	\n"
"	;\n"
"}"));
        lineEdit_53->setFrame(false);
        lineEdit_54 = new QLineEdit(frame_2);
        lineEdit_54->setObjectName(QStringLiteral("lineEdit_54"));
        lineEdit_54->setGeometry(QRect(440, 340, 171, 131));
        lineEdit_54->setStyleSheet(QLatin1String("QLineEdit {\n"
"	background-color:white;\n"
"    border: 2px solid  #00a388;; /* Bordure rose */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 2px;\n"
"}"));
        modifier = new QPushButton(frame_2);
        modifier->setObjectName(QStringLiteral("modifier"));
        modifier->setGeometry(QRect(180, 450, 121, 31));
        modifier->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: rgb(220, 72, 84);\n"
"	\n"
"    color: white; /* Texte blanc */\n"
"    border: none;\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 8px;\n"
"}"));
        ajouter = new QPushButton(frame_2);
        ajouter->setObjectName(QStringLiteral("ajouter"));
        ajouter->setGeometry(QRect(50, 450, 111, 31));
        ajouter->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: rgb(220, 72, 84);\n"
"	\n"
"    color: white; /* Texte blanc */\n"
"    border: none;\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 8px;\n"
"}"));
        pdf_3 = new QLabel(frame_2);
        pdf_3->setObjectName(QStringLiteral("pdf_3"));
        pdf_3->setGeometry(QRect(480, 360, 81, 81));
        pdf_3->setStyleSheet(QStringLiteral("border-color: rgb(255, 255, 255);"));
        pdf_3->setPixmap(QPixmap(QString::fromUtf8("../pharmasoin/image icon/File free icons designed by Freepik.jpg")));
        pdf_3->setScaledContents(true);
        lineEdit_73 = new QLineEdit(frame_2);
        lineEdit_73->setObjectName(QStringLiteral("lineEdit_73"));
        lineEdit_73->setGeometry(QRect(40, 410, 91, 20));
        lineEdit_73->setStyleSheet(QLatin1String("QLineEdit{\n"
"	 color:#00a388;\n"
"	font: 700 12pt \"Segoe UI\";\n"
"	\n"
"	;\n"
"}"));
        lineEdit_73->setFrame(false);
        adresse = new QLineEdit(frame_2);
        adresse->setObjectName(QStringLiteral("adresse"));
        adresse->setGeometry(QRect(180, 410, 131, 21));
        adresse->setStyleSheet(QLatin1String("QLineEdit {\n"
"	background-color: rgb(196, 255, 238);\n"
"    border: 2px solid  #00a388;; /* Bordure rose */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 2px;\n"
"}"));
        cin = new QLineEdit(frame_2);
        cin->setObjectName(QStringLiteral("cin"));
        cin->setGeometry(QRect(460, 210, 131, 21));
        cin->setStyleSheet(QLatin1String("QLineEdit {\n"
"	background-color: rgb(196, 255, 238);\n"
"    border: 2px solid  #00a388;; /* Bordure rose */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 2px;\n"
"}"));
        cin->raise();
        lineEdit_39->raise();
        lineEdit_40->raise();
        lineEdit_41->raise();
        lineEdit_42->raise();
        lineEdit_43->raise();
        lineEdit_44->raise();
        prnom->raise();
        nom->raise();
        gender->raise();
        age->raise();
        mail->raise();
        nbrphone->raise();
        lineEdit_51->raise();
        lineEdit_52->raise();
        label_37->raise();
        lineEdit_53->raise();
        lineEdit_54->raise();
        modifier->raise();
        ajouter->raise();
        pdf_3->raise();
        lineEdit_73->raise();
        adresse->raise();
        frame_3 = new QFrame(page_2);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(20, 0, 671, 61));
        frame_3->setStyleSheet(QLatin1String("QFrame {\n"
"    background-color: white;\n"
"    width: 10px;\n"
"    border: 2px solid #00a388;\n"
"    border-radius: 15px;\n"
"}"));
        frame_3->setFrameShape(QFrame::NoFrame);
        label_29 = new QLabel(frame_3);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(180, 10, 41, 41));
        label_29->setStyleSheet(QStringLiteral("border-color: rgb(255, 255, 255);"));
        label_29->setPixmap(QPixmap(QString::fromUtf8("../pharmasoin/image icon/liste.png")));
        label_29->setScaledContents(true);
        label_30 = new QLabel(frame_3);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(220, 10, 131, 20));
        label_30->setStyleSheet(QLatin1String("QFrame {\n"
"	background-color: white;\n"
"    width: 10px;\n"
"    border: 2px solid white;\n"
"    border-radius: 15px;\n"
"}\n"
"QLabel{\n"
"	\n"
"	font: 700 10pt \"Segoe UI\";\n"
"	color: black;\n"
"}\n"
""));
        label_33 = new QLabel(frame_3);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setGeometry(QRect(410, 20, 81, 20));
        label_33->setStyleSheet(QLatin1String("QFrame {\n"
"	background-color: white;\n"
"    width: 10px;\n"
"    border: 2px solid white;\n"
"    border-radius: 15px;\n"
"}\n"
"QLabel{\n"
"	\n"
"	font: 700 10pt \"Segoe UI\";\n"
"	color: black;\n"
"}\n"
""));
        label_34 = new QLabel(frame_3);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setGeometry(QRect(360, 10, 41, 41));
        label_34->setStyleSheet(QStringLiteral("border-color: rgb(255, 255, 255);"));
        label_34->setPixmap(QPixmap(QString::fromUtf8("../pharmasoin/image icon/5875.jpg")));
        label_34->setScaledContents(true);
        label_35 = new QLabel(frame_3);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setGeometry(QRect(510, 10, 41, 41));
        label_35->setStyleSheet(QStringLiteral("border-color: rgb(255, 255, 255);"));
        label_35->setPixmap(QPixmap(QString::fromUtf8("../pharmasoin/image icon/Calendar Green app icon.jpeg")));
        label_35->setScaledContents(true);
        label_36 = new QLabel(frame_3);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setGeometry(QRect(560, 20, 81, 20));
        label_36->setStyleSheet(QLatin1String("QFrame {\n"
"	background-color: white;\n"
"    width: 10px;\n"
"    border: 2px solid white;\n"
"    border-radius: 15px;\n"
"}\n"
"QLabel{\n"
"	\n"
"	font: 700 10pt \"Segoe UI\";\n"
"	color: black;\n"
"}\n"
""));
        label_31 = new QLabel(frame_3);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(44, 10, 121, 41));
        label_31->setStyleSheet(QLatin1String("QFrame {\n"
"	background-color: #00a388;\n"
"    width: 10px;\n"
"    border: 2px solid #00a388;\n"
"    border-radius: 15px;\n"
"}\n"
"QLabel{\n"
"	\n"
"	font: 700 9pt \"Segoe UI\";\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
""));
        label_32 = new QLabel(frame_3);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(10, 10, 41, 41));
        label_32->setStyleSheet(QLatin1String("border-color: rgb(255, 255, 255);\n"
"border: 4px solid white;"));
        label_32->setPixmap(QPixmap(QString::fromUtf8("../pharmasoin/image icon/plusclient.png")));
        label_32->setScaledContents(true);
        label_32->setWordWrap(false);
        ajouter_4 = new QPushButton(frame_3);
        ajouter_4->setObjectName(QStringLiteral("ajouter_4"));
        ajouter_4->setGeometry(QRect(220, 10, 121, 41));
        ajouter_4->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: rgb(220, 72, 84);\n"
"	\n"
"    color: white; /* Texte blanc */\n"
"    border: none;\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 8px;\n"
"}"));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        frame_4 = new QFrame(page_3);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setGeometry(QRect(20, 0, 671, 61));
        frame_4->setStyleSheet(QLatin1String("QFrame {\n"
"    background-color: white;\n"
"    width: 10px;\n"
"    border: 2px solid #00a388;\n"
"    border-radius: 15px;\n"
"}"));
        frame_4->setFrameShape(QFrame::NoFrame);
        label_47 = new QLabel(frame_4);
        label_47->setObjectName(QStringLiteral("label_47"));
        label_47->setGeometry(QRect(180, 10, 41, 41));
        label_47->setStyleSheet(QStringLiteral("border-color: rgb(255, 255, 255);"));
        label_47->setPixmap(QPixmap(QString::fromUtf8("../pharmasoin/image icon/liste.png")));
        label_47->setScaledContents(true);
        label_48 = new QLabel(frame_4);
        label_48->setObjectName(QStringLiteral("label_48"));
        label_48->setGeometry(QRect(220, 20, 131, 20));
        label_48->setStyleSheet(QLatin1String("QFrame {\n"
"	background-color: white;\n"
"    width: 10px;\n"
"    border: 2px solid white;\n"
"    border-radius: 15px;\n"
"}\n"
"QLabel{\n"
"	\n"
"	font: 700 10pt \"Segoe UI\";\n"
"	color: black;\n"
"}\n"
""));
        label_49 = new QLabel(frame_4);
        label_49->setObjectName(QStringLiteral("label_49"));
        label_49->setGeometry(QRect(410, 20, 81, 20));
        label_49->setStyleSheet(QLatin1String("QFrame {\n"
"	background-color: white;\n"
"    width: 10px;\n"
"    border: 2px solid white;\n"
"    border-radius: 15px;\n"
"}\n"
"QLabel{\n"
"	\n"
"	font: 700 10pt \"Segoe UI\";\n"
"	color: black;\n"
"}\n"
""));
        label_50 = new QLabel(frame_4);
        label_50->setObjectName(QStringLiteral("label_50"));
        label_50->setGeometry(QRect(360, 10, 41, 41));
        label_50->setStyleSheet(QStringLiteral("border-color: rgb(255, 255, 255);"));
        label_50->setPixmap(QPixmap(QString::fromUtf8("../pharmasoin/image icon/5875.jpg")));
        label_50->setScaledContents(true);
        label_51 = new QLabel(frame_4);
        label_51->setObjectName(QStringLiteral("label_51"));
        label_51->setGeometry(QRect(510, 10, 41, 41));
        label_51->setStyleSheet(QStringLiteral("border-color: rgb(255, 255, 255);"));
        label_51->setPixmap(QPixmap(QString::fromUtf8("../pharmasoin/image icon/Calendar Green app icon.jpeg")));
        label_51->setScaledContents(true);
        label_52 = new QLabel(frame_4);
        label_52->setObjectName(QStringLiteral("label_52"));
        label_52->setGeometry(QRect(560, 20, 81, 20));
        label_52->setStyleSheet(QLatin1String("QFrame {\n"
"	background-color: white;\n"
"    width: 10px;\n"
"    border: 2px solid white;\n"
"    border-radius: 15px;\n"
"}\n"
"QLabel{\n"
"	\n"
"	font: 700 10pt \"Segoe UI\";\n"
"	color: black;\n"
"}\n"
""));
        label_54 = new QLabel(frame_4);
        label_54->setObjectName(QStringLiteral("label_54"));
        label_54->setGeometry(QRect(10, 10, 41, 41));
        label_54->setStyleSheet(QLatin1String("border-color: rgb(255, 255, 255);\n"
"border: 4px solid white;"));
        label_54->setPixmap(QPixmap(QString::fromUtf8("../pharmasoin/image icon/plusclient.png")));
        label_54->setScaledContents(true);
        label_54->setWordWrap(false);
        ajouter_5 = new QPushButton(frame_4);
        ajouter_5->setObjectName(QStringLiteral("ajouter_5"));
        ajouter_5->setGeometry(QRect(40, 10, 121, 41));
        ajouter_5->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: rgb(220, 72, 84);\n"
"	\n"
"    color: white; /* Texte blanc */\n"
"    border: none;\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 8px;\n"
"}"));
        frame_5 = new QFrame(page_3);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setGeometry(QRect(20, 70, 671, 511));
        frame_5->setStyleSheet(QLatin1String("QFrame {\n"
"	background-color: rgb(202, 255, 193);\n"
"    background-color: white;\n"
"    width: 10px;\n"
"    border: 2px solid #00a388;\n"
"    border-radius: 15px;\n"
"}"));
        frame_5->setFrameShape(QFrame::NoFrame);
        supprimer = new QPushButton(frame_5);
        supprimer->setObjectName(QStringLiteral("supprimer"));
        supprimer->setGeometry(QRect(50, 450, 111, 31));
        supprimer->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: rgb(220, 72, 84);\n"
"	\n"
"    color: white; /* Texte blanc */\n"
"    border: none;\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 8px;\n"
"}"));
        tableView = new QTableView(frame_5);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(40, 70, 571, 351));
        id = new QLineEdit(frame_5);
        id->setObjectName(QStringLiteral("id"));
        id->setGeometry(QRect(510, 20, 91, 41));
        label_53 = new QLabel(frame_5);
        label_53->setObjectName(QStringLiteral("label_53"));
        label_53->setGeometry(QRect(460, 30, 41, 20));
        label_53->setStyleSheet(QLatin1String("QFrame {\n"
"	background-color: white;\n"
"    width: 10px;\n"
"    border: 2px solid white;\n"
"    border-radius: 15px;\n"
"}\n"
"QLabel{\n"
"	\n"
"	font: 700 10pt \"Segoe UI\";\n"
"	color: black;\n"
"}\n"
""));
        stackedWidget->addWidget(page_3);
        MainWindow->setCentralWidget(centralwidget);
        label_19->raise();
        frame->raise();
        stackedWidget->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 974, 27));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "               Patient", Q_NULLPTR));
        label->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "               Employee", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "               Product", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "            Prescription", Q_NULLPTR));
        label_3->setText(QString());
        label_16->setText(QString());
        label_17->setText(QApplication::translate("MainWindow", "            Supplier", Q_NULLPTR));
        label_18->setText(QApplication::translate("MainWindow", "            Delivery", Q_NULLPTR));
        label_19->setText(QString());
        lineEdit_39->setText(QApplication::translate("MainWindow", "First Name", Q_NULLPTR));
        lineEdit_40->setText(QApplication::translate("MainWindow", "Last Name", Q_NULLPTR));
        lineEdit_41->setText(QApplication::translate("MainWindow", "Gender", Q_NULLPTR));
        lineEdit_42->setText(QApplication::translate("MainWindow", "Age", Q_NULLPTR));
        lineEdit_43->setText(QApplication::translate("MainWindow", "Mail", Q_NULLPTR));
        lineEdit_44->setText(QApplication::translate("MainWindow", "Phone Number", Q_NULLPTR));
        lineEdit_51->setText(QApplication::translate("MainWindow", "          Upload Patient Image", Q_NULLPTR));
        label_37->setText(QString());
        lineEdit_53->setText(QApplication::translate("MainWindow", "Patients Data ", Q_NULLPTR));
        modifier->setText(QApplication::translate("MainWindow", "Confirm Update", Q_NULLPTR));
        ajouter->setText(QApplication::translate("MainWindow", "Confirm Add", Q_NULLPTR));
        pdf_3->setText(QString());
        lineEdit_73->setText(QApplication::translate("MainWindow", "Adresse", Q_NULLPTR));
        label_29->setText(QString());
        label_30->setText(QString());
        label_33->setText(QApplication::translate("MainWindow", "Statistics", Q_NULLPTR));
        label_34->setText(QString());
        label_35->setText(QString());
        label_36->setText(QApplication::translate("MainWindow", "Calender", Q_NULLPTR));
        label_31->setText(QApplication::translate("MainWindow", "     Add Patients", Q_NULLPTR));
        label_32->setText(QString());
        ajouter_4->setText(QApplication::translate("MainWindow", "List of Patients", Q_NULLPTR));
        label_47->setText(QString());
        label_48->setText(QApplication::translate("MainWindow", "List of Patients", Q_NULLPTR));
        label_49->setText(QApplication::translate("MainWindow", "Statistics", Q_NULLPTR));
        label_50->setText(QString());
        label_51->setText(QString());
        label_52->setText(QApplication::translate("MainWindow", "Calender", Q_NULLPTR));
        label_54->setText(QString());
        ajouter_5->setText(QApplication::translate("MainWindow", "Add Patient", Q_NULLPTR));
        supprimer->setText(QApplication::translate("MainWindow", "Delete", Q_NULLPTR));
        label_53->setText(QApplication::translate("MainWindow", "CIN", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
