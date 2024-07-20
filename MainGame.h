#pragma once
#include "Define.h"

class Object;

class MainGame
{
private:
	HDC hdc; // ���� �� ��ü�� �׸� �� ����� hdc
	Object* player; // �÷��̾� ��ü�� ��Ƶ� �ʵ�
	
	list<Object*> bullets; // ������ �Ѿ˵��� ���� ����Ʈ
	
	// ����ź �߻� ��, ���� ����� Ÿ���� ã�� ���� ���� ����Ʈ ������ �ʿ���
	// �� ��, ���ϰ� ���� ����Ʈ�� �����ϱ� ���� �ӽ÷� static ����
	// ���� ��� �ƴ�
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

