#pragma once
#include "Define.h"

class Object;

class MainGame
{
private:
	HDC hdc; // 게임 내 객체를 그릴 때 사용할 hdc
	Object* player; // 플레이어 객체를 담아둘 필드
	
	list<Object*> bullets; // 생성된 총알들을 갖는 리스트
	
	// 유도탄 발사 시, 가장 가까운 타겟을 찾기 위해 몬스터 리스트 정보가 필요함
	// 이 때, 편하게 몬스터 리스트에 접근하기 위해 임시로 static 설정
	// 좋은 방식 아님
public:
	static list<Object*> monsters;

public:
	void Initialize();
	void Update();
	void Render();
	void Release();

	MainGame();
	~MainGame();
};

