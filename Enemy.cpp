#include "Enemy.h"
#include <DxLib.h>
#include <string>

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
	//id��type���w�肳��Ȃ��������̏����������ɏ����˂�
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
