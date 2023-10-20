#include "TitleScene.h"

TitleScene::TitleScene() {}

TitleScene::~TitleScene() {}

void TitleScene::Initialize()
{
	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();
}

void TitleScene::Update()
{


	switch (titleSModeNow_)
	{
	case None:


		//ここのif文でシーン移行出来るかを判別
		//現在はIを押したときに移動
		if (input_->TriggerKey(DIK_I)) {
			flagChange_ = true;
		}

		break;

	case Expriense:

		break;
		/*今は多分いらん
			case Option:
				break;*/
	default:
		break;
	}
}

void TitleScene::Draw()
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


