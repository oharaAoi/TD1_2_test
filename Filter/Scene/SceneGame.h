#pragma once
#include <Novice.h>
#include "Scene.h"
#include "Player.h"
#include "Enemy.h"
#include "MapChip.h"
#include "Camera.h"
#include "CollisionManeger.h"

class SceneGame:
	public Scene{

private:

	Player player;

	Enemy enemy;

	Camera camera;

	MapChip mapChip;

	CollisionManeger collision;

public:

	SceneGame();
	~SceneGame();

	void Init()override;

	void Update()override;

	void Draw()override;

};

