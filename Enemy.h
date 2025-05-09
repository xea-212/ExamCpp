#pragma once
#include "GameObject.h"


class Enemy :
    public GameObject
{
    int hImage_;    //“G‰æ‘œ‚Ìƒnƒ“ƒhƒ‹
    float x_, y_;   //“G‚ÌÀ•W
    float speed_;    //“G‚ÌˆÚ“®À•W
    bool isAlive_;  //“G‚Ì¶€
public:
    Enemy();
    ~Enemy();
    void Update() override;
    void Draw() override;
    void SetPos(float x, float y) { x_ = x, y_ = y; } //“G‚ÌÀ•W‚ğİ’è
};

