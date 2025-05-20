#include "globals.h"
#include "Bullet.h"
#include <DxLib.h>
#include <string>

namespace
{
	const int BULLET_IMAGE_WIDTH = 13; //�e�̉摜�̕�
	const int BULLET_IMAGE_HEIGHT = 33; //�e�̉摜�̍���
	const float BULLET_INIT_SPEED = 200; //�e�̏����ړ����x
	const std::string BULLET_IMAGE_PATH = "Assets\\laserBlue03.png"; //�e�̉摜�̃p�X
}

Bullet::Bullet()
	:GameObject(), hImage_(-1), x_(0), y_(0), speed_(0),
	isize_x(BULLET_IMAGE_WIDTH), isize_y(BULLET_IMAGE_HEIGHT)
{
	hImage_ = LoadGraph(BULLET_IMAGE_PATH.c_str()); //�e�̉摜��ǂݍ���
	speed_ = BULLET_INIT_SPEED; //�ړ����x
	AddGameObject(this);
}

Bullet::Bullet(float x, float y)
	:GameObject(), hImage_(-1), x_(x), y_(y), speed_(0),
	isize_x(BULLET_IMAGE_WIDTH), isize_y(BULLET_IMAGE_HEIGHT)
{
	hImage_ = LoadGraph(BULLET_IMAGE_PATH.c_str()); //�e�̉摜��ǂݍ���
	speed_ = BULLET_INIT_SPEED; //�ړ����x
	isAlive_ = true;
	AddGameObject(this);
}

Bullet::~Bullet()
{
	if (hImage_ != -1)
	{
		DeleteGraph(hImage_); //�摜�̊J��
	}
	hImage_ = -1; //�摜�̃n���h���𖳌���
}

void Bullet::Update()
{
	float dt = GetDeltaTime();
	y_ = y_ - speed_ * dt; //�e�̏���
	if (y_ < 0)
	{
		isAlive_ = false; //��ʊO�ɏo����e������
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
