#pragma once
#include "GameObject.h"

class GameOverScene
	: public GameObject
{
public:
	GameOverScene();
	~GameOverScene();
	void Update() override;
	void Draw() override;
};

