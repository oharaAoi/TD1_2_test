#include "MapChip.h"

MapChip::MapChip() {

	row_ = static_cast<int>(mapAdd_.size());
	col_ = static_cast<int>(mapAdd_[0].size());

	std::reverse(mapAdd_.begin(), mapAdd_.end());

	mapChip_ = new Base * [row_];
	for (int i = 0; i < row_; i++) {
		mapChip_[i] = new Base[col_];
	}
}

MapChip::~MapChip() {
	// メモリを解放
	for (int i = 0; i < row_; i++) {
		delete[] mapChip_[i];
	}
	delete[] mapChip_;

}

void MapChip::Init() {
	local.lt.x = -16;
	local.lt.y = 16;

	local.rt.x = 16;
	local.rt.y = 16;

	local.lb.x = -16;
	local.lb.y = -16;

	local.rb.x = 16;
	local.rb.y = -16;

	screen = {
		{0,0},
		{0,0},
		{0,0},
		{0,0}
	};

	size_.x = 32.0f;
	size_.y = 32.0f;

	for (int row = 0; row < row_; row++) {
		for (int col = 0; col < col_; col++) {
			mapChip_[row][col].width = 32;
			mapChip_[row][col].height = 32;

			mapChip_[row][col].pos.x = (mapChip_[row][col].width * col) + 16;
			mapChip_[row][col].pos.y = (mapChip_[row][col].height * row) + 16;

			mapChip_[row][col].scall.x = 1.0f;
			mapChip_[row][col].scall.y = 1.0f;

			mapChip_[row][col].screenLt.x = 0.0f;
			mapChip_[row][col].screenLt.y = 0.0f;

			mapChip_[row][col].screenRt.x = 0.0f;
			mapChip_[row][col].screenRt.y = 0.0f;

			mapChip_[row][col].screenLt.x = 0.0f;
			mapChip_[row][col].screenLt.y = 0.0f;

			mapChip_[row][col].screenRb.x = 0.0f;
			mapChip_[row][col].screenRb.y = 0.0f;

			if (mapAdd_[row][col] == NONE) {
				mapChip_[row][col].type_ = NONE;
			} else {
				mapChip_[row][col].type_ = BLOCK;
			}
		}
	}

	GH_ = Novice::LoadTexture("./Resource/images/block.png");

}

void MapChip::Update(Vector2 pos) {
	for (int row = 0; row < row_; row++) {
		for (int col = 0; col < col_; col++) {
			worldMatrix_ = MakeAffineMatrix(mapChip_[row][col].scall, 0.0f, mapChip_[row][col].pos);

			camera.MakeWvpVpMatrix(worldMatrix_, pos);

			mapChip_[row][col].screenLt = Transform(local.lt, camera.GetWvpVpMatrix());
			mapChip_[row][col].screenRt = Transform(local.rt, camera.GetWvpVpMatrix());
			mapChip_[row][col].screenLb = Transform(local.lb, camera.GetWvpVpMatrix());
			mapChip_[row][col].screenRb = Transform(local.rb, camera.GetWvpVpMatrix());
		}
	}
}

void MapChip::Draw() {
	
	for (int row = 0; row < row_; row++) {
		for (int col = 0; col < col_; col++) {
			if (mapAdd_[row][col] == 1) {
				Novice::DrawQuad(
					static_cast<int>(mapChip_[row][col].screenLt.x),
					static_cast<int>(mapChip_[row][col].screenLt.y),
					static_cast<int>(mapChip_[row][col].screenRt.x),
					static_cast<int>(mapChip_[row][col].screenRt.y),
					static_cast<int>(mapChip_[row][col].screenLb.x),
					static_cast<int>(mapChip_[row][col].screenLb.y),
					static_cast<int>(mapChip_[row][col].screenRb.x),
					static_cast<int>(mapChip_[row][col].screenRb.y),
					0,
					0,
					32,
					32,
					GH_,
					0xFFFFFFFF
				);
			}
		}
	}
}
