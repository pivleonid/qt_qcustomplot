#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // генерируем данные
    QVector<double> x(360), y(360); // строить будем до 360 градусов
    for (int i=0; i<360; ++i)
    {
      x[i] = i;
      y[i] = 10*sin(x[i]*M_PI/180); // вычисляем синус
    }
    // создаем график и добавляем данные:
    ui->widget->addGraph();
    ui->widget->graph(0)->setData(x, y);
    // задаем имена осей координат
    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");
    // задаем размеры осей
    ui->widget->xAxis->setRange(0, 360);
    ui->widget->yAxis->setRange(-10, 10);
    ui->widget->replot();
}

MainWindow::~MainWindow()
{
    delete ui;
}
