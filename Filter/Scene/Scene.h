#pragma once
#include "InputManeger.h"

enum SceneNum {
	SCENE_TITLE,
	SCENE_GAME,
	SCENE_GAMEOVER,
	SCENE_CLEAR
};

class Scene
{
protected:

	InputManeger* inputManeger = InputManeger::GetInstance();

	static int sceneNo_;

	static bool sceneChange_;

public:

	virtual ~Scene() {};

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	int GetSceneNum() { return sceneNo_; }

	void SetSceneChange(bool isChange) { sceneChange_ = isChange; }
	bool GetSceneChange() { return sceneChange_; }

};

