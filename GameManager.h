#pragma once
#include "GameMap.h"
#include "ObjectList.h"
#include "Plane.h"

class CGameManager
{
	CGameMap *m_gameMap;
	CPlane *m_plane;
	CObjectList *m_bulletList;
	CObjectList *m_enemyList;

	CGameManager();
public:
	~CGameManager();

	static CGameManager *getInstance();

	void init(CPlane *p, CGameMap *map, CObjectList *list, CObjectList *elist);
	
	CPlane *getPlane() { return m_plane; }
	CGameMap *getMap() { return m_gameMap; }
	CObjectList *getBulletList() { return m_bulletList; }
	CObjectList *getEnemyList() { return m_enemyList; }

	void checkCollision();

	void updataGame();
	void draw();
};

