#include "Brick.h"
#include <assert.h>

Brick::Brick(const RectF& in_rect, Color in_color)
	:
	rect(in_rect),
	color(in_color)
{
}

void Brick::Draw(Graphics& gfx) const
{
	if(!isDestroyed)
		gfx.DrawRect(rect.GetExpanded(-padding), color);
}

bool Brick::CheckBallCollision(const Ball & ball) const
{
	return !isDestroyed && rect.IsOverlappingWith(ball.GetRect());
}

void Brick::ExecuteBallCollision(Ball & ball)
{
	assert(CheckBallCollision(ball));

	if (CheckBallCollision(ball)) {
		const Vec2 ballPosition = ball.GetPosition();
		if (ballPosition.x >= rect.left && ballPosition.x <= rect.right)
			ball.ReboundY();
		else
			ball.ReboundX();

		isDestroyed = true;
	}
}

Vec2 Brick::GetCenter() const
{
	return rect.GetCenter();
}
