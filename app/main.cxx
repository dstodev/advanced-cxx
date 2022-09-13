#include <QApplication>
#include <QStyleFactory>

#include "memdbg/preamble.h"  // introduces memory debug preprocessor code

#include "home-window/home-window.hxx"
#include "utility.hxx"

using namespace project;

int main(int argc, char** argv)
{
#include "memdbg/prelude.h"  // initializes memory debug facilities

	QApplication app(argc, argv);
	QApplication::setStyle(QStyleFactory::create("Fusion"));

	HomeWindow home;
	home.show();

	return QApplication::exec();
}
