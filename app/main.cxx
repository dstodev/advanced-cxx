#include <QApplication>
#include <QtWidgets>

#include "home-window.hxx"

#define MSVC_MEMORY_CHECK  // TODO: suppress qt false-positives?
#ifdef MSVC_MEMORY_CHECK
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif

using namespace project;

int main(int argc, char** argv)
{
#ifdef MSVC_MEMORY_CHECK
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
#endif
	QApplication app(argc, argv);

	HomeWindow home;
	home.show();

	return QApplication::exec();
}
