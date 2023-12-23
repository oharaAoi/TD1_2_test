#include "Enemy.h"

Enemy::Enemy(){
}

void Enemy::Init(){

	pos_.x = 976.0f;
	pos_.y = 464.0f;

	width_ = 64.0f;
	height_ = 64.0f;

	size_.x = 32.0f;
	size_.y = 32.0f;

	isAlive_ = true;

	scall_.x = 1.0f;
	scall_.y = 1.0f;

	drawLt_.x = 0;
	drawLt_.y = 0;

	local_.lt.x = -16.0f;
	local_.lt.y = 16.0f;

	local_.rt.x = 16.0f;
	local_.rt.y = 16.0f;

	local_.lb.x = -16.0f;
	local_.lb.y = -16.0f;

	local_.rb.x = 16.0f;
	local_.rb.y = -16.0f;

	ClacVertex(world_);
	ClacVertex(screen_);
	CalcVertex();
	CalcAddress(pos_, size_);

	GH_ = Novice::LoadTexture("./Resource/images/tori.png");

}

void Enemy::Update(){

	CalcAddress(pos_, size_);

	CalcVertex();

	//=================================================-

}

void Enemy::Draw(){
	if (isAlive_) {
		Novice::DrawQuad(
			static_cast<int>(screen_.lt.x),
			static_cast<int>(screen_.lt.y),
			static_cast<int>(screen_.rt.x),
			static_cast<int>(screen_.rt.y),
			static_cast<int>(screen_.lb.x),
			static_cast<int>(screen_.lb.y),
			static_cast<int>(screen_.rb.x),
			static_cast<int>(screen_.rb.y),
			static_cast<int>(drawLt_.x),
			static_cast<int>(drawLt_.y),
			static_cast<int>(width_),
			static_cast<int>(height_),
			GH_,
			0xFFFFFFFF
		);
	}
}

void Enemy::MatrixChange(Vector2 pos) {
	worldMatrix_ = MakeAffineMatrix(scall_, 0.0f, pos_);

	camera.MakeWvpVpMatrix(worldMatrix_, pos);

	screen_.lt = Transform(local_.lt, camera.GetWvpVpMatrix());
	screen_.rt = Transform(local_.rt, camera.GetWvpVpMatrix());
	screen_.lb = Transform(local_.lb, camera.GetWvpVpMatrix());
	screen_.rb = Transform(local_.rb, camera.GetWvpVpMatrix());
}

void Enemy::ClacVertex(Vertex coordinate) {
	coordinate.lt.x = pos_.x - (width_ / 2);
	coordinate.lt.y = pos_.y + (height_ / 2);
	coordinate.rt.x = pos_.x + (width_ / 2);
	coordinate.rt.y = pos_.y + (height_ / 2);
	coordinate.lb.x = pos_.x - (width_ / 2);
	coordinate.lb.y = pos_.y - (height_ / 2);
	coordinate.rb.x = pos_.x + (width_ / 2);
	coordinate.rb.y = pos_.y - (height_ / 2);
}

void Enemy::CalcVertex() {

	enemy_.lt.x = pos_.x - size_.x / 2;
	enemy_.lt.y = pos_.y - size_.y / 2;

	enemy_.rt.x = pos_.x + size_.x / 2;
	enemy_.rt.y = pos_.y - size_.y / 2;

	enemy_.lb.x = pos_.x - size_.x / 2;
	enemy_.lb.y = pos_.y + size_.y / 2;

	enemy_.rb.x = pos_.x + size_.x / 2;
	enemy_.rb.y = pos_.y + size_.y / 2;

}

void Enemy::CalcAddress(Vector2 centerPos, Vector2 size) {
	add_.row = static_cast<int>(centerPos.y / size.y);
	add_.col = static_cast<int>(centerPos.x / size.x);
}