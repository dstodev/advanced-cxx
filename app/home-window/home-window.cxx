#include <memory>

#include <QApplication>
#include <QGridLayout>
#include <QGroupBox>
#include <QHeaderView>
#include <QPushButton>
#include <QTableWidget>

#include "home-window.hxx"
#include "quit-button/quit-button.hxx"

using namespace project;

HomeWindow::HomeWindow(QWidget* parent)
    : QWidget(parent)
    , _layout(new QHBoxLayout)
{
	setLayout(_layout);

	setFixedSize(720 * (2.0 / 3.0), 480 / 2);
	setWindowTitle("Whoa!");

	// For a more flexible table: https://doc.qt.io/qt-6/modelview.html
	auto* table = new QTableWidget(4, 3);
	table->setItem(0, 0, new QTableWidgetItem("Item"));

	auto* table_header = table->horizontalHeader();
	table_header->setSectionResizeMode(QHeaderView::Stretch);

	// Ampersand before letter: https://doc.qt.io/qt-6/qshortcut.html#mnemonic
	auto* read = new QPushButton("Rea&d");
	auto* quit = new QuitButton;

	auto* controls = new QGroupBox;
	controls->setTitle("Controls");

	auto* controls_layout = new QGridLayout;
	controls->setLayout(controls_layout);
	controls_layout->addWidget(read);
	controls_layout->addWidget(quit);

	// addWidget() also sets the widget's parent to this
	_layout->addWidget(table);
	_layout->addWidget(controls);

	connect(quit, &QuitButton::quit_confirmed, this, &HomeWindow::quit_confirmed);
}
