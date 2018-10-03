#pragma once
#include "Graphics.h"
#include "RectF.h"
#include "Colors.h"
#include "Ball.h"

class Brick
{
public:
	Brick() = default;
	Brick(const RectF& in_rect, Color in_color);
	void Draw(Graphics& gfx) const;
	bool DoBallCollision(Ball& ball);
private:
	static constexpr float padding = 1.0f;
	RectF rect;
	Color color;
	bool isDestroyed = false;
};
