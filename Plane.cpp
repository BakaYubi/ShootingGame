#include "Plane.h"
#include "Bullet.h"
#include "util.h"	// key 조작 사용
#include <conio.h>
#include "GameManager.h"

CPlane::~CPlane()
{
}

void CPlane::update()
{
	if (_kbhit())
	{
		int nKey = _getch();
		int planeX = getX();
		int planeY = getY();
		switch (nKey)
		{
		case LEFT:
			planeX--;
			break;
		case RIGHT:
			planeX++;
			break;
		case SPACE:
			CGameObject *bullet = new CBullet(planeX, planeY, "●");
			CGameManager::getInstance()->getBulletList()->pushTail(bullet);
			break;
		}
		int mapWidth = CGameManager::getInstance()->getMap()->getWidth();
		if (planeX >= 0 && planeX < mapWidth)
			setXY(planeX, planeY);
	}
}
