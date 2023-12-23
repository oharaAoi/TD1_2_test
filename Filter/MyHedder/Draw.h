#pragma once
#include <Novice.h>
#include "MyVector2.h"

void DrawSprite(Vector2 centerPos, float width, float height, Vector2 scall, int GH, unsigned int color);

void DrawQuad(Vector2 pos, float width, float height, Vector2 lt,
	int gh, Vector2 scall, unsigned int color);

void PlayAudio(int& voiceHandle, int soundHandle, float soundVolume, bool isLoop);