#include "InputManeger.h"

InputManeger* InputManeger::GetInstance() {
	static InputManeger instance;
	return &instance;
}

void InputManeger::Update() {
	//キーの入力を受け取る
	memcpy(preKeys_, keys_, 256);
	Novice::GetHitKeyStateAll(keys_);
}