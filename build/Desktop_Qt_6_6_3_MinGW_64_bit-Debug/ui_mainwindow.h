/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *mainmenu;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_10;
    QWidget *widget;
    QWidget *widget_7;
    QLabel *label;
    QLineEdit *id__ajout;
    QWidget *nom_ajout;
    QLabel *label_2;
    QLineEdit *lineNom;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLineEdit *tel_ajout;
    QWidget *widget_8;
    QLabel *label_4;
    QLineEdit *prix_ajout;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *adresse_ajout;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QLineEdit *email_ajout;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_9;
    QLineEdit *recus_ajout;
    QPushButton *pushButton;
    QPushButton *pushButtonsupprimer;
    QPushButton *pushButton_2;
    QWidget *widget_2;
    QTableView *tableView;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1232, 683);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        centralWidget->setStyleSheet(QString::fromUtf8("#widget{\n"
"background-color: qlineargradient(\n"
"        spread: pad,\n"
"        x1: 0, y1: 0,\n"
"        x2: 1, y2: 1,\n"
"        stop: 0 #3498db,  \n"
"        stop: 1 #2ecc71   \n"
"    );\n"
"}\n"
"#widget_2{\n"
"background-color: qlineargradient(\n"
"        spread: pad,\n"
"        x1: 0, y1: 0,\n"
"        x2: 1, y2: 1,\n"
"        stop: 0 #3498db,  \n"
"        stop: 1 #2ecc71   \n"
"    );\n"
"}\n"
"\n"
"\n"
"\n"
""));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        mainmenu = new QWidget(centralWidget);
        mainmenu->setObjectName("mainmenu");
        mainmenu->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_2 = new QVBoxLayout(mainmenu);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        widget_10 = new QWidget(mainmenu);
        widget_10->setObjectName("widget_10");
        widget = new QWidget(widget_10);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 20, 261, 551));
        widget->setMaximumSize(QSize(261, 16777215));
        widget_7 = new QWidget(widget);
        widget_7->setObjectName("widget_7");
        widget_7->setGeometry(QRect(11, 11, 239, 118));
        widget_7->setMaximumSize(QSize(240, 16777215));
        label = new QLabel(widget_7);
        label->setObjectName("label");
        label->setGeometry(QRect(11, 11, 101, 31));
        id__ajout = new QLineEdit(widget_7);
        id__ajout->setObjectName("id__ajout");
        id__ajout->setGeometry(QRect(107, 46, 131, 51));
        nom_ajout = new QWidget(widget);
        nom_ajout->setObjectName("nom_ajout");
        nom_ajout->setGeometry(QRect(10, 140, 240, 41));
        nom_ajout->setMaximumSize(QSize(240, 16777215));
        label_2 = new QLabel(nom_ajout);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(11, 11, 37, 20));
        lineNom = new QLineEdit(nom_ajout);
        lineNom->setObjectName("lineNom");
        lineNom->setGeometry(QRect(90, 10, 150, 26));
        widget_4 = new QWidget(widget);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(10, 200, 231, 61));
        widget_4->setMaximumSize(QSize(240, 16777215));
        horizontalLayout_5 = new QHBoxLayout(widget_4);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_3 = new QLabel(widget_4);
        label_3->setObjectName("label_3");

        horizontalLayout_5->addWidget(label_3);

        tel_ajout = new QLineEdit(widget_4);
        tel_ajout->setObjectName("tel_ajout");

        horizontalLayout_5->addWidget(tel_ajout);

        widget_8 = new QWidget(widget);
        widget_8->setObjectName("widget_8");
        widget_8->setGeometry(QRect(10, 370, 240, 81));
        widget_8->setMaximumSize(QSize(240, 16777215));
        label_4 = new QLabel(widget_8);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(11, 11, 81, 20));
        prix_ajout = new QLineEdit(widget_8);
        prix_ajout->setObjectName("prix_ajout");
        prix_ajout->setGeometry(QRect(70, 46, 150, 26));
        widget_5 = new QWidget(widget);
        widget_5->setObjectName("widget_5");
        widget_5->setGeometry(QRect(10, 250, 231, 61));
        widget_5->setMaximumSize(QSize(240, 16777215));
        horizontalLayout_6 = new QHBoxLayout(widget_5);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_6 = new QLabel(widget_5);
        label_6->setObjectName("label_6");

        horizontalLayout_6->addWidget(label_6);

        adresse_ajout = new QLineEdit(widget_5);
        adresse_ajout->setObjectName("adresse_ajout");

        horizontalLayout_6->addWidget(adresse_ajout);

        widget_6 = new QWidget(widget);
        widget_6->setObjectName("widget_6");
        widget_6->setGeometry(QRect(10, 310, 231, 61));
        widget_6->setMaximumSize(QSize(240, 16777215));
        horizontalLayout_8 = new QHBoxLayout(widget_6);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_8 = new QLabel(widget_6);
        label_8->setObjectName("label_8");

        horizontalLayout_8->addWidget(label_8);

        email_ajout = new QLineEdit(widget_6);
        email_ajout->setObjectName("email_ajout");

        horizontalLayout_8->addWidget(email_ajout);

        widget_9 = new QWidget(widget);
        widget_9->setObjectName("widget_9");
        widget_9->setGeometry(QRect(10, 460, 231, 41));
        widget_9->setMaximumSize(QSize(240, 16777215));
        horizontalLayout_9 = new QHBoxLayout(widget_9);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_9 = new QLabel(widget_9);
        label_9->setObjectName("label_9");

        horizontalLayout_9->addWidget(label_9);

        recus_ajout = new QLineEdit(widget_9);
        recus_ajout->setObjectName("recus_ajout");

        horizontalLayout_9->addWidget(recus_ajout);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(0, 510, 93, 29));
        pushButtonsupprimer = new QPushButton(widget);
        pushButtonsupprimer->setObjectName("pushButtonsupprimer");
        pushButtonsupprimer->setGeometry(QRect(90, 510, 91, 30));
        pushButtonsupprimer->setMinimumSize(QSize(0, 30));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(180, 510, 93, 29));
        widget_2 = new QWidget(widget_10);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(410, 10, 731, 351));
        widget_2->setMinimumSize(QSize(423, 0));
        widget_2->setMaximumSize(QSize(16777215, 16777215));
        tableView = new QTableView(widget_2);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(70, 30, 601, 300));
        tableView->setMaximumSize(QSize(16777215, 300));

        verticalLayout_2->addWidget(widget_10);


        horizontalLayout->addWidget(mainmenu);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1232, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestion des Clients", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Id fournisseur", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Nom ", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Telephone", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "prix produit", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "adresse", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "email", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "recus", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        pushButtonsupprimer->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
