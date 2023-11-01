#pragma once
#include "Scene.h"
#include <Novice.h>

class SceneTitle:
	public Scene{

private:

public:

	SceneTitle();

	void Init()override;

	void Update()override;

	void Draw()override;

	void GameStart(char* keys);

};

