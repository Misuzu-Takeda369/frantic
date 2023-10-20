#include "SceneManager/GameCScene.h"

GameCScene::GameCScene() {}

GameCScene::~GameCScene() {}

void GameCScene::Initialize()
{
	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();

}

void GameCScene::Update()
{


	//ここのif文でシーン移行出来るかを判別
	//現在は4を押したときに移動
	//ここのif文でシーン移行出来るかを判別
	//現在は1を押したときに移動
	if (input_->TriggerKey(DIK_I)) {
		flagChange_ = true;
	}

}

void GameCScene::Draw() 
{
	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();
#pragma region スプライト描画
	// スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion

}

