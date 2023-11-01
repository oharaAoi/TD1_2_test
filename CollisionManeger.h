#pragma once
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

	void PlayerCollision(Player& player, MapChip mapChip);

};

