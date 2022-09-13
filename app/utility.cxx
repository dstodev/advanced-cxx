#include "utility.hxx"

#include <iostream>

#include <QStyleFactory>

namespace project {

void print_available_styles()
{
	std::cout << "Available styles:\n";
	for (auto const& key : QStyleFactory::keys()) {
		std::cout << key.toStdString() << '\n';
	}
	std::cout << std::endl;
}

}  // namespace project
