add_google_executable(link-gtest TEST SOURCES gtest.cxx)
add_google_executable(link-benchmark TEST SOURCES benchmark.cxx BENCHMARK)
add_google_executable(link-eigen TEST SOURCES eigen.cxx LIBRARIES Eigen3::Eigen)
add_google_executable(link-sdl TEST SOURCES sdl.cxx LIBRARIES SDL2::SDL2)
add_google_executable(link-fmt TEST SOURCES fmt.cxx LIBRARIES fmt::fmt)

add_local_all_target(all-link)
