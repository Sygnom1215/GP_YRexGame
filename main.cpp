#include"Console.h"
#include"Run.h"


int main()
{
	int run = 1;
	srand((unsigned)time(NULL));
	openscreen();

	while (run)
	{
		obstaclemove();
		run = endscreen();
		score = 0;
	}

	return 0;
}