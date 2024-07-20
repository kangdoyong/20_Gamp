#include "Monster.h"

void Monster::Initialize()
{
	info.sizeX = 50;
	info.sizeY = 50;
}

void Monster::Update()
{
}

void Monster::Render(HDC hdc)
{
	Ellipse(hdc, info.posX - info.sizeX, info.posY - info.sizeY,
		info.posX + info.sizeX, info.posY + info.sizeY);
}

void Monster::Release()
{
}

Monster::Monster()
{
}

Monster::~Monster()
{
}
