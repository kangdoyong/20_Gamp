#pragma once
#include "Bullet.h"
class NormalBullet :
    public Bullet
{
public:
	// Bullet��(��) ���� ��ӵ�
	void Initialize() override;
	void Update() override;
	void Render(HDC hdc) override;
	void Release() override;

	NormalBullet();
	virtual ~NormalBullet();
};

