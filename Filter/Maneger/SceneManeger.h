#pragma once
#include <memory>
#include "Scene.h"
#include "SceneTitle.h"
#include "SceneGame.h"
#include "SceneGameOver.h"
#include "SceneClear.h"

class SceneManeger
{

private:

	std::unique_ptr<Scene> sceneArr_[4];

	int sceneNo_;

public:

	SceneManeger();

	void Update();

};

