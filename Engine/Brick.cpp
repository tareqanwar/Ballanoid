#include "Brick.h"

Brick::Brick(const RectF& in_rect, Color in_color)
	:
	rect(in_rect),
	color(in_color)
{
}

void Brick::Draw(Graphics& gfx) const
{
	if(!isDestroyed)
		gfx.DrawRect(rect, color);
}

bool Brick::DoBallCollision(Ball & ball)
{
	if (!isDestroyed && rect.IsOverlappingWith(ball.GetRect())) {
		ball.ReboundY();
		isDestroyed = true;
		return true;
	}
	return false;
}
