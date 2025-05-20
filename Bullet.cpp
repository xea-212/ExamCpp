#include "globals.h"
#include "Bullet.h"
#include <DxLib.h>
#include <string>

namespace
{
	const int BULLET_IMAGE_WIDTH = 13; //弾の画像の幅
	const int BULLET_IMAGE_HEIGHT = 33; //弾の画像の高さ
	const float BULLET_INIT_SPEED = 200; //弾の初期移動速度
	const std::string BULLET_IMAGE_PATH = "Assets\\laserBlue03.png"; //弾の画像のパス
}

Bullet::Bullet()
	:GameObject(), hImage_(-1), x_(0), y_(0), speed_(0),
	isize_x(BULLET_IMAGE_WIDTH), isize_y(BULLET_IMAGE_HEIGHT)
{
	hImage_ = LoadGraph(BULLET_IMAGE_PATH.c_str()); //弾の画像を読み込む
	speed_ = BULLET_INIT_SPEED; //移動速度
	AddGameObject(this);
}

Bullet::Bullet(float x, float y)
	:GameObject(), hImage_(-1), x_(x), y_(y), speed_(0),
	isize_x(BULLET_IMAGE_WIDTH), isize_y(BULLET_IMAGE_HEIGHT)
{
	hImage_ = LoadGraph(BULLET_IMAGE_PATH.c_str()); //弾の画像を読み込む
	speed_ = BULLET_INIT_SPEED; //移動速度
	isAlive_ = true;
	AddGameObject(this);
}

Bullet::~Bullet()
{
	if (hImage_ != -1)
	{
		DeleteGraph(hImage_); //画像の開放
	}
	hImage_ = -1; //画像のハンドルを無効化
}

void Bullet::Update()
{
	float dt = GetDeltaTime();
	y_ = y_ - speed_ * dt; //弾の初速
	if (y_ < 0)
	{
		isAlive_ = false; //画面外に出たら弾を消す
	}
}

void Bullet::Draw()
{
	if (isAlive_)
	{
		DrawExtendGraph(x_, y_, x_ + isize_x, y_ + isize_y, hImage_, TRUE);
	}
}

void Bullet::SetPos(float x, float y)
{
	x_ = x;
	y_ = y;
}
