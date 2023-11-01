#include "CollisionManeger.h"

CollisionManeger::CollisionManeger(){
}

void CollisionManeger::PlayerCollision(Player& player, MapChip mapChip){

	if (mapChip.GetChipType(player.GetLtAdd().row, player.GetLtAdd().col) != NONE) {
		if (mapChip.GetChipType(player.GetLtAdd().row, player.GetLtAdd().col) != NONE) {

		}
	}
	
}
