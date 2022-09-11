#include <memory>

#include <QApplication>
#include <QGridLayout>
#include <QMessageBox>
#include <QPushButton>
#include <QTableWidget>

#include "home-window.hxx"

using namespace project;

HomeWindow::HomeWindow(QWidget* parent)
    : QWidget(parent)
{
	setFixedSize(720 * (2.0 / 3.0), 480 / 2);
	setWindowTitle("Whoa!");

	// QWidget (base class) will own layout, but useful to access from member
	_layout = new QGridLayout;  // https://doc.qt.io/qt-6/qgridlayout.html
	setLayout(_layout);

	// For a more flexible table: https://doc.qt.io/qt-6/modelview.html
	auto* table = new QTableWidget;  // https://doc.qt.io/qt-6/qtablewidget.html
	_layout->addWidget(table);       // addWidget() also sets the widget's parent to this

	// ampersand before letter: https://doc.qt.io/qt-6/qshortcut.html#mnemonic
	auto* read = new QPushButton("Rea&d");  // https://doc.qt.io/qt-6/qpushbutton.html
	_layout->addWidget(read, 1, 0);

	auto* quit = new QPushButton("&Quit");
	_layout->addWidget(quit, 1, 1);

	auto* confirm = new QMessageBox(this);  // https://doc.qt.io/qt-6/qmessagebox.html
	confirm->setText("Are you sure you want to quit?");
	confirm->setInformativeText("Are you reeaally sure?");
	confirm->setStandardButtons(QMessageBox::Yes | QMessageBox::No);  // Clicking Yes will emit the accepted() signal
	confirm->setWindowTitle("Sureness Verifier");

	connect(quit, &QPushButton::clicked, confirm, &QMessageBox::exec);
	connect(confirm, &QMessageBox::accepted, this, &HomeWindow::quit_confirmed);
}
