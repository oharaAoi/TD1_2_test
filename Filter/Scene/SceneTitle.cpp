#include "SceneTitle.h"

SceneTitle::SceneTitle(){
}

void SceneTitle::Init(){

	GH_ = Novice::LoadTexture("./Resource/images/title.png");

	pushBottomSE_ = Novice::LoadAudio("./Resource/sounds/pushButton.mp3");
	pushBottomSeHandle_ = -1;

}

void SceneTitle::Update(){
	GameStart(inputManeger->GetKeys(), inputManeger->GetPrekeys());
}

void SceneTitle::Draw(){
	Novice::DrawSprite(
		0,
		0,
		GH_,
		1.0f,
		1.0f,
		0.0f,
		0xFFFFFFFF
	);

	if (sceneChange_) {
		PlayAudio(pushBottomSeHandle_, pushBottomSE_, 0.2f, false);
	}
}

void SceneTitle::GameStart(char* keys, char* preKeys){
	if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
		sceneNo_ = SceneNum::SCENE_GAME;
		sceneChange_ = true;
	}
}
