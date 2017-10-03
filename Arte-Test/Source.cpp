#include "Core.h"
#include <string>
#include <crtdbg.h>

int main(int argc, char **argv)
{
	{
		Core c = Core("Objekt");

		for (size_t i = 0; i < 1; i++)
		{
			for (size_t y = 0; y < 1; y++)
			{
				c.addGameObject(GameObject(Transform(Position(i * 50, y * 50)), Renderer("carrot.png")));
			}
		}

		c.run();

		_CrtDumpMemoryLeaks();
	}
	_CrtDumpMemoryLeaks();
	return 0;
}