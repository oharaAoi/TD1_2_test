#include "CollisionManeger.h"

CollisionManeger::CollisionManeger() {
}

void CollisionManeger::Init() {
	distance_.x = 0;
	distance_.y = 0;
}

/*========================================================================================================
							プレイヤーとブロックの判定
==========================================================================================================*/
void CollisionManeger::PlayerCollision(Player& player, MapChip& mapChip) {
	Vector2 block;
	Vector2 player_;

	if (player.GetIsFall() == false) {
		if (player.GetRbAdd().row > 0 && player.GetLbAdd().row > 0) {
			if (mapChip.GetChipType(player.GetRbAdd().row - 1, player.GetRbAdd().col) == NONE
				&& mapChip.GetChipType(player.GetLbAdd().row - 1, player.GetLbAdd().col) == NONE) {
				if (player.GetIsFall() == false) {
					player.SetIsFall(true);
					player.SetVelocity(0.0f);
				}
			}
		}
	}

	//左上
	if (mapChip.GetChipType(player.GetLtAdd().row, player.GetLtAdd().col) != NONE) {
		player_ = player.GetPos();
		block = mapChip.GetPos(player.GetLtAdd().row, player.GetLtAdd().col);

		if (mapChip.GetChipType(player.GetPreLtAdd().row, player.GetLtAdd().col) != NONE) {
			distance_.x = (block.x + 16) - (player.GetPos().x - (player.GetWidth() / 2));

			player_.x += distance_.x;

			player.SetPos(player_);

		} else if (mapChip.GetChipType(player.GetLtAdd().row, player.GetPreLtAdd().col) != NONE) {
			distance_.y = (block.y - 16) - (player.GetPos().y + (player.GetWidth() / 2));

			player_.y += distance_.y;

			player.SetPos(player_);
		}
	}

	//右上
	if (mapChip.GetChipType(player.GetRtAdd().row, player.GetRtAdd().col) != NONE) {
		player_ = player.GetPos();
		block = mapChip.GetPos(player.GetRtAdd().row, player.GetRtAdd().col);

		if (mapChip.GetChipType(player.GetPreRtAdd().row, player.GetRtAdd().col) != NONE) {
			distance_.x = (block.x - 16) - (player.GetPos().x + (player.GetWidth() / 2));

			player_.x += distance_.x;

			player.SetPos(player_);

		} else if (mapChip.GetChipType(player.GetRtAdd().row, player.GetPreRtAdd().col) != NONE) {
			distance_.y = (block.y - 16) - (player.GetPos().y + (player.GetWidth() / 2));

			player_.y += distance_.y;

			player.SetPos(player_);
		}
	}

	//左下
	if (mapChip.GetChipType(player.GetLbAdd().row, player.GetLbAdd().col) != NONE) {
		player_ = player.GetPos();
		block = mapChip.GetPos(player.GetLbAdd().row, player.GetLbAdd().col);

		if (mapChip.GetChipType(player.GetPreLbAdd().row, player.GetLbAdd().col) != NONE) {
			distance_.x = (block.x + 16) - (player.GetPos().x - (player.GetWidth() / 2));

			player_.x += distance_.x;

			player.SetPos(player_);

		} else if (mapChip.GetChipType(player.GetLbAdd().row, player.GetPreLbAdd().col) != NONE) {
			distance_.y = (block.y + 16) - (player.GetPos().y - (player.GetWidth() / 2));

			player_.y += distance_.y;

			player.SetPos(player_);

			player.SetIsJump(false);
			player.SetIsFall(false);
			player.SetGravity(-4.0f);
		}
	}

	//右下
	if (mapChip.GetChipType(player.GetRbAdd().row, player.GetRbAdd().col) != NONE) {
		player_ = player.GetPos();
		block = mapChip.GetPos(player.GetRbAdd().row, player.GetRbAdd().col);

		if (mapChip.GetChipType(player.GetPreRbAdd().row, player.GetRbAdd().col) != NONE) {
			distance_.x = (block.x - 16) - (player.GetPos().x + (player.GetWidth() / 2));

			player_.x += distance_.x;

			player.SetPos(player_);

		} else if (mapChip.GetChipType(player.GetRbAdd().row, player.GetPreRbAdd().col) != NONE) {
			distance_.y = (block.y + 16) - (player.GetPos().y - (player.GetWidth() / 2));

			player_.y += distance_.y;

			player.SetPos(player_);

			player.SetIsJump(false);
			player.SetIsFall(false);
			player.SetGravity(-4.0f);
		}
	}
}

/*========================================================================================================
							プレイヤーとエネミーの判定(クリア条件)
==========================================================================================================*/
bool CollisionManeger::p2eCollision(Player& player, Enemy& enemy) {
	if (player.GetIsFall() == true) {
		//矩形と矩形の外積で判定を取る
		if (RectCollision(player.GetLb(), enemy.GetVertex())) {
			enemy.SetIsAlive(false);
			return true;
		}

		if (RectCollision(player.GetRb(), enemy.GetVertex())) {
			enemy.SetIsAlive(false);
			return true;
		}
	}

	return false;
}

/*========================================================================================================
							プレイヤーとエネミーの判定(ゲームオーバー条件)
==========================================================================================================*/
bool CollisionManeger::PlayerDethCollision(Player& player, Enemy& enemy) {
	if (player.GetIsFall() != true) {
		//矩形と矩形の外積で判定を取る
		if (RectCollision(player.GetLt(), enemy.GetVertex())) {
			player.SetIsAlive(false);
			return true;
		}

		if (RectCollision(player.GetRt(), enemy.GetVertex())) {
			player.SetIsAlive(false);
			return true;
		}

		if (RectCollision(player.GetLb(), enemy.GetVertex())) {
			player.SetIsAlive(false);
			return true;
		}

		if (RectCollision(player.GetRb(), enemy.GetVertex())) {
			player.SetIsAlive(false);
			return true;
		}
	} 

	return false;

}

/*========================================================================================================
							矩形の当たり判定
==========================================================================================================*/
bool CollisionManeger::RectCollision(Vector2 object, Vertex target) {
	Vector2 topVector;
	Vector2 bottomVector;
	Vector2 leftVector;
	Vector2 rightVector;

	Vector2 point2topVector;
	Vector2 point2bottomVector;
	Vector2 point2leftVector;
	Vector2 point2rightVector;

	topVector = Distance(target.lt, target.rt);
	bottomVector = Distance(target.rb, target.lb);
	leftVector = Distance(target.lb, target.lt);
	rightVector = Distance(target.rt, target.rb);

	point2topVector = Distance(object, target.rt);
	point2bottomVector = Distance(object, target.lb);
	point2leftVector = Distance(object, target.lt);
	point2rightVector = Distance(object, target.rt);

	if (CrossProduct(Distance(object, target.rt), Distance(target.lt, target.rt)) < 0) { return false; }
	if (CrossProduct(Distance(object, target.lb), Distance(target.rb, target.lb)) < 0) { return false; }
	if (CrossProduct(Distance(object, target.lt), Distance(target.lb, target.lt)) < 0) { return false; }
	if (CrossProduct(Distance(object, target.rt), Distance(target.rt, target.rb)) < 0) { return false; }

	return true;
}



