#include <memory>

#include <QApplication>
#include <QGridLayout>
#include <QMessageBox>

#include "home-window.hxx"

using namespace project;

HomeWindow::HomeWindow(QWidget* parent)
    : QWidget(parent)
{
	setFixedSize(720, 480);
	setWindowTitle("Whoa!");

	// https://doc.qt.io/qt-6/qgridlayout.html
	_layout = new QGridLayout;  // QWidget will own layout, but useful to access from member
	setLayout(_layout);

	auto* quit = new QPushButton("&Quit");  // ampersand: https://doc.qt.io/qt-6/qshortcut.html#mnemonic
	_layout->addWidget(quit, 1, 0);

	auto* confirm = new QMessageBox(this);
	confirm->setText("Are you sure you want to quit?");
	confirm->setInformativeText("Are you reeaally sure?");
	confirm->setStandardButtons(QMessageBox::Yes | QMessageBox::No);  // Clicking Yes will emit accepted()
	confirm->setWindowTitle("Sureness Verifier");

	connect(quit, &QPushButton::clicked, confirm, &QMessageBox::exec);
	connect(confirm, &QMessageBox::accepted, QApplication::instance(), &QApplication::quit);

	auto* hello = new QPushButton("&Hello");
	_layout->addWidget(hello, 0, 0);
}
