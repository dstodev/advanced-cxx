#include "utility.hxx"

#include <iostream>

#ifdef _MSC_VER
#define MSVC_MEMORY_CHECK
#endif
#ifdef MSVC_MEMORY_CHECK
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif

#include <QStyleFactory>

namespace project {

void memdbg_preamble()
{
#ifdef MSVC_MEMORY_CHECK
	// TODO: suppress qt false-positives?
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
#endif
}

void print_available_styles()
{
	std::cout << "Available styles:\n";
	for (auto const& key : QStyleFactory::keys()) {
		std::cout << key.toStdString() << '\n';
	}
	std::cout << std::endl;
}

}  // namespace project
