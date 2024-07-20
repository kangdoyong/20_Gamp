#pragma once
#include "Bullet.h"
class GuideBullet :
    public Bullet
{
private:
	Object* GetTarget();

public:
	// Bullet��(��) ���� ��ӵ�
	void Initialize() override;
	void Update() override;
	void Render(HDC hdc) override;
	void Release() override;

	GuideBullet();
	virtual ~GuideBullet();
};

