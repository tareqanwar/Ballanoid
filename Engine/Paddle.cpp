#include "Paddle.h"

Paddle::Paddle(const Vec2& in_position, float in_halfWidth, float in_halfHeight)
	:
	position(in_position),
	halfWidth(in_halfWidth),
	halfHeight(in_halfHeight)
{
}

void Paddle::Draw(Graphics& gfx) const
{
	RectF rect = GetRect();
	gfx.DrawRect(rect, wingColor);

	rect.left += wingWidth;
	rect.right -= wingWidth;

	gfx.DrawRect(rect, color);
}

bool Paddle::DoBallCollision(Ball& ball) const
{
	if (ball.GetVelocity().y > 0.0f && GetRect().IsOverlappingWith(ball.GetRect())) {
		ball.ReboundY();
		return true;
	}
	return false;
}

void Paddle::DoWallCollision(const RectF& walls)
{
	const RectF rect = GetRect();

	if (rect.left < walls.left)
	{
		position.x += walls.left - rect.left;
	}
	else if (rect.right > walls.right)
	{
		position.x -= rect.right - walls.right;
	}
}

void Paddle::Update(const Keyboard& kbd, float dt)
{
	if (kbd.KeyIsPressed(VK_LEFT)) {
		position.x -= speed * dt;
	}
	if (kbd.KeyIsPressed(VK_RIGHT)) {
		position.x += speed * dt;
	}
}

RectF Paddle::GetRect() const
{
	return RectF::FormCenter(position, halfWidth, halfHeight);
}