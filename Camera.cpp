#include "Camera.h"

Camera::Camera(){
	Init();
}

void Camera::Init() {

	pos_.x = 0.0f;
	pos_.y = 0.0f;

	left_ = -400.0f;
	top_ = 400.0f;

	right_ = 400.0f;
	bottom_ = -400.0f;

	width_ = 800.0f;
	height_ = 800.0f;

	cameraWorldMatrix2.m[0][0] = 1;
	cameraWorldMatrix2.m[1][1] = 1;
	cameraWorldMatrix2.m[2][0] = pos_.x;
	cameraWorldMatrix2.m[2][1] = pos_.y;
	cameraWorldMatrix2.m[2][2] = 1;
}

void Camera::CameraMove(Vector2 pos) {
	cameraWorldMatrix2.m[0][0] = 1;
	cameraWorldMatrix2.m[1][1] = 1;
	cameraWorldMatrix2.m[2][0] = pos.x;
	cameraWorldMatrix2.m[2][1] = pos.y;
	cameraWorldMatrix2.m[2][2] = 1;
}

void Camera::MakeWvpVpMatrix(Matrix3x3 matrix, Vector2 pos) {

	CameraMove(pos);

	//カメラのビュー行列を作成
	viewMatrix = Inverse(cameraWorldMatrix2);
	//カメラの正射影行列を作成
	orthoMatrix = MakeOrthographicMatrix(left_, top_, right_, bottom_);
	//カメラのビューポート行列を作成
	viewportMatrix = MakeViewportMatrix(0.0f, 0.0f, width_, height_);

	//行列を結合する
	wvpVpMatrix = Multiply(matrix, viewMatrix);
	wvpVpMatrix = Multiply(wvpVpMatrix, orthoMatrix);
	wvpVpMatrix = Multiply(wvpVpMatrix, viewportMatrix);
}

void Camera::Draw() {
	Novice::DrawBox(
		static_cast<int>(0),
		static_cast<int>(0),
		static_cast<int>(width_),
		static_cast<int>(height_),
		0.0f,
		0xFFFFFFFF,
		kFillModeWireFrame
	);
}