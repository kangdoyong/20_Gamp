#pragma once
#include "Object.h"
class Player :
    public Object
{
private:
	// 이동 속력
	int speed;
	// 포신의 길이
	float gunBarrelLength;
	// 포신 회전 시, 사용할 각
	float gunBarrelAngle;
	// 메인 게임 객체가 갖는 총알리스트의 주소를 갖는 필드
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
	// Object을(를) 통해 상속됨
	void Initialize() override;
	void Update() override;
	void Render(HDC hdc) override;
	void Release() override;

	Player();
	virtual ~Player();
};


