#pragma once
#include "GameObject.h"
#include <vector>

//ポインターの時だけこの使い方ができる
class Player; //前方宣言
class Enemy;

class Stage :
    public GameObject
{
public:
    Stage();
    ~Stage();
    void Update() override;
    void Draw() override;
private:
    Player* player_;
    std::vector<Enemy *> enemy_;
};

