#pragma once
#include "Object.h"

class Bullet abstract :
	public Object
{
protected:
	float angle; // �Ѿ��� �߻�� ���� ���� �ʵ�, degree ����
	float speed;

public:
	void SetAngle(float angle) { this->angle = angle; }

public:
	// Object��(��) ���� ��ӵ�
	void Initialize() abstract;
	void Update() abstract;
	void Render(HDC hdc) abstract;
	void Release() abstract;

	Bullet();
	virtual ~Bullet();
};

