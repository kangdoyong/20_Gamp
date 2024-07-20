#pragma once
#include "Bullet.h"
class GuideBullet :
    public Bullet
{
private:
	Object* GetTarget();

public:
	// Bullet을(를) 통해 상속됨
	void Initialize() override;
	void Update() override;
	void Render(HDC hdc) override;
	void Release() override;

	GuideBullet();
	virtual ~GuideBullet();
};

