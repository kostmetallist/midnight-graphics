#include "mainwindow.h"

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QSlider>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QCategoryAxis>
#include <cmath>

QT_CHARTS_USE_NAMESPACE


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QLineSeries *series = new QLineSeries();

    for (double x = 0; x <= 4; x += 0.1)
        *series << QPointF(x, sqrt(x));

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->setMinimumHeight(400.0);
    chart->setMinimumWidth(400.0);
    chart->addSeries(series);

    QPen curve_pen(QRgb(0x408383ff));
    curve_pen.setWidth(3);
    series->setPen(curve_pen);

    QFont chart_title_font;
    chart_title_font.setBold(true);
    chart_title_font.setPixelSize(12);
    chart->setTitleBrush(QBrush(Qt::white));
    chart->setTitleFont(chart_title_font);
    chart->setTitle("Plot");

    QLinearGradient background;
    background.setStart(QPointF(0, 0));
    background.setFinalStop(QPointF(0, 1));
    background.setColorAt(0.0,
        QRgb(COLOR_BACKGROUND_1));
    background.setColorAt(1.0,
        QRgb(COLOR_BACKGROUND_2));
    background.setCoordinateMode(QGradient::ObjectBoundingMode);
    chart->setBackgroundBrush(background);

    QCategoryAxis *axisX = new QCategoryAxis();
    QCategoryAxis *axisY = new QCategoryAxis();
    QFont axis_font;
    axis_font.setPixelSize(10);
    axisX->setLabelsFont(axis_font);
    axisX->setTitleText("X");
    axisY->setLabelsFont(axis_font);
    axisY->setTitleText("Y");

    QPen axis_pen(QRgb(0x10fcfcfc));
    axis_pen.setWidth(2);
    axisX->setLinePen(axis_pen);
    axisY->setLinePen(axis_pen);

    QBrush axisBrush(Qt::white);
    axisX->setLabelsBrush(axisBrush);
    axisY->setLabelsBrush(axisBrush);

    axisX->setLabelsPosition
            (QCategoryAxis::AxisLabelsPositionOnValue);
    axisY->setLabelsPosition
            (QCategoryAxis::AxisLabelsPositionOnValue);
    axisX->setGridLineVisible(true);
    axisY->setGridLineVisible(true);

    axisX->append("-2", -2);
    axisX->append("-1", -1);
    axisX->append("0", 0);
    axisX->append("1", 1);
    axisX->append("2", 2);
    axisX->append("3", 3);
    axisX->append("4", 4);
    axisX->setRange(-2, 4);

    axisY->append("0 ", 0);
    axisY->append("1 ", 1);
    axisY->append("2 ", 2);
    axisY->append("3 ", 3);
    axisY->append("4 ", 4);
    axisY->setRange(0, 4);

    chart->setAxisX(axisX, series);
    chart->setAxisY(axisY, series);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QHBoxLayout *main_layout = new QHBoxLayout();
    QVBoxLayout *chart_area = new QVBoxLayout();
    QVBoxLayout *settings_area = new QVBoxLayout();
    QLabel *func_label = new QLabel("Function:");
    QLineEdit *func_field = new QLineEdit();
    QLabel *diapx_label = new QLabel("X boundaries:");
    QLineEdit *diapx_field = new QLineEdit();
    QLabel *diapy_label = new QLabel("Y boundaries:");
    QLineEdit *diapy_field = new QLineEdit();
    QLabel *precision_label = new QLabel("Precision:");
    QSlider *precision_slider =
            new QSlider(Qt::Horizontal);
    QLabel *combobox_label = new QLabel("Color:");
    QComboBox *color_combobox = new QComboBox();
    QPushButton *go_button = new QPushButton("Generate");

    QWidget *central = new QWidget();

    central->setLayout(main_layout);
    func_field->setText("sqrt(x)");
    func_field->setPalette(Qt::gray);

    diapx_field->setText("-2;4");
    diapx_field->setPalette(Qt::gray);

    diapy_field->setText("0;4");
    diapy_field->setPalette(Qt::gray);

    precision_slider->
            setToolTip("Smaller amount of x's per segment will increase performance but reduce precision of curve");

    color_combobox->addItem("Blue");
    color_combobox->addItem("Red");
    color_combobox->addItem("Green");
    color_combobox->addItem("Yellow");
    color_combobox->setPalette(Qt::gray);

    go_button->setPalette(Qt::gray);

    chart_area->addWidget(chartView);
    settings_area->addWidget(func_label);
    settings_area->addWidget(func_field);
    settings_area->addWidget(diapx_label);
    settings_area->addWidget(diapx_field);
    settings_area->addWidget(diapy_label);
    settings_area->addWidget(diapy_field);
    settings_area->addWidget(precision_label);
    settings_area->addWidget(precision_slider);
    settings_area->addWidget(combobox_label);
    settings_area->addWidget(color_combobox);
    settings_area->addWidget(go_button);

    main_layout->addLayout(chart_area);
    main_layout->addLayout(settings_area);

    QMainWindow window;
    window.setCentralWidget(central);
    window.resize(600, 400);
    window.setWindowIcon(QIcon(":resources/iconfile/logo.ico"));
    window.setWindowTitle("Midnight Graphics v0.02");
    window.setPalette(Qt::black);
    window.setAutoFillBackground(true);
    window.show();

    return app.exec();
}
