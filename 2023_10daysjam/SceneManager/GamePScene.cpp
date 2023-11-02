#include "GamePScene.h"


GamePScene::~GamePScene()
{
	delete player_;
	delete hpUi_;
	delete spUi_;
	delete timerUi_;

	//delete enemy_;

	for (PopEnemy* enemies : enemy_) {
		delete enemies;
	}
	
	
	/*
	for (PopItem* popItem : popItem_) {
		delete popItem;
	}
	*/

	delete popItem_;
}

void GamePScene::Initialize()
{
	CountNum_ = 0;
	player_ = new Player();
	player_->Initialize();


	hpUi_ = new HpUI();
	hpUi_->Initialize();

	spUi_ = new SpUI();
	spUi_->Initialize();

	timerUi_ = new TimerUI();
	timerUi_->Initialize();

	//PopItem* popItem = new PopItem();
	//popItem->Initialize();

	popItem_ = new PopItem();
	popItem_->Initialize();

}

void GamePScene::Update(char* keys, char* preKeys)
{
	switch (gameSModeNow_)
	{
	case None:

		if (!GameMove_) {
			//ここ押すと動き出す
			if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0) {
				GameMove_ = true;
			}

			if ((timerUi_->GetterTimer() <= 0) || ((player_->GetPlayerHp() <= 0) || (player_->GetPlayerSp() <= 0))) {
				flagChange_ = true;
			}

		}
		else {

			//敵の発生
			EnemyPoping();
			//プレイヤーの挙動
			player_->Update(keys, preKeys);

			for (PopEnemy* enemies : enemy_) {
					enemies->Update();
			}


			/*
			for (PopItem* popItem : popItem_) {
				popItem->Update();
			}
			*/
			if (!popItem_->IsDead()) {
				popItem_->Update();
			}

			//当たり判定
			CheckCollisionAll();

			//敵を消去してよいか
			EnemyDead();
			//アイテムを消してよいか
			ItemDead();

			hpUi_->Update(player_->GetPlayerDecreasedHp());

			spUi_->Update(player_->GetPlayerDecreasedSp());

			timerUi_->Update();

#pragma region シーン変更含む
			changeTimingFrame_++;

			///ポーズへ
			if ((preKeys[DIK_P] == 0 && keys[DIK_P] != 0) && changeTimingFrame_ >= 30) {
				GameMove_ = false;
				gameSModeNow_ = Pause;
				changeTimingFrame_ = 0;
			}
			//確認用
			CountNum_ += 1;
			///シーン変換
#ifdef _DEBUG
			//ここのif文でシーン移行出来るかを判別
			//現在はIを押したときに移動
			if ((preKeys[DIK_I] == 0 && keys[DIK_I] != 0) && changeTimingFrame_ >= 30) {
				flagChange_ = true;
				changeTimingFrame_ = 0;
			}
			//ここのif文でシーン移行出来るかを判別
			//現在はOを押したときに移動(がめおべ)
			if ((preKeys[DIK_O] == 0 && keys[DIK_O] != 0) && changeTimingFrame_ >= 30) {
				flagChange_ = true;
				flagGameOver_ = true;
				changeTimingFrame_ = 0;
			}
#endif // DEBUG

			if (timerUi_->GetterTimer() <= 0) {
				//flagChange_ = true;
				changeTimingFrame_ = 0;
				GameMove_ = false;
			}
			//ここのif文でシーン移行出来るかを判別
			//現在はOを押したときに移動(がめおべ)
			if ((player_->GetPlayerHp() <= 0) || (player_->GetPlayerSp() <= 0)) {
				//flagChange_ = true;
				flagGameOver_ = true;
				changeTimingFrame_ = 0;
				GameMove_ = false;
			}

#pragma endregion 
		}

		break;

	case Pause:

		changeTimingFrame_++;
		//解除
		if ((preKeys[DIK_P] == 0 && keys[DIK_P] != 0) && changeTimingFrame_ >= 30) {
			GameMove_ = true;
			gameSModeNow_ = None;
			changeTimingFrame_ = 0;
		}
		break;

	default:
		break;
	}


