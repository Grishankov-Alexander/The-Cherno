#include <iostream>
#include <algorithm>
#include <string>

struct Vector2
{
	float x, y;
};

struct Vector4
{
	union
	{
		struct
		{
			float x, y, z, w;
		};
		struct
		{
			Vector2 a, b;
		};
	};
};

void printVector2(const Vector2 &v)
{
	std::cout << v.x << ", " << v.y << '\n';
}


int main()
{
	union
	{
		int a;
		unsigned long long b;
		struct
		{
			double c;
		};
	};

	b = 0xff;
	std::cout << std::hex;
	std::cout << "a: " << a << '\n';
	std::cout << "b: " << b << '\n';
	std::cout << "c: " << c << '\n';

	std::cout << std::string(20, '-') << '\n';
	Vector4 v{ 1.0f, 2.0f, 3.0f, 4.0f };
	printVector2(v.a);
	printVector2(v.b);
	std::cout << std::string(20, '-') << '\n';
	v.z = 500;
	printVector2(v.a);
	printVector2(v.b);
}