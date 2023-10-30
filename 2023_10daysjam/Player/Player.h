﻿#pragma once

#include "Object/Object.h"
#include <list>
#include "Function/Function.h"
#include "PlayerMAttack.h"
#include "PlayerLAttack.h"
#include "Animation/PlayerAnimation.h"



class Player : public Object
{
public:

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Player();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize() override;

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update(char* keys, char* preKeys) override;

	/// <summary>
	/// 前景描画
	/// </summary>
	void Draw() override;

	/// <summary>
	/// キー入力
	/// </summary>
	void Move(char* keys, char* preKeys);
	/// <summary>
	///	ジャンプ処理用
	/// </summary>
	void Jump();

	/// <summary>
	/// 攻撃のtypeが変わる
	/// </summary>
	void AttackTypeChange();

	/// <summary>
	/// 精神状態の変更(基底クラスに移動挙動すべて一緒のはずなので)
	/// </summary>
	void MindTypeChange();

	/// <summary>
	/// 攻撃処理
	/// </summary>
	void Attack();

	/// <summary>
	/// 弾が消える関数
	/// </summary>
	void BulletDead();

	/// <summary>
	/// 攻撃時のSPの処理
	/// </summary>
	void AttackSpDown();

	/// <summary>
	/// プレイヤーの攻撃方向をマウスの位置で決める
	/// </summary>
	void playerDirectionDecisionA();


	/// <summary>
	/// enum　State適応のチェンジ
	/// </summary>
	void PlayerStateChange(char* keys);

	/// <summary>
	/// 当たった時の挙動
	/// </summary>
	void OnCollision() override;

	/// <summary>
	/// 最大値のHP
	/// </summary>
	/// <returns></returns>
	float GetPlayerHpMax() { return maxHp_; };
	/// <summary>
	/// 最大値のSP
	/// </summary>
	/// <returns></returns>
	float GetPlayerSpMax() { return maxSp_; };

	/// <summary>
	/// 最大-現在のHP
	/// </summary>
	/// <returns></returns>
	float GetPlayerDecreasedHp() { return decreasedHp_; };
	/// <summary>
	/// 最大-現在のSP
	/// </summary>
	/// <returns></returns>
	float GetPlayerDecreasedSp() { return decreasedSp_; };

	/// <summary>
	/// 近距離の攻撃のゲッター
	/// </summary>
	/// <returns></returns>
	PlayerMAttack* GetMAttack() { return mAttack_; };

	/// <summary>
	/// 遠距離の攻撃のゲッター
	/// </summary>
	/// <returns></returns>
	const std::list<PlayerLAttack*>& GetBullet() { return lAttack_; };

private:

	//マウスの位置(Yも無いと関数動かん)
	IntState mousePos_ = {0,0};
	
	//STATE用変数
	STATE playerState_ = IDOL;

	//Hp,Sp関連(最大、現在,減少量)
	const float maxHp_ = 500.0f;
	const float maxSp_ = 500.0f;
	float decreasedHp_;
	float decreasedSp_;
	
	

	//プレイヤーの向き(攻撃の向き)
	PlayerDirection playerDirectionA_ = RIGHT;

	//プレイヤーの向き(動き(待機や移動などキー入力で変化するタイプ))
	PlayerDirection playerDirectionM_ = RIGHT;

	//精神状態が変わる値の変数
	float spChangingPoint_ = 250.0f;
	//magic攻撃時のSP減少量
	float attackSpDown_ = 20.0f;

	//近距離用の当たり判定用クラス
	PlayerMAttack* mAttack_ = nullptr;

	//遠距離の当たり判定(複数にする)
	std::list<PlayerLAttack*> lAttack_;

	//アニメーション関連
	PlayerAnimation* playerAnimation_ = nullptr;

	///ジャンプ関連
	//ジャンプの最初のスピード
	float jumpSpeed_;
	//ジャンプするかのフラグ
	bool jumpFrag_ = false;
	//ジャンプのラグ
	int jumpLag_ = 10;
	///ジャンプ関連
	
	///攻撃関連
	//現在の攻撃type
	PlayerAttackType playerAttackTypeNow_ = Plane;
	//近距離攻撃できるかフラグ(近距離)
	bool attackFrag_ = false;
	

	//最初にいる位置
	Vector2 standardPos_;

	//攻撃している時間仮近距離(多分eff・animeでいらなくなる)
	int attackframe_ = 60;

	
};

