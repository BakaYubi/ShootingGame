#include "Plane.h"
#include "GameMap.h"
#include "ObjectList.h"
#include "GameManager.h"
#include <time.h>
#include "util.h"
#include "Enemy.h"

void main()
{
	CGameMap *gameMap = new CGameMap(20, 20);
	CPlane *plane = new CPlane(10, 19, "бу");
	CObjectList *bulletList = new CObjectList();
	CObjectList *enemyList = new CObjectList();

	for (int i = 0; i < 5; i++) {
		int x = i * 3 + 6;
		CGameObject *enemy = new CEnemy(x, 2, "б┌");
		enemyList->pushTail(enemy);
	}

	CGameManager::getInstance()->init(plane, gameMap, bulletList, enemyList);

	int curTime, oldTime;
	oldTime = clock();
	ScreenInit();
	bool isContinue = true;
	while (isContinue) {
		ScreenClear();
		CGameManager::getInstance()->draw();
		ScreenFlipping();

		CGameManager::getInstance()->updataGame();
		while (1)
		{
			curTime = clock();
			if (curTime - oldTime > 33) {
				oldTime = curTime;
				break;
			}
		}
	}
	ScreenRelease();
}