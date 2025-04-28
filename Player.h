#pragma once
#include "GameObject.h"
class Player :
    public GameObject
{
    int hImage_;    //プレイヤー画像のハンドル
    float x_, y_;   //プレイヤーの座標
    float speed_;    //プレイヤーの移動座標

public:
    Player();
    ~Player();
    void Update() override;
    void Draw() override;
};

