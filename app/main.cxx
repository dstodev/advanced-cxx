#include <QApplication>
#include <QStyleFactory>

#include "home-window.hxx"

#include "utility.hxx"

using namespace project;

int main(int argc, char** argv)
{
	// memdbg_preamble();  // TODO: suppress qt false-positives?

	QApplication app(argc, argv);
	QApplication::setStyle(QStyleFactory::create("Fusion"));

	// print_available_styles();

	HomeWindow home;
	home.show();

	QObject::connect(&home, SIGNAL(quit_confirmed()), &app, SLOT(exit()));

	return QApplication::exec();
}
