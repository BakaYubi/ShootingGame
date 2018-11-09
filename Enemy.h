#pragma once
#include "GameObject.h"
class CEnemy :public CGameObject
{
	int deley = 0;
	int count = 0;
	int dir = 0;
public:
	CEnemy();
	~CEnemy();
	CEnemy(int x, int y, char *img) :CGameObject(x, y, img) {}

	void update();
};

