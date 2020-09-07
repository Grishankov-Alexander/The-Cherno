#include <iostream>

struct Entity
{
	int x, y;

	inline int *getXPos()
	{
		return &x;
	}
};

int main()
{
	int a = 50;
	double &b = *(double *)&a;
	// Dangerous: you will modify "a"
	// and adjacent 4 bytes.
	//b = 10;

	Entity e{ 5, 8 };
	int *pos = (int *)&e;
	std::cout << pos[0] << ", " << pos[1] << '\n';
	int *xPos = e.getXPos();
	// will modify y
	xPos[1] = 2;
	std::cout << e.y << '\n';

	int &y = *(int *)((char *)&e + 4);
	y = 8;
	std::cout << e.x << ", " << e.y << '\n';
}