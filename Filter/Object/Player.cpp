#include "Player.h"

Player::Player() {
}

void Player::Init() {
	pos_.x = 48.0f;
	pos_.y = 48.0f;

	scall_.x = 1.0f;
	scall_.y = 1.0f;

	width_ = 32.0f;
	height_ = 32.0f;

	velocity_.x = 4.0f;
	velocity_.y = 4.0f;

	acceleration_.x = 0.0f;
	acceleration_.y = -0.8f;

	isJump_ = false;

	GH_ = Novice::LoadTexture("White1x1.png");
	drawLt_.x = 1;
	drawLt_.y = 1;

	drawScall_.x = 1.0f;
	drawScall_.y = 1.0f;

	localLt_.x = -16;
	localLt_.y = 16;

	localRt_.x = 16;
	localRt_.y = 16;

	localLb_.x = -16;
	localLb_.y = -16;

	localRb_.x = 16;
	localRb_.y = -16;

	screenLt_.x = 0.0f;
	screenLt_.y = 0.0f;
	screenRt_.x = 0.0f;
	screenRt_.y = 0.0f;
	screenLb_.x = 0.0f;
	screenLb_.y = 0.0f;
	screenRb_.x = 0.0f;
	screenRb_.y = 0.0f;

	ClacVertex();

	ClacAddress();

}

void Player::Update(char* keys) {
	//=========================================
	ClacVertex();
	PreClacAddress();

	//=========================================
	PlayerMove(keys);
	PlayerJump();

	//=========================================

	ClacVertex();

	ClacAddress();

	//=========================================
	
	//=========================================

}

void Player::Draw() {
	worldMatrix_ = MakeAffineMatrix(scall_, 0.0f, pos_);

	camera.MakeWvpVpMatrix(worldMatrix_, pos_);

	screenLt_ = Transform(localLt_, camera.GetWvpVpMatrix());
	screenRt_ = Transform(localRt_, camera.GetWvpVpMatrix());
	screenLb_ = Transform(localLb_, camera.GetWvpVpMatrix());
	screenRb_ = Transform(localRb_, camera.GetWvpVpMatrix());

	/*DrawQuad(
		pos_,
		width_,
		height_,
		drawLt_,
		GH_,
		drawScall_,
		0xFFFFFFFF
	);*/

	Novice::DrawQuad(
		static_cast<int>(screenLt_.x),
		static_cast<int>(screenLt_.y),
		static_cast<int>(screenRt_.x),
		static_cast<int>(screenRt_.y),
		static_cast<int>(screenLb_.x),
		static_cast<int>(screenLb_.y),
		static_cast<int>(screenRb_.x),
		static_cast<int>(screenRb_.y),
		static_cast<int>(drawLt_.x),
		static_cast<int>(drawLt_.y),
		static_cast<int>(width_),
		static_cast<int>(height_),
		GH_,
		0xFFFFFFFF
	);

	Novice::ScreenPrintf(10, 10, "player.pos.x:%f", pos_.x);
	Novice::ScreenPrintf(10, 30, "player.pos.y:%f", pos_.y);

	Novice::ScreenPrintf(10, 60, "player.ltAdd_:%d", ltAdd_.row);
	Novice::ScreenPrintf(10, 80, "player.preltAdd_:%d", preLtAdd_.row);

	Novice::ScreenPrintf(300, 10, "screenLt_.x:%f", screenLt_.x);
}

void Player::PlayerMove(char* keys) {
	if (keys[DIK_A]) {
		pos_.x -= velocity_.x;
	}

	if (keys[DIK_D]) {
		pos_.x += velocity_.x;
	}

	if (keys[DIK_W]) {
		pos_.y += velocity_.x;
	}

	if (keys[DIK_S]) {
		pos_.y -= velocity_.y;
	}

	if (keys[DIK_SPACE]) {
		if (!isJump_) {
			isJump_ = true;
			velocity_.y = 16.0f;
		}
	}
}

void Player::PlayerJump() {
	if (isJump_) {
		velocity_.y += acceleration_.y;

		pos_.y += velocity_.y;
	}
}

void Player::ClacVertex() {
	lt_.x = pos_.x - (width_ / 2);
	lt_.y = pos_.y + (height_ / 2);
	rt_.x = pos_.x + (width_ / 2);
	rt_.y = pos_.y + (height_ / 2);
	lb_.x = pos_.x - (width_ / 2);
	lb_.y = pos_.y - (height_ / 2);
	rb_.x = pos_.x + (width_ / 2);
	rb_.y = pos_.y - (height_ / 2);
}

void Player::ClacAddress() {
	ltAdd_.col = static_cast<int>(lt_.x / 32.0f);
	ltAdd_.row = static_cast<int>((lt_.y - 1.0f) / 32.0f);

	rtAdd_.col = static_cast<int>((rt_.x - 1.0f) / 32.0f);
	rtAdd_.row = static_cast<int>((rt_.y - 1.0f) / 32.0f);

	lbAdd_.col = static_cast<int>(lb_.x / 32.0f);
	lbAdd_.row = static_cast<int>((lb_.y) / 32.0f);

	rbAdd_.col = static_cast<int>((rb_.x - 1.0f) / 32.0f);
	rbAdd_.row = static_cast<int>(rb_.y / 32.0f);
}

void Player::PreClacAddress() {
	preLtAdd_.col = static_cast<int>(lt_.x / 32.0f);
	preLtAdd_.row = static_cast<int>((lt_.y - 1.0f) / 32.0f);

	preRtAdd_.col = static_cast<int>((rt_.x - 1.0f) / 32.0f);
	preRtAdd_.row = static_cast<int>((rt_.y - 1.0f) / 32.0f);

	preLbAdd_.col = static_cast<int>(lb_.x / 32.0f);
	preLbAdd_.row = static_cast<int>((lb_.y) / 32.0f);

	preRbAdd_.col = static_cast<int>((rb_.x - 1.0f) / 32.0f);
	preRbAdd_.row = static_cast<int>(rb_.y / 32.0f);

}
