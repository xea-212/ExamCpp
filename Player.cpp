#include "Player.h"
#include <DxLib.h>
#include "globals.h"
#include "Input.h"
#include "Bullet.h"


namespace
{
	const float PLAYER_INIT_SPEED = 200.0f;//�v���C���[�̏����ړ����x
	const int PLAYER_IMAGE_WIDTH = 48;//�v���C���[�̉摜�̕�
	const int PLAYER_IMAGE_HEIGHT = 48;//�v���C���[�̉摜�̍���
	const int PLAYER_BASE_MARGIN = 32;//�v���C���[�̊�}�[�W��

	const float PLAYER_INIT_X = WIN_WIDTH / 2 - PLAYER_IMAGE_WIDTH / 2;//�v���C���[�̏���X���W
	const float PLAYER_INIT_Y = WIN_HEIGHT - PLAYER_IMAGE_HEIGHT - PLAYER_BASE_MARGIN;//�v���C���[�̏���Y���W
	const int BULLET_IMAGE_MARGIN = 17; //�e�̉摜�̃}�[�W��
	const float BULLET_INTERVAL = 0.5f; //�e�̔��ˊԊu
	const int PLAYER_BULLET_NUM = 5; // �v���C���[�������ɔ��˂ł���e�̐�
};


Player::Player()
	:GameObject(), hImage_(-1), pos_({0,0}), speed_(0), imageSize_({PLAYER_IMAGE_WIDTH ,PLAYER_IMAGE_HEIGHT})
{
	hImage_ = LoadGraph("Assets\\tiny_ship5.png");//�v���C���[�̉摜��ǂݍ���
	if (hImage_ == -1)
	{
		//�摜�̓ǂݍ��݂Ɏ��s�����ꍇ�̃G���[�n���h�����O
		//�G���[��Ԃ��ăQ�[���I��
	}
	pos_.x = PLAYER_INIT_X;//�������W
	pos_.y = PLAYER_INIT_Y;
	speed_ = PLAYER_INIT_SPEED;
	for (int i = 0; i < PLAYER_BULLET_NUM; i++)
	{
		bullets_.push_back(new Bullet()); // �e�̃x�N�^�[��������
	}

	pInstance_ = this;
	AddGameObject(this); //�v���C���[�I�u�W�F�N�g���Q�[���I�u�W�F�N�g�ɒǉ�
}

Player::~Player()
{
	//��ʃT�C�Y������i��ŏ����I�j
}

void Player::Update()
{
	float dt = GetDeltaTime(); //�t���[���Ԃ̎��ԍ����擾
	if (Input::IsKeepKeyDown(KEY_INPUT_LEFT))
	{
		pos_.x -= speed_ * dt; // ���Ɉړ�
	}
	if (Input::IsKeepKeyDown(KEY_INPUT_RIGHT))
	{
		pos_.x += speed_ * dt;  // �E�Ɉړ�
	}
	static float bulletTimer = 0.0f;
	
	if (bulletTimer > 0.0f)
	{
		bulletTimer -= dt;
	}

	if (Input::IsKeyDown(KEY_INPUT_SPACE))
	{
		if (bulletTimer <= 0.0f)
		{
			Shoot(); // �e�𔭎�
			//new Bullet(pos_.x + BULLET_IMAGE_MARGE, pos_.y); //�e�𔭎�
			bulletTimer = BULLET_INTERVAL; //�e�̔��ˊԊu�����Z�b�g
		}
	}
}

void Player::Draw()
{
	// �v���C���[�̉摜��`��i�摜�̌��_�͍���j
	DrawExtendGraphF(pos_.x, pos_.y, pos_.x + PLAYER_IMAGE_WIDTH, pos_.y + PLAYER_IMAGE_HEIGHT, hImage_, TRUE);
}

//�e�����֐�
void Player::Shoot()
{
	//for (auto& itr : bullets_)
	//{
	//	if (itr->IsFired() == false)
	//	{
	//		itr->SetPos(pos_.x + BULLET_IMAGE_MARGIN, pos_.y); // �e�̈ʒu��ݒ�
	//		itr->SetFired(true); // ���ˏ�Ԃɂ���
	//		break; //����˂����烋�[�v�𔲂���
	//	}
	//}

	Bullet* blt = GetActiveBullet();
	if (blt != nullptr)
	{
		blt->SetPos(pos_.x + BULLET_IMAGE_MARGIN, pos_.y); // �e�̈ʒu��ݒ�
		blt->SetFired(true); // ���ˏ�Ԃɂ���
	}
}

Bullet* Player::GetActiveBullet()
{
	for (auto& itr : bullets_)
	{
		if (!itr->IsFired())
		{
			return itr;
		}
	}
	return nullptr;
}

Player* Player::pInstance_ = nullptr;
