#pragma once


class Vector2
{
public:
	Vector2();
	Vector2(int X, int Y);


	Vector2 operator+= (Vector2 other);
	Vector2 operator+ (Vector2 other);
	Vector2 operator-= (Vector2 other);
	Vector2 operator- (Vector2 other);

private:
	int X, Y;
};


