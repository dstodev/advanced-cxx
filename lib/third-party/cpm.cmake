# This code is modified from: https://github.com/cpm-cmake/CPM.cmake/wiki/Downloading-CPM.cmake-in-CMake (as of 5/17/2023)

set(output_root "${PROJECT_BINARY_DIR}/cmake")

list(APPEND CMAKE_MODULE_PATH ${output_root})
list(APPEND CMAKE_PREFIX_PATH ${output_root})

set(output_path ${output_root}/CPM.cmake)
set(cpm_version 0.34.0)

if(NOT EXISTS ${output_path})
	message(STATUS "Downloading CPM.cmake to ${output_path}")
	file(DOWNLOAD https://github.com/TheLartians/CPM.cmake/releases/download/v0.38.1/CPM.cmake
		${output_path}
		TLS_VERIFY ON
	)
endif()

include(${output_path})