#include "MainGame.h"
#include "Player.h"
#include "Monster.h"
#include "MathUtil.h"

list<Object*> MainGame::monsters;

void MainGame::Initialize()
{
	hdc = GetDC(g_hWnd);

	player = new Player();
	player->Initialize();

	// 메인게임 객체가 갖는 총알리스트의 주소를 플레이어 객체에 넘김
	((Player*)player)->SetBullets(&bullets);

	for (int i = 0; i < 10; ++i)
	{
		Object* monster = new Monster();
		monster->Initialize();
		monster->SetPos(rand() % WIN_SIZE_X, rand() % WIN_SIZE_Y);

		monsters.push_back(monster);
	}
}

void MainGame::Update()
{
	player->Update();

	for (auto i = bullets.begin(); i != bullets.end();)
	{
		(*i)->Update();

		auto info = (*i)->GetInfo();

		if (info.posX < 0 || info.posX > WIN_SIZE_X
			|| info.posY < 0 || info.posY > WIN_SIZE_Y)
		{
			delete* i;
			*i = nullptr;
			i = bullets.erase(i);
		}
		else
		{
			++i;
		}
	}

	for (auto i = monsters.begin(); i != monsters.end(); )
	{
		if (MathUtil::OnCollision(player, *i))
		{
			delete* i;
			*i = nullptr;
			i = monsters.erase(i);
		}
		else
		{
			++i;
		}
	}
}

void MainGame::Render()
{
	Rectangle(hdc, 0, 0, WIN_SIZE_X, WIN_SIZE_Y);
	player->Render(hdc);

	for (auto i = bullets.begin(); i != bullets.end(); ++i)
	{
		(*i)->Render(hdc);
	}
	for (auto i = monsters.begin(); i != monsters.end(); ++i)
	{
		(*i)->Render(hdc);
	}
}

void MainGame::Release()
{
	if (player)
	{
		delete player;
		player = nullptr;
	}

	for (auto i = bullets.begin(); i != bullets.end(); ++i)
	{
		if (*i)
		{
			delete* i;
			*i = nullptr;
		}
	}
	bullets.clear();

	for (auto i = monsters.begin(); i != monsters.end(); ++i)
	{
		if (*i)
		{
			delete* i;
			*i = nullptr;
		}
	}
	monsters.clear();

	ReleaseDC(g_hWnd, hdc);
}

MainGame::MainGame()
{
}

MainGame::~MainGame()
{
	Release();
}
