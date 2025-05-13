#include "Enemy.h"
#include <DxLib.h>
#include <string>

namespace
{
	const int ENEMY_IMAGE_WIDTH = 48;//プレイヤーの画像の幅
	const int ENEMY_IMAGE_HEIGHT = 48;//プレイヤーの画像の高さ

	const float ENEMY_INIT_X = 100;//プレイヤーの初期X座標
	const float ENEMY_INIT_Y = 100;//プレイヤーの初期Y座標
	const float ENEMY_INIT_SPEED = 100.0f;
}

Enemy::Enemy()
	:GameObject(), hImage_(-1), x_(0), y_(0), speed_(0), isAlive_(true)
{
	hImage_ = LoadGraph("Assets\\tiny_ship10.png");//プレイヤーの画像を読み込む
	if (hImage_ == -1)
	{
		//画像の読み込みに失敗した場合のエラーハンドリング
		//エラーを返してゲーム終了
	}
	x_ = ENEMY_INIT_X;//初期座標
	y_ = ENEMY_INIT_Y;//初期座標
	speed_ = ENEMY_INIT_SPEED;//移動速度
	//idとtypeを指定されなかった時の処理をここに書かねば
}

Enemy::Enemy(int id, ETYPE type)
	: GameObject(), hImage_(-1), x_(0), y_(0), speed_(0), isAlive_(true), ID_(id), type_(type)
{
	std::string imagePath[MAX_ETYPE] =
	{
		"Assets\\tiny_ship10.png", //ZKAO
		"Assets\\tiny_ship18.png", //MID
		"Assets\\tiny_ship16.png", //KNIGHT
		"Assets\\tiny_ship9.png" //BOSS
	};

	hImage_ = LoadGraph(imagePath[type_].c_str());
	if (hImage_ == -1)
	{
		//画像の読み込みに失敗した場合のエラーハンドリング
		//エラーを返してゲーム終了
	}
	x_ = ENEMY_INIT_X;//初期座標
	y_ = ENEMY_INIT_Y;//初期座標
	speed_ = ENEMY_INIT_SPEED;//移動速度
}


Enemy::~Enemy()
{
	if (hImage_ != -1)
	{
		DeleteGraph(hImage_); //画像のハンドルを解放
	}
}

void Enemy::Update()
{
}

void Enemy::Draw()
{
	//画像の左上に敵画像を表示
	DrawExtendGraph(x_, y_, x_ + ENEMY_IMAGE_WIDTH, y_ + ENEMY_IMAGE_HEIGHT, hImage_, TRUE);
}
