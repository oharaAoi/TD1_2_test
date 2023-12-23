#pragma once
#include "MyMath.h"
#include "MyVector2.h"
#define _USE_MATH_DEFINES
#include <math.h>

//2点間の距離を求める
Vector2 Distance(Vector2 obj, Vector2 other);

//2点間の距離の大きさを求める
float Length(Vector2 obj);

//正規化
void Normalize(Vector2& obj);

float Clamp(float t, float start, float end);


//外積を求め右にいるか判断する
float CrossProduct(Vector2 aVector, Vector2 bVector);