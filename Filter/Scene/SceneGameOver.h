#pragma once
#include "Scene.h"
#include "Draw.h"
#include <Novice.h>

class SceneGameOver:
	public Scene{

private:

	int GH_;

	int pushBottomSE_;
	int pushBottomSeHandle_;

	int gameOverSE_;
	int gameOverSeHandle_;

public:
	SceneGameOver();
	~SceneGameOver();

	void Init()override;

	void Update()override;

	void Draw()override;

	void GoTitle(char* keys, char* preKeys);

};

