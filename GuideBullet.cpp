#include "GuideBullet.h"
#include "MainGame.h"
#include "MathUtil.h"

Object* GuideBullet::GetTarget()
{
	// �ּ� �Ÿ��� ��Ƶ� ����
	float minDistance = 1000.f;
	// �ּ� �Ÿ��� ���� ��ü�� ��Ƶ� ����
	Object* target = nullptr;

	auto monsters = MainGame::monsters;

	for (auto i = monsters.begin(); i != monsters.end(); ++i)
	{
		// �Ѿ˰� ������ ���� ��ü ������ �Ÿ��� ����
		float distance = MathUtil::GetDistance(this, *i);

		// ���� ���꿡�� ���ߴ� �ּҰŸ� ���� ���� ���� �Ÿ��� �� ª���� Ȯ��
		if (distance < minDistance)
		{
			// �ּ� �Ÿ��� ����
			minDistance = distance;
			// �ּ� �Ÿ��� ���� ���� ��ü�� ����
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
	// �Ѿ˰� ���� ����� Ÿ���� ã��
	auto target = GetTarget();

	if (target == nullptr)
		return;

	// Ÿ������ ���ϴ� ������ ����
	float angle = MathUtil::GetAngle(target, this);

	// ���� ����(����)������ �̵�
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
