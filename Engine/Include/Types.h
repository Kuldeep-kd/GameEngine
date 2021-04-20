
#ifndef Types
#define Types
#include <chrono>

namespace Engine
{

	struct Vector2i;
	struct Vector2f;

	//Thought of making it a custom template as all the float code is repeted for int
	//Do you think it is worth doing?
	//Or is will it make code too complicated for the users.
	//template<typename T>
	//class Vector2{
	//
	//}
	struct Vector2i
	{
		int x, y;
		void operator+=(Vector2i Vector)
		{
			x += Vector.x;
			y += Vector.y;
		}
		void operator()(int X, int Y)
		{
			x = X;
			y = Y;
		}
		Vector2i operator*(int Value)
		{
			Vector2i Temp;
			Temp.x = (float)x * Value;
			Temp.y = (float)y * Value;
			return Temp;
		}
		Vector2i operator*(double Value)
		{
			Vector2i Temp;
			Temp.x = x * Value;
			Temp.y = y * Value;
			return Temp;
		}

		Vector2i operator*(float Value)
		{
			Vector2i Temp;
			Temp.x = (float)x * Value;
			Temp.y = (float)y * Value;
			return Temp;
		}

		Vector2i operator*(Vector2i Vector)
		{
			Vector2i Temp;
			Temp.x = x * Vector.x;
			Temp.y = y * Vector.y;
			return Temp;
		}
		Vector2i operator/(int Value)
		{
			Vector2i Temp;
			Temp.x = x / Value;
			Temp.y = y / Value;
			return Temp;
		}
		Vector2i operator/(double Value)
		{
			Vector2i Temp;
			Temp.x = x / Value;
			Temp.y = y / Value;
			return Temp;
		}
		void operator*=(Vector2i Vector)
		{
			x *= Vector.x;
			y *= Vector.y;
		}
	};


	struct Vector2f
	{
		double x=0, y=0;

		void operator+=(Vector2f Vector)
		{
			x += Vector.x;
			y += Vector.y;
		}
		
		void operator+=(Vector2f* Vector)
		{
			x += Vector->x;
			y += Vector->y;
		}
		void operator()(float X, float Y)
		{
			x = X;
			y = Y;
		}
		template<class T>
		Vector2f operator*(T Value)
		{
			Vector2f Temp;
			Temp.x = x * Value;
			Temp.y = y * Value;
			return Temp;
		}
		/*Vector2f operator*(double Value)
		{
			Vector2f Temp;
			Temp.x = x * Value;
			Temp.y = y * Value;
			return Temp;
		}

		Vector2f operator*(float Value)
		{
			Vector2f Temp;
			Temp.x = x * Value;
			Temp.y = y * Value;
			return Temp;
		}*/

		Vector2f operator*(Vector2f Vector)
		{
			Vector2f Temp;
			Temp.x = x * Vector.x;
			Temp.y = y * Vector.y;
			return Temp;
		}
		Vector2f operator*(Vector2i Vector)
		{
			Vector2f Temp;
			Temp.x = x * Vector.x;
			Temp.y = y * Vector.y;
			return Temp;
		}
		Vector2f operator/(int Value)
		{
			Vector2f Temp;
			Temp.x = x / Value;
			Temp.y = y / Value;
			return Temp;
		}
		Vector2f operator/(double Value)
		{
			Vector2f Temp;
			Temp.x = x / Value;
			Temp.y = y / Value;
			return Temp;
		}
		Vector2f operator/(Vector2f Vector)
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




	//Provides timing solution for the engine. Might change in future.
	class Time
	{
	private:
		int delta;
		std::chrono::time_point<std::chrono::steady_clock> CurrentTime, PreviousTime;
		std::chrono::milliseconds Duration;
	public:

		Time() : delta(0), Duration(0)
		{
			//Init Previous time as it will be used directly after this.
			PreviousTime = std::chrono::steady_clock::now();
		}
		void Step()
		{
			CurrentTime = std::chrono::steady_clock::now();
			Duration = std::chrono::duration_cast<std::chrono::milliseconds>(CurrentTime - PreviousTime);
			delta = Duration.count();
			PreviousTime = CurrentTime;
		}
		//Returns time in seconds
		operator float()
		{
			return delta / 1000.0f;
		}
		//Accepts time in seconds
		void SetDelta(float newDelta)
		{
			delta = (int)newDelta;
		}
		//Accepts time in milliseconds
		void SetDelta(int newDelta)
		{
			delta = newDelta;
		}
	};

}

#endif