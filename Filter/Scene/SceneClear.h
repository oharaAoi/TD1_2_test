#pragma once
#include "Scene.h"
#include "Draw.h"
#include <Novice.h>

class SceneClear:
	public Scene{

private:

	int GH_;

	int pushBottomSE_;
	int pushBottomSeHandle_;

	int gemeClearSE_;
	int gemeClearSeHandle_;

public:

	SceneClear();

	void Init()override;

	void Update()override;

	void Draw()override;

	void GoTitle(char* keys, char* preKeys);

};

