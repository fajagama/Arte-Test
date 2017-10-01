#include "Core.h"
#include <string>

int main(int argc, char **argv)
{
	Core c = Core("Objekt");

	for (size_t i = 0; i < 10; i++)
	{
		for (size_t y = 0; y < 10; y++)
		{
			c.addGameObject(GameObject(Transform(Position(i * 50, y * 50)), Renderer("carrot.png")));
		}
	}

	c.run();

	return 0;
}