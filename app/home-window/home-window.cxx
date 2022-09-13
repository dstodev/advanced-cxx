#include <memory>

#include <QApplication>
#include <QGraphicsView>
#include <QGridLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QPushButton>

#include "home-window.hxx"
#include "quit-button/quit-button.hxx"
#include "scene/scene.hxx"

using namespace project;

HomeWindow::HomeWindow(QWidget* parent)
    : QWidget(parent)
    , _layout(new QHBoxLayout)
{
	setLayout(_layout);

	setFixedSize(720 * (2.0 / 3.0), 480 / 2);
	setWindowTitle("Something");

	// For a flexible data-interface architecture: https://doc.qt.io/qt-6/modelview.html
	auto* scene = new Scene(this);
	auto* scene_view = new QGraphicsView(scene);

	// Ampersand before letter: https://doc.qt.io/qt-6/qshortcut.html#mnemonic
	auto* reset = new QPushButton("&Reset");
	auto* quit = new QuitButton;

	auto* controls = new QGroupBox;
	controls->setTitle("Controls");

	auto* controls_layout = new QGridLayout;
	controls->setLayout(controls_layout);
	controls_layout->addWidget(reset);
	controls_layout->addWidget(quit);

	// addWidget() also sets the widget's parent to this
	_layout->addWidget(scene_view);
	_layout->addWidget(controls);

	connect(quit, &QuitButton::quit_confirmed, this, &QApplication::quit);
}
