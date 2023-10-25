#pragma once
#include <Vector2.h>
#include <Novice.h>
#include "ImGuiManager.h"
#include <list>
#include "CharaBase.h"
#include "PlayerMAttack.h"
#include "PlayerLAttack.h"


class Player
{
public:

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Player();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update(char* keys, char* preKeys);

	/// <summary>
	/// 前景描画
	/// </summary>
	void Draw();

	/// <summary>
	/// キー入力
	/// </summary>
	void Move(char* keys, char* preKeys);
	//char* keys, char* preKeys
	/// <summary>
	///	ジャンプ処理用
	/// </summary>
	void Jump();

	/// <summary>
	/// 攻撃のtypeが変わる
	/// </summary>
	void AttackTypeChange();

	/// <summary>
	/// 精神状態の変更
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

	float GetPlayerHp() { return hp_; };
	float GetPlayerSp() { return sp_; };

	float GetPlayerHpMax() { return maxHp_; };
	float GetPlayerSpMax() { return maxSp_; };

	float GetPlayerDecreasedHp() { return decreasedHp_; };
	float GetPlayerDecreasedSp() { return decreasedSp_; };

	/// <summary>
	/// アニメーション？のチェンジ
	/// </summary>
	void PlayerStateChange(char* keys, char* preKeys);

	/// <summary>
	/// 近距離の攻撃のゲッター
	/// </summary>
	/// <returns></returns>
	PlayerMAttack GetMAttack() { return *mAttack_; };

	/// <summary>
	/// 遠距離の攻撃のゲッター
	/// </summary>
	/// <returns></returns>
	const std::list<PlayerLAttack*>& GetBullet() { return lAttack_; };

private:

	//基準となる情報(ここからアニメーション用に引っ張る)
	CharaBase charaBase_;

	int playerState_ = IDOL;

	//Hp,Sp関連(最大、現在,減少量)
	const float maxHp_ = 500.0f;
	const float maxSp_ = 500.0f;
	float hp_;
	float sp_;
	float decreasedHp_;
	float decreasedSp_;
	
	

	//現在の狂気度
	int maindStateNow_ = Normal;
	//狂気カラー(デバック用)
	unsigned int maindColor_ = WHITE;
	//プレイヤーの向き
	int playerDirection_ = RIGHT;

	//精神状態が変わる値の変数
	float spChangingPoint_ = 250.0f;
	//magic攻撃時のSP減少量
	float attackSpDown_ = 20.0f;

	//近距離用の当たり判定用クラス
	PlayerMAttack* mAttack_;

	//遠距離の当たり判定(複数にする)
	std::list<PlayerLAttack*> lAttack_;

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
	bool playerAttackTypeNow_ = Plane;
	//近距離攻撃できるかフラグ(近距離)
	bool attackFrag_ = false;
	

	//最初にいる位置
	Vector2 standardPos_;

	//攻撃している時間仮近距離(多分eff・animeでいらなくなる)
	int attackframe_ = 60;

	
};

