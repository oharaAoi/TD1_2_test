#pragma once
#include "Player.h"
#include "Enemy.h"
#include "MapChip.h"
#include "MyVector2.h"
#include "MyMath.h"

class CollisionManeger
{

private:

	Vector2 distance_;

public:

	CollisionManeger();

	void Init();

	void PlayerCollision(Player& player, MapChip& mapChip);

	bool p2eCollision(Player& player, Enemy& enemy);

	bool PlayerDethCollision(Player& player, Enemy& enemy);

	bool RectCollision(Vector2 object, Vertex target);

};

