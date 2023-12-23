#include "SceneManeger.h"

SceneManeger::SceneManeger() {
	sceneArr_[SCENE_TITLE] = std::make_unique<SceneTitle>();
	sceneArr_[SCENE_GAME] = std::make_unique<SceneGame>();
	sceneArr_[SCENE_GAMEOVER] = std::make_unique<SceneGameOver>();
	sceneArr_[SCENE_CLEAR] = std::make_unique<SceneClear>();

	sceneNo_ = SCENE_TITLE;
	sceneArr_[sceneNo_]->Init();
}

void SceneManeger::Update() {

	sceneNo_ = sceneArr_[sceneNo_]->GetSceneNum();

	if (sceneArr_[sceneNo_]->GetSceneChange() == true) {
		sceneArr_[sceneNo_]->Init();
		sceneArr_[sceneNo_]->SetSceneChange(false);
	}

	sceneArr_[sceneNo_]->Update();

	sceneArr_[sceneNo_]->Draw();

}