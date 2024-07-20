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
		// ������ ���� ��ġ�� ������ �� �κ����� ó�� �� �� ����
		isFire = true;
		rotCenterX = info.posX;
		rotCenterY = info.posY;
	}

	// �߻� ������ ������ ������ ������ ���� �̵���Ŵ
	rotCenterX += cosf(angle * PI / 180.f) * speed;
	rotCenterY += -sinf(angle * PI / 180.f) * speed;

	// ������ ���� �������� �Ѿ��� ȸ�� ��Ŵ
	info.posX = rotCenterX + cosf(rotAngle * PI / 180.f) * 10.f;
	info.posY = rotCenterY + -sinf(rotAngle * PI / 180.f) * 10.f;

	// ������ ���� �������� �Ѿ��� ����ؼ� ȸ���� �� �ֵ���
	// rotAngle�� ������ ���� �� ��
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
