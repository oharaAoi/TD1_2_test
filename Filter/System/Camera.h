#pragma once
#include <Novice.h>
#include "Matrix.h"
#include "MyVector2.h"
#include "MyMath.h"

class Camera
{

private:

	Vector2 pos_;

	float left_;
	float top_;

	float right_;
	float bottom_;

	float width_;
	float height_;

	Matrix3x3 cameraWorldMatrix2{};

	//ビュー行列
	Matrix3x3 viewMatrix{};
	//正射影行列
	Matrix3x3 orthoMatrix{};
	//ビューポート行列
	Matrix3x3 viewportMatrix{};
	//結合行列
	Matrix3x3 wvpVpMatrix{};

public:

	Camera();

	void Init();

	void Draw();

	void CameraMove(Vector2 pos);

	void MakeWvpVpMatrix(Matrix3x3 matrix, Vector2 pos);

	Matrix3x3 GetWvpVpMatrix() { return wvpVpMatrix; }


};

