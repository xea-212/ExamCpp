#pragma once
#include "GameObject.h"
#include "globals.h"
#include "Player.h"

class EnemyBeam :
    public GameObject
{

public:
    EnemyBeam();
    EnemyBeam(float x, float y);
    EnemyBeam(Point pos_);
    ~EnemyBeam();
    void Update() override;
    void Draw() override;

    void SetPos(float x, float y) { pos_.x = x; pos_.y = y; }
    void SetPos(const Point& pos) { pos_ = pos; }
    void SetFired(bool fired) { isFired_ = fired; } //発射状態を設定
    bool IsFired() const { return isFired_; } //発射状態を取得
    Rect GetRect() const { return{ pos_.x, pos_.y, imageSize_.x, imageSize_.y }; }
protected:
private:
    int hImage_; //弾の画像ハンドル
    Point pos_; //弾の座標
    float speed_; //弾の移動速度
    Point imageSize_;
    //int isize_x, isize_y; //弾の表示サイズ
    bool isFired_; //発射されているかどうか
    Player* p;
    Point pPos;
    Point direction_;
};

