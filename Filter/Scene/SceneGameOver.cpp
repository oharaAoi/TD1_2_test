#include "SceneGameOver.h"

SceneGameOver::SceneGameOver() { Init(); }

SceneGameOver::~SceneGameOver(){}

void SceneGameOver::Init(){

	GH_ = Novice::LoadTexture("./Resource/images/gameOver.png");

	pushBottomSE_ = Novice::LoadAudio("./Resource/sounds/pushButton.mp3");
	pushBottomSeHandle_ = -1;

	gameOverSE_ = Novice::LoadAudio("./Resource/sounds/gameOver.mp3");
	gameOverSeHandle_ = -1;

}

void SceneGameOver::Update() {

	GoTitle(inputManeger->GetKeys(), inputManeger->GetPrekeys());

}

void SceneGameOver::Draw(){

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

	if (gameOverSeHandle_ == -1) {
		PlayAudio(gameOverSeHandle_, gameOverSE_, 0.2f, false);
	}

}

void SceneGameOver::GoTitle(char* keys, char* preKeys) {

	if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
		sceneNo_ = SCENE_TITLE;
		sceneChange_ = true;
	}

}