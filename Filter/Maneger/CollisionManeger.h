#pragma once
#include "Player.h"
#include "MapChip.h"
#include "MyVector2.h"

class CollisionManeger
{

private:

	Vector2 distance_;

public:

	CollisionManeger();

	void Init();

	void PlayerCollision(Player& player, MapChip& mapChip);

};

