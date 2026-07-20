#include "Title.h"

int Title::Update()
{
	int ch;
	ch = _getche();

	if (ch == ' ')
	{
		return 1;
	}
	return 0;
}