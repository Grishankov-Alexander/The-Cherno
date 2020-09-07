#include <iostream>
#include <string>
#include <vector>

struct Vertex {
	float x, y, z;

	Vertex(float x, float y, float z)
		: x{ x }, y{ y }, z{ z }
	{}

	Vertex(const Vertex& v)
		: x{ v.x }, y{ v.y }, z{ v.z }
	{
		std::cout << "Vertex(const Vertex&) called!\n";
	}
};

std::ostream &operator<<(std::ostream &os, const Vertex &v)
{
	os << v.x << ", " << v.y << ", " << v.z << std::endl;
	return os;
}

void func(const std::vector<Vertex> &vec) {}

void part1()
{
	std::vector<Vertex> vertices;
	vertices.push_back(Vertex(1, 2, 3));
	vertices.push_back({ 4, 5, 6 });
	func(vertices);

	for (size_t i = 0; i < vertices.size(); ++i)
		std::cout << vertices[i];
	vertices.erase(vertices.end() - 1);
	for (const Vertex &v : vertices)
		std::cout << v;
}

void optimized()
{
	std::vector<Vertex> vertices;
	vertices.reserve(3);
	vertices.emplace_back(1, 2, 3);  // no copy construction
	vertices.emplace_back(4, 5, 6);
	vertices.emplace_back(7, 8, 9);
 }

int main(int argc, char *argv[])
{
	//part1();
	optimized();
}