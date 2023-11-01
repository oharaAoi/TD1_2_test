#include "SceneTitle.h"

SceneTitle::SceneTitle(){
}

void SceneTitle::Init(){
}

void SceneTitle::Update(){
	GameStart(inputManeger->GetKeys());
}

void SceneTitle::Draw(){
	Novice::ScreenPrintf(10, 10, "sceneNo_:%d", sceneNo_);
}

void SceneTitle::GameStart(char* keys){
	if (keys[DIK_SPACE]) {
		sceneNo_ = SceneNum::SCENE_GAME;
		sceneChange_ = true;
	}
}
