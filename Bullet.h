#pragma once
#include "Object.h"

class Bullet abstract :
	public Object
{
protected:
	float angle; // 총알이 발사될 각을 갖는 필드, degree 각도
	float speed;

public:
	void SetAngle(float angle) { this->angle = angle; }

public:
	// Object을(를) 통해 상속됨
	void Initialize() abstract;
	void Update() abstract;
	void Render(HDC hdc) abstract;
	void Release() abstract;

	Bullet();
	virtual ~Bullet();
};

