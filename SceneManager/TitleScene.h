#pragma once
#include <Adapter/Novice.h>
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
	bool SetFlagChange(bool flagChange) {  return this->flagChange_ = flagChange; };

private:

	//シーン変更できるかどうか
	bool flagChange_ = false; 

	/// <summary>
	/// 現在のタイトル画面のモード
	/// </summary>
	int titleSModeNow_ = None;

	//受け取りのせいですぐに変わるのでそれを防ぐためのラグ(後で消える)
	int changeTimingFrame_ = 40;

};
