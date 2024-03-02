#include <QFile>
#include <QDebug>

#include "..\include\MainWindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
	ui.setupUi(this);
	this->setupStyle();
	this->setWindowFlags(Qt::FramelessWindowHint);

	QPushButton* btn_close = findChild<QPushButton*>("btn_close");
	QPushButton* btn_minimize = findChild<QPushButton*>("btn_minimize");

	connect(btn_close, &QPushButton::clicked, this, &MainWindow::on_btn_close_clicked);
	connect(btn_minimize, &QPushButton::clicked, this, &MainWindow::on_btn_minimize_clicked);
}

void MainWindow::setupStyle()
{
	QString styleFilePath = "style/MainStyle.qss";

	try {
		QFile styleFile(styleFilePath);
		styleFile.open(QFile::ReadOnly);
		QString style = styleFile.readAll();
		qApp->setStyleSheet(style);
		styleFile.close();
	}
	catch (std::exception& ex) {

	}
}

void MainWindow::on_btn_close_clicked()
{
	this->close();
}

void MainWindow::on_btn_minimize_clicked()
{
	this->showMinimized();
}

MainWindow::~MainWindow()
{

}
