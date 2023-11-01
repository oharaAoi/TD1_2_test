#include "SceneGame.h"

SceneGame::SceneGame(){
}

SceneGame::~SceneGame() {
}

void SceneGame::Init(){
	player.Init();
	camera.Init();
	mapChip.Init();
	collision.Init();
}

void SceneGame::Update(){
	player.Update(inputManeger->GetKeys());

	collision.PlayerCollision(player, mapChip);

	camera.CameraMove(player.GetPos());

	mapChip.Update(player.GetPos());
}

void SceneGame::Draw(){

	mapChip.Draw();

	player.Draw();

	camera.Draw();

	Novice::ScreenPrintf(10, 10, "sceneNo_:%d", sceneNo_);

}
