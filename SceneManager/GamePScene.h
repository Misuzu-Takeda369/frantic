#pragma once
#include "ImGuiManager.h"
#include "Audio.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Sprite.h"
#include "Player/Player.h"
/// <summary>
/// プレイシーンのクラス
/// </summary>

class GamePScene {
public:

	enum GameSMode {
		None, Pause,Option
		//何もなし,ポーズ
	};

	/// <summary>
	/// コンストクラタ
	/// </summary>
	GamePScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GamePScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

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
	/// クリアとoverを判別するためのフラグのゲッター
	/// </summary>
	/// <returns></returns>
	bool GetFlagGameOver() { return flagGameOver_; };



private:

	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	// シーン変更できるかどうか
	bool flagChange_ = false;
	//クリアとoverを判別するためのフラグ
	bool flagGameOver_ = false;

	//仮挙動
	int CountNum_ = 0;

	/// <summary>
	/// 現在のタイトル画面のモード
	/// </summary>
	int gameSModeNow_ = None;


	//ゲームをうごかしているか
	bool GameMove_ = false;


	Player* player_ = nullptr;

};
