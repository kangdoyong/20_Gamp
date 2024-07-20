#pragma once
#include "Object.h"
class Player :
    public Object
{
private:
	// �̵� �ӷ�
	int speed;
	// ������ ����
	float gunBarrelLength;
	// ���� ȸ�� ��, ����� ��
	float gunBarrelAngle;
	// ���� ���� ��ü�� ���� �Ѿ˸���Ʈ�� �ּҸ� ���� �ʵ�
	list<Object*>* bullets;

public:
	void SetBullets(list<Object*>* bullets)
	{
		this->bullets = bullets;
	}

private:
	template<typename T>
	Object* CreateBullet();

public:
	// Object��(��) ���� ��ӵ�
	void Initialize() override;
	void Update() override;
	void Render(HDC hdc) override;
	void Release() override;

	Player();
	virtual ~Player();
};


