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
	bool DoBallCollision(Ball& ball);
	void DoWallCollision(const RectF& walls);
	void Update(const Keyboard& kbd, float dt);
	RectF GetRect() const;
	void ResetCooldown();
private:
	static constexpr float wingWidth = 16.0f;
	static constexpr Color wingColor = Colors::Red;
	static constexpr Color color = Colors::White;
	static constexpr float speed = 350.0f;

	static constexpr float maximumExitRatio = 2.6f;
	static constexpr float fixedZoneWidthRatio = 0.2f;

	float exitXFactor;
	float fixedZoneHalfWidth;
	float fixedZoneExitX;

	float halfWidth;
	float halfHeight;
	Vec2 position;
	bool isCooldown = false;
};