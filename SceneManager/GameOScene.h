#pragma once
#include <Adapter/Novice.h>

/// <summary>
/// ゲームオーバーシーンのクラス
/// </summary>

class GameOScene
{
public:
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameOScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameOScene();

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
	/// シーン変更管理のゲッター
	/// </summary>
	/// <returns></returns>
	bool GetFlagChange() { return flagChange_; };

	/// <summary>
	/// シーン変更管理のセッター
	/// </summary>
	/// <returns></returns>
	bool SetFlagChange(bool flagChange) { return this->flagChange_ = flagChange; };

	/// <summary>
	/// リトライするかを判別するためのフラグのゲッター
	/// </summary>
	/// <returns></returns>
	bool GetFlagRetry() { return flagRetry_; };

private:
	// シーン変更できるかどうか
	bool flagChange_ = false;

	//受け取りのせいですぐに変わるのでそれを防ぐためのラグ(後で消える)
	int changeTimingFrame_ = 0;

	//リトライするかを判別するためのフラグ
	bool flagRetry_ = false;

};
