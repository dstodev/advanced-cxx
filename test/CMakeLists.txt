add_subdirectory(etc)
add_subdirectory(link)
add_subdirectory(performance)
add_subdirectory(unit)

add_custom_target(all-test)
add_dependencies(all-test
	all-link
	all-unit
)

include(sample/targets.cmake)

add_subdirectory(flags)
