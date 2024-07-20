#include "NormalBullet.h"

void NormalBullet::Initialize()
{
	info.sizeX = 25;
	info.sizeY = 25;
	speed = 10;
}

void NormalBullet::Update()
{
	info.posX += cosf(angle * PI / 180.f) * speed;
	info.posY += -sinf(angle * PI / 180.f) * speed;
}

void NormalBullet::Render(HDC hdc)
{
	Ellipse(hdc, info.posX - info.sizeX,
		info.posY - info.sizeY,
		info.posX + info.sizeX,
		info.posY + info.sizeY);
}

void NormalBullet::Release()
{
}

NormalBullet::NormalBullet()
{
}

NormalBullet::~NormalBullet()
{
}
