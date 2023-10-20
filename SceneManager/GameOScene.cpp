#include "GameOScene.h"

GameOScene::GameOScene() {}

GameOScene::~GameOScene() {}


void GameOScene::Initialize() 
{
	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();
}

void GameOScene::Update()
{
#pragma region シーン変換
	//ここのif文でシーン移行出来るかを判別
	//現在は4を押したときに移動
	
	//ここのif文でシーン移行出来るかを判別
	//現在は0を押したときに移動タイトルへ
	if (input_->TriggerKey(DIK_I)) {
		flagChange_ = true;
	}
	//リトライする場合
	else if(input_->TriggerKey(DIK_O)) {
		flagChange_ = true;
		flagRetry_ = true;
	}

#pragma endregion
}

void GameOScene::Draw()
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

