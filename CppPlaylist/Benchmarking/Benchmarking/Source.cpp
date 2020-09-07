#include <iostream>
#include <memory>
#include <chrono>
#include <array>


class Timer
{
public:
	Timer()
		: t0{ std::chrono::steady_clock::now() }
	{}
	~Timer(){ stop(); }

	void stop();

private:
	std::chrono::steady_clock::time_point t0, t1;
};

struct Data
{
	float x, y;
};

void Timer::stop()
{
	t1 = std::chrono::steady_clock::now();
	auto ns = (t1 - t0).count();
	std::cout << ns << "ns (" << ns * 10e-6 << "ms)\n";
}


int main(int argc, char **argv)
{
	const size_t array_size = 99999;

	std::cout << "make_shared:\n";
	{
		auto arr = new std::array<std::shared_ptr<Data>, array_size>;
		Timer timer;
		for (size_t i = 0; i < array_size; ++i)
			(*arr)[i] = std::make_shared<Data>();
		delete arr;
	}

	std::cout << "new shared:\n";
	{
		auto arr = new std::array<std::shared_ptr<Data>, array_size>;
		Timer timer;
		for (size_t i = 0; i < array_size; ++i)
			(*arr)[i] = std::shared_ptr<Data>(new Data);
		delete arr;
	}

	std::cout << "make_unique:\n";
	{
		auto arr = new std::array<std::unique_ptr<Data>, array_size>;
		Timer timer;
		for (size_t i = 0; i < array_size; ++i)
			(*arr)[i] = std::make_unique<Data>();
		delete arr;
	}

	std::cin.get();
	return 0;
}