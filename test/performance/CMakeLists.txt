add_google_executable(perf-project BENCHMARK
	SOURCES
		shear.cxx
		thread-pool.cxx

	LIBRARIES
		project

		Eigen3::Eigen
)

add_local_all_target(all-performance)
