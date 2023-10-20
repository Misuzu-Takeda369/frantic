#pragma once
#include "Audio.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Sprite.h"
/// <summary>
/// タイトルシーンのクラス
/// </summary>

class TitleScene
{
public:

	enum TitleSMode {
		None,Expriense,Option
		//何もなし,操作説明,オプション？
	};
	/// <summary>
	/// コンストクラタ
	/// </summary>
	TitleScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~TitleScene();

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
	bool SetFlagChange(bool flagChange) {  return this->flagChange_ = flagChange; };

private:


	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;
	//シーン変更できるかどうか
	bool flagChange_ = false; 

	/// <summary>
	/// 現在のタイトル画面のモード
	/// </summary>
	int titleSModeNow_ = None;

	

};
