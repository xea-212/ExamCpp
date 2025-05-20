#pragma once
#include "GameObject.h"


class Bullet :
    public GameObject
{
public:
    Bullet();
    Bullet(float x, float y);
    ~Bullet();
    void Update() override;
    void Draw() override;

    void SetPos(float x, float y);
private:
    int hImage_; //�e�̉摜�n���h��
    float x_, y_; //�e�̍��W
    float speed_; //�e�̈ړ����x
    bool isAlive_; //�e�������Ă��邩
    int isize_x, isize_y; //�e�̕\���T�C�Y
};

