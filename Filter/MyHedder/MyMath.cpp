#include "MyMath.h"

// 2点間の距離を求める
Vector2 Distance(Vector2 obj, Vector2 other) {
	Vector2 result{};
	result.x = obj.x - other.x;
	result.y = obj.y - other.y;

	return result;
}

//2点間の距離の大きさを求める
float Length(Vector2 obj) {
	float result{};

	return result = sqrtf(powf(obj.x, obj.y));
}

//正規化
void Normalize(Vector2& obj) {
	float length;
	length = Length(obj);

	if (length != 0) {
		obj.x = obj.x / length;
		obj.y = obj.y / length;
	}
}

float Clamp(float t, float start, float end) {
	if (t < start) {
		t = start;
	} else if (t > end) {
		t = end;
	}

	return t;
}

//外積を求め右にいるか判断する
float CrossProduct(Vector2 aVector, Vector2 bVector) {
	float dot;
	dot = aVector.x * bVector.y - aVector.y * bVector.x;

	return dot;
}
