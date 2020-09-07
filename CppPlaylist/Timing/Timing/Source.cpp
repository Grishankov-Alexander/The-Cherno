#include <chrono>
#include <thread>
#include <iostream>


struct Timer
{
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;

	Timer()
	{
		start = std::chrono::high_resolution_clock::now();
	}
	~Timer()
	{
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;
		std::cout << "Timer took " << duration.count() * 1000.0f << " ms\n";
	}
};

void func()
{
	Timer timer;

	std::this_thread::sleep_for(
		std::chrono::duration<int, std::milli>(100)
	);
}


int main(int argc, char **argv)
{
	func();

	return 0;
}