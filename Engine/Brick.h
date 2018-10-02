#pragma once
#include "Graphics.h"
#include "RectF.h"
#include "Colors.h"

class Brick
{
public:
	Brick(const RectF& in_rect, Color in_color);
	void Draw(Graphics& gfx) const;
private:
	RectF rect;
	Color color;
	bool isDestroyed = false;
};
