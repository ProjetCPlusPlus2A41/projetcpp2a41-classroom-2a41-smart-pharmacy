#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    createBarChart();

}

Dialog::~Dialog()
{
    delete ui;
}
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlRecord>
#include <QtCharts>

void Dialog::createBarChart()
{
    // Query the database for product data (Make sure QTY is the correct column name)
    QSqlQuery query;
    query.prepare("SELECT NOM, QTY FROM PRODUITS");  // Adjust SQL as needed, QTY is the column for quantity

    if (!query.exec()) {
        qDebug() << "Error fetching data from PRODUITS:" << query.lastError().text();
        return;
    }

    // Create a bar series
    QBarSeries *series = new QBarSeries();

    // Initialize categories for X-axis (product names) and a bar set for Y-axis (quantities)
    QStringList categories;
    QBarSet *set_1 = new QBarSet("Product Quantities");

    // Variable to store the maximum quantity for dynamic Y-axis range
    int maxQuantity = 0;

    // Iterate over the query results to append data to the bar set
    while (query.next()) {
        QString productName = query.value("NOM").toString();
        int productQuantity = query.value("QTY").toInt(); // Fetch quantity

        // Add product name to categories for the X-axis
        categories.append(productName);

        // Append product quantity to the bar set
        set_1->append(productQuantity);

        // Update maxQuantity if the current product's quantity is greater than the previous max
        if (productQuantity > maxQuantity) {
            maxQuantity = productQuantity;
        }
    }

    // Append the set to the series
    series->append(set_1);

    // Create the chart
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Product Quantities");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // Set up the X-axis with the product names (categories)
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // Set up the Y-axis dynamically based on the maximum quantity
    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, maxQuantity + 10);  // Set a dynamic range based on the max value
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Configure the chart legend
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    // Create the chart view and set render hint for smooth rendering
    QChartView *chartview = new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);

    // Set the layout for the widget
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(chartview);

    // Set the chart view as the central widget
    this->setLayout(layout);
}

