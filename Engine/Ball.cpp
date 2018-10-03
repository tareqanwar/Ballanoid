#include "Ball.h"
#include "SpriteCodex.h"

Ball::Ball(const Vec2& in_position, const Vec2& in_velocity)
	:
	position(in_position),
	velocity(in_velocity)
{
}

void Ball::Draw(Graphics & gfx) const
{
	SpriteCodex::DrawBall(position, gfx);
}

void Ball::Update(float dt)
{
	position += velocity * dt;
}

bool Ball::DoWallCollision(const RectF& walls)
{
	bool isColided = false;
	const RectF rect = GetRect();

	if (rect.left < walls.left) {
		position.x += walls.left - rect.left;
		ReboundX();
		isColided = true;
	}
	else if (rect.right > walls.right) {
		position.x -= rect.right - walls.right;
		ReboundX();
		isColided = true;
	}

	if (rect.top < walls.top) {
		position.y += walls.top - rect.top;
		ReboundY();
		isColided = true;
	}
	else if (rect.bottom > walls.bottom) {
		position.y -= rect.bottom - walls.bottom;
		ReboundY();
		isColided = true;
	}
	return isColided;
}

void Ball::ReboundX()
{
	velocity.x = -velocity.x;
}

void Ball::ReboundY()
{
	velocity.y = -velocity.y;
}

RectF Ball::GetRect() const
{
	return RectF::FormCenter(position, radius, radius);
}

Vec2 Ball::GetVelocity() const
{
	return velocity;
}

Vec2 Ball::GetPosition() const
{
	return position;
}
