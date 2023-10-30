#pragma once
#include "Novice.h"
#include "ImGuiManager.h"
#include "Function/Function.h"
#include "Player/Player.h"
#include "UI/HpUI.h"
#include "UI/SpUI.h"
#include "UI/TimerUI.h"
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
	void Update(char* keys, char* preKeys);

	/// <summary>
	/// 前景描画
	/// </summary>
	void Draw();

	/// <summary>
	/// 当たり判定すべてを統括する関数
	/// </summary>
	void CollisionDetection();

	

	///ゲッターセッター

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

	//受け取りのせいですぐに変わるのでそれを防ぐためのラグ(後で消える)
	//シーンチェンジとポーズ変更
	int changeTimingFrame_ = 0;

	//ゲームをうごかしているか
	bool GameMove_ = false;


	Player* player_ = nullptr;

	HpUI* hpUi_ = nullptr;
	SpUI* spUi_ = nullptr;
	TimerUI* timerUi_ = nullptr;

};
