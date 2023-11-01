#include "CollisionManeger.h"

CollisionManeger::CollisionManeger() {
}

void CollisionManeger::Init() {
	distance_.x = 0;
	distance_.y = 0;
}

void CollisionManeger::PlayerCollision(Player& player, MapChip& mapChip) {
	Vector2 block;
	Vector2 player_;

	//左上
	if (mapChip.GetChipType(player.GetLtAdd().row, player.GetLtAdd().col) != NONE) {
		player_ = player.GetPos();
		block = mapChip.GetPos(player.GetLtAdd().row, player.GetLtAdd().col);

		if (mapChip.GetChipType(player.GetPreLtAdd().row, player.GetLtAdd().col) != NONE) {
			distance_.x = (block.x + 16) - (player.GetPos().x - (player.GetWidth() / 2));

			player_.x += distance_.x;

			player.SetPos(player_);

		}else if (mapChip.GetChipType(player.GetLtAdd().row, player.GetPreLtAdd().col) != NONE) {
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
		}
	}

	//右上
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
		}
	}
}
