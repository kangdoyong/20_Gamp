#include "Player.h"
#include "AbstractFactory.h"
#include "NormalBullet.h"
#include "RotateBullet.h"
#include "GuideBullet.h"

void Player::Initialize()
{
	info.posX = WIN_SIZE_X / 2;
	info.posY = WIN_SIZE_Y / 2;

	speed = 10;

	info.sizeX = 50;
	info.sizeY = 50;

	gunBarrelLength = 100;
	// �����͸� �Է��� ���� ��׸��� ���
	// ���� ���� �ÿ��� �������� ����
	gunBarrelAngle = 90;
}

void Player::Update()
{
	// ȭ��ǥ ����Ű ��, ��� ���� ȸ��
	// ��, �Ʒ��� ��ũ ����/����

	if (GetAsyncKeyState(VK_LEFT))
	{
		gunBarrelAngle += 10.f;
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{
		gunBarrelAngle -= 10.f;
	}

	if (GetAsyncKeyState(VK_UP))
	{
		info.posX += cosf(gunBarrelAngle * PI / 180.f) * speed;
		info.posY += -sinf(gunBarrelAngle * PI / 180.f) * speed;
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		info.posX -= cosf(gunBarrelAngle * PI / 180.f) * speed;
		info.posY -= -sinf(gunBarrelAngle * PI / 180.f) * speed;
	}

	// Q �Ϲ�, W ȸ��, E ���� �Ѿ�
	
	if (GetAsyncKeyState('Q'))
	{
		bullets->push_back(CreateBullet<NormalBullet>());
	}

	if (GetAsyncKeyState('W'))
	{
		bullets->push_back(CreateBullet<RotateBullet>());
	}

	if (GetAsyncKeyState('E'))
	{
		bullets->push_back(CreateBullet<GuideBullet>());
	}
}

void Player::Render(HDC hdc)
{
	// ��ũ ����
	Ellipse(hdc, info.posX - info.sizeX, 
		info.posY - info.sizeY,
		info.posX + info.sizeX,
		info.posY + info.sizeY);

	// ��ũ ����
	// ���� �׸��� ������ �κ� (������) ����
	MoveToEx(hdc, info.posX, info.posY, NULL);

	// ������ ������ ����
	// ������ ���̸� ���� (����/ũ��)�� ǥ��
	// ������ ǥ���ϴ� ���� ��
	int gbPosX = info.posX + cosf(gunBarrelAngle * PI / 180.f) * gunBarrelLength;
	int gbPosY = info.posY + -sinf(gunBarrelAngle * PI / 180.f) * gunBarrelLength;

	// ������ ������ ����
	LineTo(hdc, gbPosX, gbPosY);
}

void Player::Release()
{
}

template<typename T>
Object* Player::CreateBullet()
{
	// ���ſ������� �Ѿ��� �����ǵ��� ������ �� �κ� ��ġ��
	// ���ؼ�, ������ �Ѿ˿� �Ѱ���
	float x = info.posX + cosf(gunBarrelAngle * PI / 180.f) * gunBarrelLength;
	float y = info.posY + -sinf(gunBarrelAngle * PI / 180.f) * gunBarrelLength;

	Object* bullet = AbstractFactory<T>::CreateObject(x, y);
	((Bullet*)bullet)->SetAngle(gunBarrelAngle);
	
	return bullet;
}

Player::Player()
{
}

Player::~Player()
{
}
