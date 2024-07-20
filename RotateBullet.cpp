#include "RotateBullet.h"

void RotateBullet::Initialize()
{
	info.sizeX = 10;
	info.sizeY = 10;
	speed = 1;
	rotAngle = 0;

	isFire = false;
}

void RotateBullet::Update()
{
	if (!isFire)
	{
		// 가상의 점의 위치를 포신의 끝 부분으로 처음 한 번 설정
		isFire = true;
		rotCenterX = info.posX;
		rotCenterY = info.posY;
	}

	// 발사 시점의 포신의 방향대로 가상의 점을 이동시킴
	rotCenterX += cosf(angle * PI / 180.f) * speed;
	rotCenterY += -sinf(angle * PI / 180.f) * speed;

	// 가상의 점을 기준으로 총알을 회전 시킴
	info.posX = rotCenterX + cosf(rotAngle * PI / 180.f) * 10.f;
	info.posY = rotCenterY + -sinf(rotAngle * PI / 180.f) * 10.f;

	// 가상의 점을 기준으로 총알이 계속해서 회전할 수 있도록
	// rotAngle에 임의의 각을 더 함
	rotAngle += 10.f;
}

void RotateBullet::Render(HDC hdc)
{
	Ellipse(hdc, info.posX - info.sizeX,
		info.posY - info.sizeY,
		info.posX + info.sizeX,
		info.posY + info.sizeY);
}

void RotateBullet::Release()
{
}

RotateBullet::RotateBullet()
{
}

RotateBullet::~RotateBullet()
{
}
