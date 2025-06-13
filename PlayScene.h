#pragma once
#include "GameObject.h"
class PlayScene :
    public GameObject
{
public:
    PlayScene();
    ~PlayScene();
    void Update() override;
    void Draw() override;
};