#ifdef _DEBUG
#pragma region ImGui関連

	ImGui::Begin("GameMove&Mode");
	ImGui::Text("GameMove_ %d\n0_Stop Butten[DIK_SPACE]\n", GameMove_);
	ImGui::Text("gameSModeNow_ %d\n0_None 1_Pause Butten[DIK_P]\n", gameSModeNow_);
	ImGui::End();

	ImGui::Begin("EnemyPop");
	ImGui::Text("EnemyPop %d\n", EnemyPopFrame_);
	ImGui::End();


#pragma endregion
#endif // DEBUG
}


void GamePScene::Draw()
{
	switch (gameSModeNow_)
	{
	case None:

		break;

	default:
		break;
	}

	player_->Draw();
	//enemy_->Draw();


	for (PopEnemy* enemies : enemy_) {

		//if (enemies->GetIsDead()) {
			enemies->Draw();
		//}
		
	}

	/*for (PopItem* popItem : popItem_) {
		popItem->Draw();
	}*/

	if (!popItem_->IsDead()) {
		popItem_->Draw();
	}

	Novice::ScreenPrintf(500, 500, "%d", CountNum_);
	Novice::ScreenPrintf(500, 550, "%d", changeTimingFrame_);


#pragma region UI関連(一番前に写す)
	hpUi_->Draw();
	spUi_->Draw();
	timerUi_->Draw();

#pragma endregion
}

void GamePScene::CheckCollisionAll()
{

	//const std::list<PlayerLAttack*>& playerLA = player_->GetBullet();
	PlayerMAttack* playerMA = player_->GetMAttack();
	//アイテム(複数)

#pragma region プレイヤー本体と敵本体
	//player_->OnCollision();
	for (PopEnemy* enemies : enemy_) {

		if (IsCollision(player_, enemies) == true) {
			float damege = 10.0f;
			player_->OnCollision(damege);
			//enemies->
		}
		//enemies;

		
	}
#pragma endregion

#pragma region プレイヤー近距離と敵本体
	for (PopEnemy* enemies : enemy_) {
		//CheckCollision(playerMA,);

	}
#pragma endregion

#pragma region プレイヤー遠距離と敵本体
	//for(えねみーとえんきょり)
	/*
	for (PlayerLAttack* playerLAtteck : playerLAttacks) {
			//CheckCollision(playerLAtteck, );
	}
	*/
#pragma endregion

#pragma region プレイヤー本体とアイテム
	//for(アイテム)
	//CheckCollision(player_,);
#pragma endregion
}

/*没
void GamePScene::CheckCollision(Object* ObjectA, Object* ObjectB)
{
	if (CircleCollision(ObjectA->GetPosX(), ObjectA->GetPosY(), ObjectA->GetRadish(), ObjectB->GetPosX(), ObjectB->GetPosY(), ObjectB->GetRadish()))
	{
		ObjectA->OnCollision();
		ObjectB->OnCollision();
	}
}
*/

void GamePScene::ItemDead()
{
	/*
	lAttack_.remove_if([](PlayerLAttack* lAttack) {
		if (lAttack->IsDead()) {
			delete lAttack;
			return true;
		}

		return false;
		});
	*/

	/*
	if (popItem_->IsDead()) {
		delete popItem_;
	}
	*/
}

void GamePScene::EnemyDead()
{
	enemy_.remove_if([](PopEnemy* enemies) {
		if (enemies->GetIsDead()) {
			delete enemies;
			return true;
		}

		return false;
		});
	
}

void GamePScene::EnemyPoping()
{
	EnemyPopFrame_++;

	if (EnemyPopFrame_ >= consEnemyPopFrame_) {

		
		PopEnemy* newEnemy = new PopEnemy();
		newEnemy->Initialize();
		enemy_.push_back(newEnemy);
		

		EnemyPopFrame_ = 0;

	}
}
