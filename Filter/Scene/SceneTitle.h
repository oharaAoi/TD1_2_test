#pragma once
#include "Scene.h"
#include "Draw.h"
#include <Novice.h>

class SceneTitle:
	public Scene{

private:

	int GH_;

	int pushBottomSE_;
	int pushBottomSeHandle_;

public:

	SceneTitle();

	void Init()override;

	void Update()override;

	void Draw()override;

	void GameStart(char* keys, char* preKeys);

};

