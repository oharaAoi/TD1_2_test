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

	gravity_.x = 0.0f;
	gravity_.y = -4.0f;

	isJump_ = false;
	isFall_ = false;

	isAlive_ = true;

	leftGH_ = Novice::LoadTexture("./Resource/images/playerLeft.png");
	rightGH_ = Novice::LoadTexture("./Resource/images/player.png");
	GH_ = rightGH_;

	drawLt_.x = 0;
	drawLt_.y = 0;

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

	jumpSE_ = Novice::LoadAudio("./Resource/Sounds/jump.mp3");
	jumpSeHandle_ = -1;

	ClacVertex();

	ClacAddress();

}

void Player::Update(char* keys) {
	//=========================================
	ClacVertex();
	PreClacAddress();

	//=========================================
	PlayerMove(keys);
	
	PlayerFall();
	//=========================================

	ClacVertex();

	ClacAddress();

	//=========================================
	
	//=========================================

}

void Player::Draw() {

	if (isAlive_) {
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
	}

	if (isJump_) {
		PlayAudio(jumpSeHandle_, jumpSE_, 0.2f, false);
	}
}

void Player::MatricChange() {
	worldMatrix_ = MakeAffineMatrix(scall_, 0.0f, pos_);

	camera.MakeWvpVpMatrix(worldMatrix_, pos_);

	screenLt_ = Transform(localLt_, camera.GetWvpVpMatrix());
	screenRt_ = Transform(localRt_, camera.GetWvpVpMatrix());
	screenLb_ = Transform(localLb_, camera.GetWvpVpMatrix());
	screenRb_ = Transform(localRb_, camera.GetWvpVpMatrix());
}

void Player::PlayerMove(char* keys) {
	if (keys[DIK_A]) {
		pos_.x -= velocity_.x;
		GH_ = leftGH_;
	}

	if (keys[DIK_D]) {
		pos_.x += velocity_.x;
		GH_ = rightGH_;
	}

	if (keys[DIK_SPACE]) {
		if (!isFall_) {
			if (!isJump_) {
				isJump_ = true;
				isFall_ = true;
				velocity_.y = 16.0f;
			}
		}
	}
}

void Player::PlayerJump() {
	
}

void Player::PlayerFall() {
	if (isFall_) {
		velocity_.y += acceleration_.y;

		pos_.y += velocity_.y;

		if (velocity_.y < 0) {
			isJump_ = false;
		}
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
