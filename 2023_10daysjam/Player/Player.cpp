#include "Player.h"


Player::~Player()
{
	delete mAttack_;
}

void Player::Initialize()
{
	standardPos_ = { 150.0f,550.0f };

	charaBase_ = {
		{standardPos_.x,standardPos_.y},{2.0f,-2.0f},64.0f,0.0f,WHITE
	};

	hp_ = 500.0f;
	sp_ = 500.0f;

	jumpSpeed_ = 25.0f;

	jumpFrag_ = false;
	jumpLag_ = 10;

	playerAttackTypeNow_ = Plane;
	attackFrag_ = false;

	maindStateNow_ = Normal;
	playerDirection_ = 1;
	attackframe_ = 60;
}

void Player::Update(char* keys, char* preKeys)
{
	//移動処理
	Move(keys,preKeys);
	//攻撃モードの変移
	AttackTypeChange();
	//攻撃
	Attack();

#pragma region ImGum関連

#ifdef _DEBUG

#endif // DEBUG

#pragma endregion
}

void Player::Draw()
{

	//プレイヤー本体
	Novice::DrawEllipse(int(charaBase_.pos_.x),int(charaBase_.pos_.y),	int(charaBase_.radius_), int(charaBase_.radius_),0.0f, charaBase_.color,kFillModeSolid);

	//近距離用当たり判定が起きている時場合
	if (mAttack_) {
		mAttack_->Draw();
	}

#ifdef _DEBUG

	Novice::DrawLine(0,int(standardPos_.y+charaBase_.radius_),1280, int(standardPos_.y + charaBase_.radius_),BLACK);
	
#endif // _DEBUG

}


void Player::Move(char* keys, char* preKeys)
{

	//横移動
	if (keys[DIK_LEFT] || keys[DIK_A]) {
		charaBase_.pos_.x -= charaBase_.speed_.x;
		playerDirection_ = 0;
	}
	else if (keys[DIK_RIGHT] || keys[DIK_D]) {
		charaBase_.pos_.x += charaBase_.speed_.x;
		playerDirection_ = 1;
	}

	//縦
	Jump();
	if (((preKeys[DIK_UP] ==0 && keys[DIK_UP] !=0)|| (preKeys[DIK_W] == 0 && keys[DIK_W] != 0))&& jumpLag_ <= 0) {
		jumpFrag_ = true;
		jumpLag_ = 10;
	}

}

void Player::Jump()
{
	//ジャンプの挙動
	if (jumpFrag_) {
		jumpSpeed_ += charaBase_.speed_.y;
		charaBase_.pos_.y -= jumpSpeed_;

		if (charaBase_.pos_.y>= standardPos_.y) {
			jumpFrag_ = false;
			charaBase_.pos_.y = standardPos_.y;
			jumpSpeed_ = 25.0f;
		}
	}
	else {
		jumpLag_--;
	}
}

void Player::AttackTypeChange()
{
	//右クリックしたら攻撃のモードが変わる
	if (Novice::IsTriggerMouse(1)) {

		if (playerAttackTypeNow_ == Plane) {
			playerAttackTypeNow_ = Magic;
			charaBase_.color = RED;
		}
		else {
			playerAttackTypeNow_ = Plane; 
			charaBase_.color = WHITE;
		}
		

	}

}

void Player::Attack()
{
	//左クリックしたら攻撃する
	if (Novice::IsTriggerMouse(0)) {
		attackFrag_ = true;

		mAttack_ = new PlayerMAttack();
		mAttack_->Initialize(&playerAttackTypeNow_,&maindStateNow_,&playerDirection_);
	}

	//アタックフラグが動いている場合
	if (attackFrag_) {

		//近距離用当たり判定が起きている時場合
		if (mAttack_) {
			mAttack_->Update(&charaBase_.pos_,playerDirection_);
		}

		attackframe_--;
		if (attackframe_<= 0) {
			attackFrag_ = false;
			delete mAttack_;
			attackframe_ = 60;
		}
	}
}

