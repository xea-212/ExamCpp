#pragma once
#include "GameObject.h"
#include "globals.h"

class Bullet; // �O���錾


class Player :
    public GameObject
{  
public:
    Player();
    ~Player();
    void Update() override;
    void Draw() override;
    void Shoot(); // �e�𔭎˂���֐�
    Rect GetRect() const { return{ pos_.x, pos_.y, imageSize_.x, imageSize_.y }; } // �v���C���[�̋�`���擾
    std::vector<Bullet*> GetAllBullets() const { return bullets_; }
    Point GetPosition() const { return pos_; }
    static Player* Instance()
    {
        return pInstance_;
    }
protected:
private:
    int hImage_;    //�v���C���[�摜�̃n���h��
    Point pos_;   //�v���C���[�̍��W
    float speed_;    //�v���C���[�̈ړ����W
    Point imageSize_;
    std::vector<Bullet*> bullets_;
    Bullet* GetActiveBullet();
    static Player* pInstance_;
};

