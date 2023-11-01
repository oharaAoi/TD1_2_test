#pragma once
#include <Novice.h>
#include "MyVector2.h"
#include "Draw.h"
#include "Matrix.h"
#include "Camera.h"

class Player
{

private:

	Vector2 pos_;
	Vector2 scall_;
	float width_;
	float height_;

	Vector2 velocity_;
	Vector2 acceleration_;

	bool isJump_;

	int GH_;
	Vector2 drawLt_;
	Vector2 drawScall_;

	Vector2 lt_;
	Vector2 rt_;
	Vector2 lb_;
	Vector2 rb_;

	Vector2 localLt_;
	Vector2 localRt_;
	Vector2 localLb_;
	Vector2 localRb_;

	Vector2 screenLt_;
	Vector2 screenRt_;
	Vector2 screenLb_;
	Vector2 screenRb_;

	//=========================================
	//各頂点のアドレス
	struct Address {
		int row;
		int col;
	};

	Address ltAdd_;
	Address rtAdd_;
	Address lbAdd_;
	Address rbAdd_;

	Address preLtAdd_;
	Address preRtAdd_;
	Address preLbAdd_;
	Address preRbAdd_;

	//=========================================
	Matrix3x3 worldMatrix_;

	//=========================================
	Camera camera;

public:

	Player();

	void Init();

	void Update(char* keys);

	void Draw();

	void PlayerMove(char* keys);

	void PlayerJump();

	//各頂点の座標の計算
	void ClacVertex();

	//各頂点のアドレスの計算
	void ClacAddress();

	void PreClacAddress();

	/*アクセッサ*/

	void SetPos(Vector2 pos) { pos_ = pos; }
	Vector2 GetPos() { return pos_; }

	float GetWidth() { return width_; }
	float GetHeight() { return height_; }

	void SetIsJump(bool isJump) { isJump_ = isJump; }

	Vector2 GetLt() { return lt_; }
	Vector2 GetRt() { return rt_; }
	Vector2 GetLb() { return lb_; }
	Vector2 GetRb() { return rb_; }

	Address GetLtAdd() { return ltAdd_; }
	Address GetRtAdd() { return rtAdd_; }
	Address GetLbAdd() { return lbAdd_; }
	Address GetRbAdd() { return rbAdd_; }

	Address GetPreLtAdd() { return preLtAdd_; }
	Address GetPreRtAdd() { return preRtAdd_; }
	Address GetPreLbAdd() { return preLbAdd_; }
	Address GetPreRbAdd() { return preRbAdd_; }

	Matrix3x3 GetWorldMatrix(){return worldMatrix_;}
};

