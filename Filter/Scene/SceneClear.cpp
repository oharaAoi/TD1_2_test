#include "SceneClear.h"

SceneClear::SceneClear() { Init(); }

void SceneClear::Init(){

	GH_ = Novice::LoadTexture("./Resource/images/gameClear.png");

	pushBottomSE_ = Novice::LoadAudio("./Resource/sounds/pushButton.mp3");
	pushBottomSeHandle_ = -1;

	gemeClearSE_ = Novice::LoadAudio("./Resource/sounds/gameClear.mp3");
	gemeClearSeHandle_ = -1;

}

void SceneClear::Update(){

	GoTitle(inputManeger->GetKeys(), inputManeger->GetPrekeys());

}

void SceneClear::Draw(){

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

	if (gemeClearSeHandle_ == -1) {
		PlayAudio(gemeClearSeHandle_, gemeClearSE_, 0.2f, false);
	}

}

void SceneClear::GoTitle(char* keys, char* preKeys){
	if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
		sceneNo_ = SCENE_TITLE;
		sceneChange_ = true;
	}
}
