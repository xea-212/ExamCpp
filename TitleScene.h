#pragma once
#include "GameObject.h"
class TitleScene :
    public GameObject
{
    TitleScene();
    ~TitleScene();
    void Update() override;
    void Draw() override;
};

