#include "Player.h"
#include <DxLib.h>
#include "globals.h"
#include "Input.h"
#include "Bullet.h"


namespace
{
	const float PLAYER_INIT_SPEED = 200.0f;//プレイヤーの初期移動速度
	const int PLAYER_IMAGE_WIDTH = 48;//プレイヤーの画像の幅
	const int PLAYER_IMAGE_HEIGHT = 48;//プレイヤーの画像の高さ
	const int PLAYER_BASE_MARGIN = 32;//プレイヤーの基準マージン

	const float PLAYER_INIT_X = WIN_WIDTH / 2 - PLAYER_IMAGE_WIDTH / 2;//プレイヤーの初期X座標
	const float PLAYER_INIT_Y = WIN_HEIGHT - PLAYER_IMAGE_HEIGHT - PLAYER_BASE_MARGIN;//プレイヤーの初期Y座標
	const int BULLET_IMAGE_MARGIN = 17; //弾の画像のマージン
	const float BULLET_INTERVAL = 0.5f; //弾の発射間隔
	const int PLAYER_BULLET_NUM = 5; // プレイヤーが同時に発射できる弾の数
};


Player::Player()
	:GameObject(), hImage_(-1), pos_({0,0}), speed_(0), imageSize_({PLAYER_IMAGE_WIDTH ,PLAYER_IMAGE_HEIGHT})
{
	hImage_ = LoadGraph("Assets\\tiny_ship5.png");//プレイヤーの画像を読み込む
	if (hImage_ == -1)
	{
		//画像の読み込みに失敗した場合のエラーハンドリング
		//エラーを返してゲーム終了
	}
	pos_.x = PLAYER_INIT_X;//初期座標
	pos_.y = PLAYER_INIT_Y;
	speed_ = PLAYER_INIT_SPEED;
	for (int i = 0; i < PLAYER_BULLET_NUM; i++)
	{
		bullets_.push_back(new Bullet()); // 弾のベクターを初期化
	}

	pInstance_ = this;
	AddGameObject(this); //プレイヤーオブジェクトをゲームオブジェクトに追加
}

Player::~Player()
{
	//画面サイズを解放（後で書く！）
}

void Player::Update()
{
	float dt = GetDeltaTime(); //フレーム間の時間差を取得
	if (Input::IsKeepKeyDown(KEY_INPUT_LEFT))
	{
		pos_.x -= speed_ * dt; // 左に移動
	}
	if (Input::IsKeepKeyDown(KEY_INPUT_RIGHT))
	{
		pos_.x += speed_ * dt;  // 右に移動
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
			Shoot(); // 弾を発射
			//new Bullet(pos_.x + BULLET_IMAGE_MARGE, pos_.y); //弾を発射
			bulletTimer = BULLET_INTERVAL; //弾の発射間隔をリセット
		}
	}
}

void Player::Draw()
{
	// プレイヤーの画像を描画（画像の原点は左上）
	DrawExtendGraphF(pos_.x, pos_.y, pos_.x + PLAYER_IMAGE_WIDTH, pos_.y + PLAYER_IMAGE_HEIGHT, hImage_, TRUE);
}

//弾を撃つ関数
void Player::Shoot()
{
	//for (auto& itr : bullets_)
	//{
	//	if (itr->IsFired() == false)
	//	{
	//		itr->SetPos(pos_.x + BULLET_IMAGE_MARGIN, pos_.y); // 弾の位置を設定
	//		itr->SetFired(true); // 発射状態にする
	//		break; //一つ発射したらループを抜ける
	//	}
	//}

	Bullet* blt = GetActiveBullet();
	if (blt != nullptr)
	{
		blt->SetPos(pos_.x + BULLET_IMAGE_MARGIN, pos_.y); // 弾の位置を設定
		blt->SetFired(true); // 発射状態にする
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
