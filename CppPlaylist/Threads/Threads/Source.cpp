#include <iostream>
#include <thread>

static bool is_finished = false;

void fib()
{
	using namespace std::literals::chrono_literals;

	std::cout << "Started fibonacci series computation "
		<< "in thread " << std::this_thread::get_id() << '\n';
	int a = 0, b = 1;
	while (!is_finished)
	{
		std::cout << a << '\n';
		auto temp = a;
		a = b;
		b = temp + b;
		std::this_thread::sleep_for(1s);
	}
	std::cout << "Finished thread "
		<< std::this_thread::get_id() << '\n';
}

int main(int argc, char **argv)
{
	std::cout << "Started main thread with id "
		<< std::this_thread::get_id() << '\n';

	std::thread fib_thread(&fib);
	std::cin.get();
	is_finished = true;
	fib_thread.join();

	std::cout << "Finished main thread with id "
		<< std::this_thread::get_id() << '\n';
	return 0;
}