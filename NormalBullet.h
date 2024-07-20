#pragma once
#include "Bullet.h"
class NormalBullet :
    public Bullet
{
public:
	// Bullet을(를) 통해 상속됨
	void Initialize() override;
	void Update() override;
	void Render(HDC hdc) override;
	void Release() override;

	NormalBullet();
	virtual ~NormalBullet();
};

