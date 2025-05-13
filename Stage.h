#pragma once
#include "GameObject.h"
#include <vector>

//�|�C���^�[�̎��������̎g�������ł���
class Player; //�O���錾
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

