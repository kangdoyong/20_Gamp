#pragma once
#include "Bullet.h"
class RotateBullet :
    public Bullet
{
	// ������ ���� �߻���� ���� �������� ����ؼ� �̵���Ų��.
	// �Ѿ��� ������ ���� �������� ȸ���Ѵ�.
private:
	// �Ѿ��� ȸ���� �� ���� ������ ���� ��ǥ�� ��Ÿ�� �ʵ�
	float rotCenterX;
	float rotCenterY;
	// �Ѿ��� ȸ���� ��, ���� ��
	float rotAngle;
	// �Ѿ��� ��� �߻�ƴ����� ��Ÿ�� �ʵ�
	// -> �Ѿ��� �����ǰ� ù ������Ʈ����?
	bool isFire;

public:
	// Bullet��(��) ���� ��ӵ�
	void Initialize() override;
	void Update() override;
	void Render(HDC hdc) override;
	void Release() override;

	RotateBullet();
	virtual ~RotateBullet();
};

