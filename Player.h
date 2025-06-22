#pragma once
#include "GameObject.h"
#include "globals.h"

class Bullet; // 前方宣言


class Player :
    public GameObject
{  
public:
    Player();
    ~Player();
    void Update() override;
    void Draw() override;
    void Shoot(); // 弾を発射する関数
    Rect GetRect() const { return{ pos_.x, pos_.y, imageSize_.x, imageSize_.y }; } // プレイヤーの矩形を取得
    std::vector<Bullet*> GetAllBullets() const { return bullets_; }
    Point GetPosition() const { return pos_; }
    static Player* Instance()
    {
        return pInstance_;
    }
protected:
private:
    int hImage_;    //プレイヤー画像のハンドル
    Point pos_;   //プレイヤーの座標
    float speed_;    //プレイヤーの移動座標
    Point imageSize_;
    std::vector<Bullet*> bullets_;
    Bullet* GetActiveBullet();
    static Player* pInstance_;
};

