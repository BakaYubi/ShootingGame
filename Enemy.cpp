#include "Enemy.h"



CEnemy::CEnemy()
{
}


CEnemy::~CEnemy()
{
}

void CEnemy::update()
{
	deley++;
	
	if (deley == 10)
	{
		deley = 0;
		if (count == 5) {
			count = 0;
			dir = !dir;
		}
		int x = getX();
		int y = getY();
		if (dir == 0)
			x--;
		else
			x++;
		setXY(x, y);
		count++;
	}
}
