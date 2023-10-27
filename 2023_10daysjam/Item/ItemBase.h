#pragma once

class ItemBase
{
public:

	/// <summary>
	/// 初期化
	/// </summary>
	virtual void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	virtual void Update();

	/// <summary>
	/// 前景描画
	/// </summary>
	virtual void Draw();


	/// <summary>
	/// クラスの外部用アイテム消えるためのフラグ変数
	/// </summary>
	bool IsDead() const { return isDead_; };

protected:

	//位置
	Vector2 pos_;
	//画像サイズ
	int sizeX_; int sizeY_;
	int image_;

	//弾の寿命(消えるまでの時間の定数)
	static const int kLifeTime = 120;
	// 弾の寿命(消えるまでの時間の判定用変数)
	int deathTimer_ = kLifeTime;
	//消えるフラグ
	bool isDead_ = false;
};

