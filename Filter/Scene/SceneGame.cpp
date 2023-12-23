#include "SceneGame.h"

SceneGame::SceneGame(){
}

SceneGame::~SceneGame() {
}

/*========================================================================================================
										初期化処理
==========================================================================================================*/
void SceneGame::Init(){
	player.Init();
	enemy.Init();
	camera.Init();
	mapChip.Init();
	collision.Init();
}

/*========================================================================================================
										更新処理
==========================================================================================================*/
void SceneGame::Update(){
	/* --------------------------- oblectの更新 --------------------------- */
	player.Update(inputManeger->GetKeys());

	enemy.Update();

	mapChip.Update(inputManeger->GetKeys());

	/* --------------------------- oblectの当たり判定 --------------------------- */
	collision.PlayerCollision(player, mapChip);


	if (collision.p2eCollision(player, enemy)) {
		sceneNo_ = SCENE_CLEAR;
		sceneChange_ = true;
	}

	if (collision.PlayerDethCollision(player, enemy)) {
		sceneNo_ = SCENE_GAMEOVER;
		sceneChange_ = true;
	}

	/* --------------------------- oblectの座標変換 --------------------------- */
	camera.CameraMove(player.GetPos());
	player.MatricChange();
	enemy.MatrixChange(player.GetPos());
	mapChip.MartixChange(player.GetPos());
}

/*========================================================================================================
										描画処理
==========================================================================================================*/
void SceneGame::Draw(){

	mapChip.Draw();

	player.Draw();

	enemy.Draw();

	camera.Draw();

}
