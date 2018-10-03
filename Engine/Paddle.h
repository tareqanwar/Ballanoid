#pragma once
#include "Graphics.h"
#include "Vec2.h"
#include "RectF.h"
#include "Colors.h"
#include "Ball.h"
#include "Keyboard.h"

class Paddle
{
public:
	Paddle(const Vec2& in_position, float in_halfWidth, float in_halfHeight);
	void Draw(Graphics& gfx) const;
	bool DoBallCollision(Ball& ball) const;
	void DoWallCollision(const RectF& walls);
	void Update(const Keyboard& kbd, float dt);
	RectF GetRect() const;
private:
	Color color = Colors::White;
	float speed = 300.0f;
	float halfWidth;
	float halfHeight;
	Vec2 position;
};