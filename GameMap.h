#pragma once
class CGameMap
{
	int m_width;
	int m_height;
public:
	~CGameMap(){}
	CGameMap(int w,int h):m_width(w),m_height(h){}
	
	int getWidth() { return m_width; }
	int getHeight() { return m_height; }
};

