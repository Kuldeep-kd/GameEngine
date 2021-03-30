
#ifndef Types
#define Types
struct Vector2f
{
	double x, y;

	void operator+=(Vector2f Vector)
	{
		x += Vector.x;
		y += Vector.y;
	}
	void operator()(float X,float Y)
	{
		x = X;
		y = Y;
	}
	Vector2f& operator*(int Value)
	{
		Vector2f Temp;
		Temp.x = x * Value;
		Temp.y = y * Value;
		return Temp;
	}
	Vector2f& operator*(double Value)
	{
		Vector2f Temp;
		Temp.x = x * Value;
		Temp.y = y * Value;
		return Temp;
	}

	Vector2f& operator*(float Value)
	{
		Vector2f Temp;
		Temp.x = x * Value;
		Temp.y = y * Value;
		return Temp;
	}

	Vector2f& operator*(Vector2f Vector)
	{
		Vector2f Temp;
		Temp.x = x * Vector.x;
		Temp.y = y * Vector.y;
		return Temp;
	}
	Vector2f& operator/(int Value)
	{
		Vector2f Temp;
		Temp.x = x / Value;
		Temp.y = y / Value;
		return Temp;
	}
	Vector2f& operator/(Vector2f Vector)
	{
		Vector2f Temp;
		Temp.x = x / Vector.x;
		Temp.y = y / Vector.y;
		return Temp;
	}
	void operator*=(Vector2f Vector)
	{
		x *= Vector.x;
		y *= Vector.y;
	}
};


#endif