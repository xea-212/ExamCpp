#include "Effect.h"
#include <DxLib.h>
#include <string>

namespace {
	float ANIME_TIME = { 1.0f };
	int EFFECT_IMAGE_SIZE = { 48 };
	const std::string EIMG_PATH = "Assets\\explosion.png";
	const int MAX_FRAME = 9;
	const int DIV_NUM = 3;
	const float FRAME_TIME = ANIME_TIME / MAX_FRAME;
}


Effect::Effect(Point _pos)
	:GameObject(), pos_({ _pos.x, _pos.y }), hImage_(std::vector<int>(MAX_FRAME,-1)),
	animeTimer_(ANIME_TIME), frame_(0)
{
	//hImage_ = LoadGraph(EIMG_PATH.c_str());
	LoadDivGraph(EIMG_PATH.c_str(), MAX_FRAME, DIV_NUM, DIV_NUM, 
		EFFECT_IMAGE_SIZE, EFFECT_IMAGE_SIZE, hImage_.data());
	AddGameObject(this);
}

Effect::~Effect()
{
	//DeleteGraph(hImage_);
	for (auto& itr : hImage_)
	{
		DeleteGraph(itr);
		hImage_.clear();
	}
}

void Effect::Update()
{
	const int FrameTimer = ANIME_TIME / MAX_FRAME;
	float dt = GetDeltaTime();
	animeTimer_ = animeTimer_ - dt;
	if (animeTimer_ < 0)
	{
		this->isAlive_ = false;
	}

	frameTimer_ = frameTimer_ - dt;
	if (frameTimer_ < 0)
	{
		frame_++;
		frameTimer_ = FRAME_TIME - frameTimer_;
	}
}

void Effect::Draw()
{
	DrawExtendGraphF(pos_.x, pos_.y, pos_.x + EFFECT_IMAGE_SIZE, pos_.y + EFFECT_IMAGE_SIZE, hImage_[frame_], TRUE);
}