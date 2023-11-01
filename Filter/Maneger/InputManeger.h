#pragma once
#include <Novice.h>

class InputManeger
{

private:

	//シングルトンにする(他クラスでインスタンスを作成できない)
	InputManeger() {};
	~InputManeger() {};

	char keys_[256] = { 0 };
	char preKeys_[256] = { 0 };

public:

	InputManeger(const InputManeger& obj) = delete;
	InputManeger operator + (const InputManeger& obj) = delete;

	static InputManeger* GetInstance();

	void Update();

	char* GetKeys() { return keys_; }
	char* GetPrekeys() { return preKeys_; }

};

