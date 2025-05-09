#include "Enemy.h"
#include <DxLib.h>

namespace
{
	const int ENEMY_IMAGE_WIDTH = 48;//�v���C���[�̉摜�̕�
	const int ENEMY_IMAGE_HEIGHT = 48;//�v���C���[�̉摜�̍���

	const float ENEMY_INIT_X = 100;//�v���C���[�̏���X���W
	const float ENEMY_INIT_Y = 100;//�v���C���[�̏���Y���W
	const float ENEMY_INIT_SPEED = 100.0f;
}

Enemy::Enemy()
	:GameObject(), hImage_(-1), x_(0), y_(0), speed_(0), isAlive_(true)
{
	hImage_ = LoadGraph("Assets\\tiny_ship10.png");//�v���C���[�̉摜��ǂݍ���
	if (hImage_ == -1)
	{
		//�摜�̓ǂݍ��݂Ɏ��s�����ꍇ�̃G���[�n���h�����O
		//�G���[��Ԃ��ăQ�[���I��
	}
	x_ = ENEMY_INIT_X;//�������W
	y_ = ENEMY_INIT_Y;//�������W
	speed_ = ENEMY_INIT_SPEED;//�ړ����x
}

Enemy::~Enemy()
{
	if (hImage_ != -1)
	{
		DeleteGraph(hImage_); //�摜�̃n���h�������
	}
}

void Enemy::Update()
{
}

void Enemy::Draw()
{
	//�摜�̍���ɓG�摜��\��
	DrawExtendGraph(x_, y_, x_ + ENEMY_IMAGE_WIDTH, y_ + ENEMY_IMAGE_HEIGHT, hImage_, TRUE);
}
