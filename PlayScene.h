#pragma once
#include "GameObject.h"
class PlayScene :
    public GameObject
{
    PlayScene();
    ~PlayScene();
    void Update() override;
    void Draw() override;
};

