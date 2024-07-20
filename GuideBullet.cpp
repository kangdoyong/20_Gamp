#include "GuideBullet.h"
#include "MainGame.h"
#include "MathUtil.h"

Object* GuideBullet::GetTarget()
{
	// 최소 거리를 담아둘 변수
	float minDistance = 1000.f;
	// 최소 거리를 갖는 객체를 담아둘 변수
	Object* target = nullptr;

	auto monsters = MainGame::monsters;

	for (auto i = monsters.begin(); i != monsters.end(); ++i)
	{
		// 총알과 각각의 몬스터 객체 사이의 거리를 구함
		float distance = MathUtil::GetDistance(this, *i);

		// 이전 연산에서 구했던 최소거리 보다 현재 구한 거리가 더 짧은지 확인
		if (distance < minDistance)
		{
			// 최소 거리를 갱신
			minDistance = distance;
			// 최소 거리를 갖는 몬스터 객체를 갱신
			target = *i;
		}
	}

	return target;
}

void GuideBullet::Initialize()
{
	info.sizeX = 25;
	info.sizeY = 25;
	speed = 4;
}

void GuideBullet::Update()
{
	// 총알과 가장 가까운 타겟을 찾음
	auto target = GetTarget();

	if (target == nullptr)
		return;

	// 타겟쪽을 향하는 각도를 구함
	float angle = MathUtil::GetAngle(target, this);

	// 구한 각도(방향)쪽으로 이동
	info.posX += cosf(angle * PI / 180.f) * speed;
	info.posY += -sinf(angle * PI / 180.f) * speed;
}

void GuideBullet::Render(HDC hdc)
{
	Ellipse(hdc, info.posX - info.sizeX,
		info.posY - info.sizeY,
		info.posX + info.sizeX,
		info.posY + info.sizeY);
}

void GuideBullet::Release()
{
}

GuideBullet::GuideBullet()
{
}

GuideBullet::~GuideBullet()
{
}
