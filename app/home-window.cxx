#include <iostream>
#include <memory>

#include <QApplication>
#include <QGridLayout>
#include <QMessageBox>

#include "home-window.hxx"

using namespace project;

class ConfirmExit : public QMessageBox
{
	Q_OBJECT
public:
	explicit ConfirmExit(QWidget* parent = nullptr)
	    : QMessageBox(parent)
	{
		setText("Are you sure you want to exit?");
		setInformativeText("Are you reeaally sure?");
		QMessageBox::setWindowTitle("Sureness Verifier");
		setStandardButtons(QMessageBox::Yes | QMessageBox::No);
		connect(this, &QMessageBox::buttonClicked, this, &ConfirmExit::confirm_exit);
	}
	~ConfirmExit() override = default;

signals:
	void yesClicked();

private slots:
	void confirm_exit(QAbstractButton* selection)
	{
		auto button = standardButton(selection);
		if (button == QMessageBox::Yes) {
			emit yesClicked();
		}
	}
};

HomeWindow::HomeWindow(QWidget* parent)
    : QWidget(parent)
{
	setFixedSize(720, 480);
	setWindowTitle("Whoa!");

	// https://doc.qt.io/qt-6/qgridlayout.html
	_layout = new QGridLayout;  // QWidget will own layout, but useful to access from member
	setLayout(_layout);

	auto* quit = new QPushButton("&Quit");  // ampersand: https://doc.qt.io/qt-6/qshortcut.html#mnemonic
	_layout->addWidget(quit);

	auto* modal = new ConfirmExit(this);
	connect(quit, &QPushButton::clicked, modal, &QMessageBox::exec);
	connect(modal, &ConfirmExit::yesClicked, QApplication::instance(), &QApplication::quit);

	auto* hello = new QPushButton("&Hello");
	_layout->addWidget(hello);
}

#include "home-window.moc"
