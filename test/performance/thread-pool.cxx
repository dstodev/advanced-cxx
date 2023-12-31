#include <benchmark/benchmark.h>

#include <thread-pool.hxx>

using namespace project;

static void count_single_threaded(benchmark::State& state)
{
	int const num_tasks = 1000;

	for (auto _ : state) {
		int count = 0;

		for (int i {}; i < num_tasks; ++i) {  // loop may be optimized away
			count += (i + 1);
		}

		(void) count;
	}
}

static void count_single_threaded_volatile(benchmark::State& state)
{
	int const num_tasks = 1000;

	for (auto _ : state) {
		volatile int count = 0;  // volatile prevents compiler from optimizing away the loop

		for (int i {}; i < num_tasks; ++i) {
			count += (i + 1);
		}

		(void) count;
	}
}

static void count_single_threaded_atomic(benchmark::State& state)
{
	int const num_tasks = 1000;

	for (auto _ : state) {
		volatile std::atomic_int count = 0;

		for (int i {}; i < num_tasks; ++i) {
			count += (i + 1);
		}

		(void) count;
	}
}

static void count_multithreaded(benchmark::State& state)
{
	int const num_tasks = 1000;

	for (auto _ : state) {
		ThreadPool pool(state.range(0));
		volatile std::atomic_int count = 0;

		for (int i {}; i < num_tasks; ++i) {
			pool.add_task([&count, i]() { count += (i + 1); });
		}

		(void) count;
	}
}

static void count_multithreaded_initialized(benchmark::State& state)
{
	int const num_tasks = 1000;

	ThreadPool pool(state.range(0));

	for (auto _ : state) {
		volatile std::atomic_int count = 0;

		for (int i {}; i < num_tasks; ++i) {
			pool.add_task([&count, i]() { count += (i + 1); });
		}

		pool.wait();

		(void) count;
	}
}

// clang-format off

BENCHMARK(count_single_threaded);
BENCHMARK(count_single_threaded_volatile);
BENCHMARK(count_single_threaded_atomic);

BENCHMARK(count_multithreaded)
    ->RangeMultiplier(2)
    ->Range(1, 2 << 4)
    ->Unit(benchmark::kMillisecond)
    ->Iterations(1000);

BENCHMARK(count_multithreaded_initialized)
    ->RangeMultiplier(2)
    ->Range(1, 2 << 4)
    ->Unit(benchmark::kMillisecond)
    ->Iterations(1000);

// clang-format on
