#pragma once
#include "Object.h"

// 1. 몬스터 클래스를 정의하고, 메인게임에서 몬스터 객체를 10마리 생성
// 2. 몬스터는 x, y 축으로 100만큼의 사이즈를 갖고, 원의 모양을 갖습니다.
// 3. 여러 마리의 몬스터를 관리할 수 있게 list에 몬스터 객체를 담아주세요
// 4. 생성 시, 몬스터의 위치는 화면 내에서 랜덤한 위치로 설정

class Monster :
    public Object
{
public:
	// Object을(를) 통해 상속됨
	void Initialize() override;
	void Update() override;
	void Render(HDC hdc) override;
	void Release() override;

	Monster();
	virtual ~Monster();
};

