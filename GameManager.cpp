#include "GameManager.h"
#include "Bullet.h"
#include "Enemy.h"


CGameManager::CGameManager()
{
}


CGameManager::~CGameManager()
{
}

CGameManager * CGameManager::getInstance()
{
	static CGameManager instance;
	return & instance;
}

void CGameManager::init(CPlane * p, CGameMap * map, CObjectList * list, CObjectList *elist)
{
	m_plane = p;
	m_gameMap = map;
	m_bulletList = list;
	m_enemyList = elist;
}

#include "Bullet.h"
void CGameManager::checkCollision()
{
	int count = m_bulletList->getCount();
	for (int bi = 0; bi < count; bi++)
	{
		CGameObject *curBullet = m_bulletList->getObject(bi);

		int ecount = m_enemyList->getCount();
		for (int ei = 0; ei < ecount; ei++)
		{
			CGameObject *curEnemy = m_enemyList->getObject(ei);
			if (curEnemy->getY() == curBullet->getY() && curEnemy->getX() == curBullet->getX()) {
				m_enemyList->remove(ei);
				m_bulletList->remove(bi);
				break;
			}
		}
		if (curBullet->getY() < 0) {
			m_bulletList->remove(bi);
			break;
		}
	}
	// 醚舅 利 面倒贸府
	
}

void CGameManager::updataGame()
{
	m_plane->update();
	for (int i = 0; i < m_bulletList->getCount(); i++) {
		CBullet *curBullet = (CBullet *)m_bulletList->getObject(i);
		curBullet->update();
	}
	for (int i = 0; i < m_enemyList->getCount(); i++) {
		CEnemy *curEnemy = (CEnemy *)m_enemyList->getObject(i);
		curEnemy->update();
	}
	checkCollision();
}

void CGameManager::draw()
{
	m_plane->draw();
	int bNum = m_bulletList->getCount();
	for (int i = 0; i < bNum; i++) {
		m_bulletList->getObject(i)->draw();
	}
	int eNum = m_enemyList->getCount();
	for (int i = 0; i < eNum; i++) {
		m_enemyList->getObject(i)->draw();
	}
}
