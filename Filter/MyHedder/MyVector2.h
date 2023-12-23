#pragma once

class Vector2
{
public:

	float x;
	float y;

	Vector2();
	Vector2(float x, float y);

	//ベクトルの加算
	Vector2 operator+(const Vector2& obj)const {
		return Vector2(x + obj.x, y + obj.y);
	}

	Vector2 operator+=(const Vector2& obj) {
		x += obj.x;
		y += obj.y;
		return *this;
	}

	//ベクトルの減算
	Vector2 operator-(const Vector2& obj)const {
		return Vector2(x - obj.x, y - obj.y);
	}

	Vector2 operator-=(const Vector2& obj) {
		x -= obj.x;
		y -= obj.y;
		return *this;
	}

	//ベクトルの乗算
	Vector2 operator*(const Vector2& obj)const {
		return Vector2(x * obj.x, y * obj.y);
	}

	//ベクトルの除算
	Vector2 operator/(const Vector2& obj)const {
		return Vector2(x / obj.x, y / obj.y);
	}

	//ベクトルの代入
	/*Vector2 operator=(const Vector2& obj) {
		obj =

	}*/

};
