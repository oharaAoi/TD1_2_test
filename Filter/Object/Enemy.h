#pragma once
#include <Novice.h>
#include "MyVector2.h"
#include "Draw.h"
#include "Matrix.h"
#include "Camera.h"

struct Vertex {
		Vector2 lt;
		Vector2 rt;
		Vector2 lb;
		Vector2 rb;
};

class Enemy
{
private:

	Vector2 pos_;
	float width_;
	float height_;

	Vector2 size_;
	Vector2 scall_;

	bool isAlive_;

	Vector2 drawLt_;

	Vertex local_;
	Vertex world_;
	Vertex screen_;

	Vertex enemy_;

	int GH_;

	//各頂点のアドレス
	struct Address {
		int row;
		int col;
	};

	Address add_;

	//=========================================
	Matrix3x3 worldMatrix_;

	//=========================================
	Camera camera;

public:

	Enemy();

	void Init();
	void Update();
	void Draw();

	void MatrixChange(Vector2 pos);

	void ClacVertex(Vertex coordinate);

	void CalcVertex();

	void CalcAddress(Vector2 centerPos, Vector2 size);

	//
	Vector2 GetPos() { return pos_; }

	void SetIsAlive(bool isAlive) { isAlive_ = isAlive; }
	
	Address GetAddress() { return add_; }

	Vertex GetVertex() { return enemy_; }

};

