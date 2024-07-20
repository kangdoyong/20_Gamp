#pragma once
#include "Bullet.h"
class RotateBullet :
    public Bullet
{
	// 가상의 점을 발사시점 포신 방향으로 계속해서 이동시킨다.
	// 총알은 가상의 점을 기준으로 회전한다.
private:
	// 총알이 회전할 때 쓰일 가상의 점의 좌표를 나타낼 필드
	float rotCenterX;
	float rotCenterY;
	// 총알이 회전할 때, 쓰일 각
	float rotAngle;
	// 총알이 방금 발사됐는지를 나타낼 필드
	// -> 총알이 생성되고 첫 업데이트인지?
	bool isFire;

public:
	// Bullet을(를) 통해 상속됨
	void Initialize() override;
	void Update() override;
	void Render(HDC hdc) override;
	void Release() override;

	RotateBullet();
	virtual ~RotateBullet();
};

