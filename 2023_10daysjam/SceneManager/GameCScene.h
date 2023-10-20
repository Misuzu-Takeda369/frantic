#pragma once
#include <Novice.h>

/// <summary>
/// ゲームクリアシーンのクラス
/// </summary>

class GameCScene {
public:
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameCScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameCScene();

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
	/// 背景描画
	/// </summary>
	void BackDraw();

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


private:
	// シーン変更できるかどうか
	bool flagChange_ = false; 

	//受け取りのせいですぐに変わるのでそれを防ぐためのラグ(後で消える)
	int changeTimingFrame_ = 0;

};
