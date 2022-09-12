#include <QApplication>
#include <QStyleFactory>

#include "home-window.hxx"

#include "utility.hxx"

using namespace project;

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	QApplication::setStyle(QStyleFactory::create("Fusion"));

	HomeWindow home;
	home.show();

	QObject::connect(&home, SIGNAL(quit_confirmed()), &app, SLOT(exit()));

	return QApplication::exec();
}
