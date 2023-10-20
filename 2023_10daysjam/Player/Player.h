#pragma once
#include <Vector2.h>
#include <Novice.h>
#include "ImGuiManager.h"
#include "CharaBase.h"
#include "PlayerMAttack.h"


class Player
{
public:

	///プレイヤーの精神状態
	enum MaindState {
		//0.通常,1.狂気
		Normal,Lunatic
	};

	///プレイヤーの攻撃モード
	enum PlayerAttackType {
		Plane, Magic
	};

	///プレイヤーの攻撃モード
	enum PlayerDirection {
		//0:左,1:右
		Left, RIGHT
	};
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
	/// 攻撃処理
	/// </summary>
	void Attack();

	float GetPlayerHp() { return hp_; };
	float GetPlayerSp() { return sp_; };

	/// <summary>
	/// 近距離の攻撃のゲッター
	/// </summary>
	/// <returns></returns>
	PlayerMAttack GetMAttack() { return *mAttack_; };

private:

	//基準となる情報(ここからアニメーション用に引っ張る)
	CharaBase charaBase_;
	float hp_;
	float sp_;

	//現在の狂気度
	int maindStateNow_ = Normal;
	//プレイヤーの向き
	int playerDirection_ = RIGHT;

	//近距離用の当たり判定用クラス
	PlayerMAttack* mAttack_;

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
	//攻撃できるかフラグ
	bool attackFrag_ = false;
	//最初にいる位置
	Vector2 standardPos_;

	//攻撃している時間仮(多分eff・animeでいらなくなる)
	int attackframe_ = 60;

};

