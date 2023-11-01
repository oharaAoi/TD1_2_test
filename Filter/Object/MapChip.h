#pragma once
#include <Novice.h>
#include <vector>
#include <string>

#include "MyVector2.h"
#include "LoadCsv.h"
#include "Matrix.h"
#include "Camera.h"

enum ChipType {
	NONE,
	BLOCK
};

class MapChip
{

private:

	int GH_;

	//=================================
	
	std::vector<std::vector<int>>mapAdd_ = LoadFile("./Resource/map/mapSample.csv");

	int row_;
	int col_;

	Vector2 size_;

	struct Base {
		Vector2 pos;
		Vector2 scall;
		float width;
		float height;

		ChipType type_;

		Vector2 worldLt;
		Vector2 worldRt;
		Vector2 worldLb;
		Vector2 worldrb;

		Vector2 screenLt;
		Vector2 screenRt;
		Vector2 screenLb;
		Vector2 screenRb;
	};

	Base** mapChip_;

	struct Vertex {
		Vector2 lt;
		Vector2 rt;
		Vector2 lb;
		Vector2 rb;
	};

	Vertex local;
	Vertex screen;

	//=========================================
	Matrix3x3 worldMatrix_;

	//=========================================
	Camera camera;

public:

	MapChip();
	~MapChip();

	void Init();
	void Update(Vector2 pos);
	void Draw();

	/*アクセッサ*/

	Vector2 GetPos(int row, int col) { return mapChip_[row][col].pos; }

	Vector2 GetSize() { return size_; }

	ChipType GetChipType(int row, int col) { return mapChip_[row][col].type_; }

	Matrix3x3 GetWorldMatrix() { return worldMatrix_; }

};

