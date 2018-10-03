#pragma once

#include "Vec2.h"

class RectF
{
public:
	RectF() = default;
	RectF(float in_left, float in_right, float in_top, float in_bottom);
	RectF(const Vec2& topLeft, const Vec2& bottomRight);
	RectF(const Vec2& topLeft, float width, float height);
	bool IsOverlappingWith(const RectF& other) const;
	static RectF FormCenter(const Vec2& center, float halfWidth, float halfHeight);
public:
	float left;
	float right;
	float top;
	float bottom;
};