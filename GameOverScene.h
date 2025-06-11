#pragma once
#include "GameObject.h"

class GameOverScene
	: public GameObject
{
	GameOverScene();
	~GameOverScene();
	void Update() override;
	void Draw() override;
};

