#include "EnemyBeam.h"
#include "DxLib.h"
#include <cmath>

namespace
{
	const int ENEMY_BEAM_IMAGE_WIDTH = 11;
	const int ENEMY_BEAM_IMAGE_HEIGHT = 21;
	const float ENEMY_BEAM_INIT_SPEED = 250.0f;
}

EnemyBeam::EnemyBeam()
	:GameObject(), hImage_(-1),pos_({-10,-10}), speed_(ENEMY_BEAM_INIT_SPEED),
	isFired_(false), imageSize_({ ENEMY_BEAM_IMAGE_WIDTH,ENEMY_BEAM_IMAGE_HEIGHT }), //�����T�C�Y��ݒ�
	pPos({0,0})
{
	hImage_ = LoadGraph("Assets\\ebeams.png");

	AddGameObject(this);
}

EnemyBeam::EnemyBeam(float x, float y)
	:GameObject(), hImage_(-1), pos_({ x, y }), speed_(ENEMY_BEAM_INIT_SPEED),
	isFired_(true), imageSize_({ ENEMY_BEAM_IMAGE_WIDTH,ENEMY_BEAM_IMAGE_HEIGHT }),
	pPos({0,0}), direction_({0,0})
{
	hImage_ = LoadGraph("Assets\\ebeams.png");

	p = Player::Instance();
	pPos = p->GetPosition();
	float dx = pPos.x - pos_.x;
	float dy = pPos.y - pos_.y;

	float length = std::sqrt(dx * dx + dy * dy);
	if (length > 0)
	{
		direction_.x = dx / length;
		direction_.y = dy / length;
	}
	else
	{
		direction_ = { 0.0f, 1.0f }; // Default to down if start and target are same
	}


	AddGameObject(this);
}

EnemyBeam::EnemyBeam(Point pos_)
	:GameObject(), hImage_(-1), pos_({ pos_.x,pos_.y }), speed_(ENEMY_BEAM_INIT_SPEED),
	isFired_(true), imageSize_({ ENEMY_BEAM_IMAGE_WIDTH,ENEMY_BEAM_IMAGE_HEIGHT }),
	pPos({0,0}), direction_({ 0,0 })
{
	hImage_ = LoadGraph("Assets\\ebeams.png");
	p = Player::Instance();
	pPos = p->GetPosition();
	float dx = pPos.x - pos_.x;
	float dy = pPos.y - pos_.y;

	float length = std::sqrt(dx * dx + dy * dy);
	if (length > 0)
	{
		direction_.x = dx / length;
		direction_.y = dy / length;
	}
	else
	{
		direction_ = { 0.0f, 1.0f }; // Default to down if start and target are same
	}

	AddGameObject(this);
}

EnemyBeam::~EnemyBeam()
{
	if (hImage_ != -1)
	{
		DeleteGraph(hImage_);
	}
	hImage_ = -1;
}

void EnemyBeam::Update()
{
	float dt = GetDeltaTime();

	pos_.x += direction_.x * speed_ * dt;
	pos_.y += direction_.y * speed_ * dt;

	if (pos_.y > WIN_HEIGHT) {
		isFired_ = false; // ��ʊO�ɏo���珀����Ԃɖ߂�
		SetAlive(false);
	}
}

void EnemyBeam::Draw()
{
	//���˂���Ă�����`��
	if (isFired_)
	{

		DrawExtendGraphF(pos_.x, pos_.y, pos_.x + imageSize_.x, pos_.y + imageSize_.y,
			hImage_, TRUE); // �e�̕`��
	}
}
