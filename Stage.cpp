#include "Stage.h"
#include "Player.h"
#include "Enemy.h"

namespace
{
	const int ENEMY_NUM = 10*7; //敵の数
	const int ENEMY_COL_SIZE = 10;
	const int ENEMY_ROW_SIZE = 7;
	int type;
}

Stage::Stage()
	: GameObject(), player_(nullptr)
{
	AddGameObject(this);
	player_ = new Player();
	enemy_ = std::vector<Enemy*>(ENEMY_NUM);
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		int col = i % ENEMY_COL_SIZE;
		int row = i / ENEMY_COL_SIZE;
		ETYPE enemyType[ENEMY_ROW_SIZE] = { BOSS, KNIGHT, MID, ZAKO, ZAKO, ZAKO };

		enemy_[i] = new Enemy(i, enemyType[row]);
		enemy_[i]->SetPos(col * 55,  row * 50);
	}
}

Stage::~Stage()
{
}

void Stage::Update()
{
	player_->Update(); // プレイヤーの更新
	for (auto& elm : enemy_)
	{
		elm->Update(); // 敵の更新
	}
}

void Stage::Draw()
{
	player_->Draw(); // プレイヤーの描画
	for (auto& elm : enemy_)
	{
		elm->Draw(); // 敵の描画
	}
}
