#include "Vector2.h"

Vector2::Vector2()
{
	this->X = 0;
	this->Y = 0;
}


Vector2::Vector2(int X, int Y)
{
	this->X = X;
	this->Y = Y;
}

Vector2 Vector2::operator+= (Vector2 other) {
	return *this + other;
}

Vector2 Vector2::operator+ (Vector2 other) {
	Vector2 result = *this;
	result.X += other.X;
	result.Y += other.Y;
}

Vector2 Vector2::operator+= (Vector2 other) {
	return *this - other;
}

Vector2 Vector2::operator- (Vector2 other) {
	Vector2 result = *this;
	result.X -= other.X;
	result.Y -= other.Y;
}

