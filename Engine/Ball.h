#pragma once
#include "Vec2.h"
#include "Graphics.h"

class Ball
{
public:
	Ball(const Vec2& in_position, const Vec2& in_direction);
	void Draw(Graphics& gfx) const;
	void Update(float dt);
	bool DoWallCollision(const RectF& walls);
	void ReboundX();
	void ReboundY();
	RectF GetRect() const;
	Vec2 GetVelocity() const;
	Vec2 GetPosition() const;
	void SetDirection(const Vec2& direction);
private:
	static constexpr float radius = 7.0f;
	float speed = 400.0f;
	Vec2 position;
	Vec2 velocity;
};
