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

bool Paddle::DoBallCollision(Ball& ball)
{
	if (!isCooldown) {
		const RectF rect = GetRect();

		if (rect.IsOverlappingWith(ball.GetRect())) {
			const Vec2 ballPosition = ball.GetPosition();

			if (std::signbit(ball.GetVelocity().x) == std::signbit((ballPosition - position).x))
				ball.ReboundY();
			else if (ballPosition.x >= rect.left && ballPosition.x <= rect.right)
				ball.ReboundY();
			else
				ball.ReboundX();

			isCooldown = true;
			return true;
		}
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

void Paddle::ResetCooldown()
{
	isCooldown = false;
}
