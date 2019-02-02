#include "mainwindow.h"
#include "../ui/ui_mainwindow.h"

#include <QtWidgets>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
	ui->setupUi(this);

    // connect(ui->detailsPushButton, &QPushButton::clicked,
    //    qApp, &SampleApp::doDetailsAction);
    connect(ui->detailsPushButton, &QPushButton::clicked,
        this, &MainWindow::detailsButtonPushed);

    connect(ui->listPushButton, &QPushButton::clicked,
        this, &MainWindow::listButtonPushed);

    auto quitAction = new QAction();
    quitAction->setShortcuts(QKeySequence::Quit);
    addAction(quitAction);
    connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::detailsButtonPushed()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::listButtonPushed()
{
    ui->stackedWidget->setCurrentIndex(0);
}
