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
	// 데이터를 입력할 때만 디그리로 사용
	// 이후 연산 시에는 라디안으로 변경
	gunBarrelAngle = 90;
}

void Player::Update()
{
	// 화살표 방향키 좌, 우는 포신 회전
	// 위, 아래는 탱크 전진/후진

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

	// Q 일반, W 회전, E 유도 총알
	
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
	// 탱크 몸통
	Ellipse(hdc, info.posX - info.sizeX, 
		info.posY - info.sizeY,
		info.posX + info.sizeX,
		info.posY + info.sizeY);

	// 탱크 포신
	// 직선 그리기 시작할 부분 (시작점) 지정
	MoveToEx(hdc, info.posX, info.posY, NULL);

	// 포신의 끝점을 연산
	// 포신의 길이를 통해 (길이/크기)를 표현
	// 방향을 표현하는 법을 모름
	int gbPosX = info.posX + cosf(gunBarrelAngle * PI / 180.f) * gunBarrelLength;
	int gbPosY = info.posY + -sinf(gunBarrelAngle * PI / 180.f) * gunBarrelLength;

	// 직선의 끝점을 지정
	LineTo(hdc, gbPosX, gbPosY);
}

void Player::Release()
{
}

template<typename T>
Object* Player::CreateBullet()
{
	// 포신에서부터 총알이 생성되도록 포신의 끝 부분 위치를
	// 구해서, 생성한 총알에 넘겨줌
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
