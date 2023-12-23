#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <assert.h>
#include "MyVector2.h"

struct Matrix3x3 {
	float m[3][3];
};

/*関数*/
/*拡縮行列*/
Matrix3x3 MakeScaleMatrix(Vector2 scale);

/*回転行列*/
Matrix3x3 MakeRotateMatrix(float theta);

/*平行移動行列*/
Matrix3x3 MakeTranslateMatrix(Vector2 translate);

/*アフィン*/
Matrix3x3 MakeAffineMatrix(Vector2 scale, float theta, Vector2 translate);

/*3x3の行列の積*/
Matrix3x3 Multiply(Matrix3x3 matrix1, Matrix3x3 matrix2);

/*2次元ベクトルを同次座標系として変換する*/
Vector2 Transform(Vector2 vector, Matrix3x3 matrix);

/*逆行列*/
Matrix3x3 Inverse(Matrix3x3 matrix);

//正射影行列
Matrix3x3 MakeOrthographicMatrix(float left, float top, float right, float bottom);

//ビューポート行列
Matrix3x3 MakeViewportMatrix(float left, float top, float width, float height);