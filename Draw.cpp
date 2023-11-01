#include "Draw.h"

void DrawSprite(Vector2 centerPos, float width, float height, Vector2 scall, int GH, unsigned int color) {
	Novice::DrawSprite(
		static_cast<int>(centerPos.x - width / 2),
		static_cast<int>(centerPos.y - height / 2),
		GH,
		scall.x,
		scall.y,
		0.0f,
		color
	);
}

void DrawQuad(Vector2 pos, float width, float height, Vector2 lt,
	int gh, Vector2 scall, unsigned int color) {
	Novice::DrawQuad(
		static_cast<int>((pos.x - (width / 2) * scall.x)),
		static_cast<int>((pos.y - (height / 2) * scall.y)),
		static_cast<int>((pos.x + (width / 2) * scall.x)),
		static_cast<int>((pos.y - (height / 2) * scall.y)),
		static_cast<int>((pos.x - (width / 2) * scall.x)),
		static_cast<int>((pos.y + (height / 2) * scall.y)),
		static_cast<int>((pos.x + (width / 2) * scall.x)),
		static_cast<int>((pos.y + (height / 2) * scall.y)),
		static_cast<int>(lt.x),
		static_cast<int>(lt.y),
		static_cast<int>(width),
		static_cast<int>(height),
		gh,
		color
	);
}