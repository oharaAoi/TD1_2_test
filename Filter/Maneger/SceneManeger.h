#pragma once
#include <memory>
#include "Scene.h"
#include "SceneTitle.h"
#include "SceneGame.h"

class SceneManeger
{

private:

	std::unique_ptr<Scene> sceneArr_[2];

	int sceneNo_;

public:

	SceneManeger();

	void Update();

};

