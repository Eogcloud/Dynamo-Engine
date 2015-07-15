#include "vec2.h"

namespace dynamo{
	namespace math{
		
		vec2::vec2()
		{
			x = 0.0f;
			y = 0.0f;
		}

		vec2::vec2(const float& x, const float& y)
		{
			this->x = x;
			this->y = y;
		}

		vec2& vec2::add(const vec2& other)
		{
			x += other.x;
			y += other.y;
			return *this;
		}
			
		vec2& vec2::subtract(const vec2& other)
		{
			x -= other.x;
			y -= other.y;
			return *this;
		}
				
		vec2& vec2::multiply(const vec2& other)
		{
			x *= other.x;
			y *= other.y;
			return *this;
		}
				
		vec2& vec2::divide(const vec2& other)
		{
			x /= other.x;
			y /= other.y;
			return *this;
		}

		bool vec2::compare(const vec2& other)
		{
			if (x == other.x && y == other.y)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		bool vec2::notEqual(const vec2& other)
		{
			if (x == other.x && y == other.y)
			{
				return false;
			}
			else
			{
				return true;
			}
		}

		vec2& vec2::operator+=(const vec2& other)
		{
			return add(other);
		}
		
		vec2& vec2::operator-=(const vec2& other)
		{
			return subtract(other);
		}
		
		vec2& vec2::operator*=(const vec2& other)
		{
			return multiply(other);
		}
		
		vec2& vec2::operator/=(const vec2& other)
		{
			return divide(other);
		}

		bool vec2::operator==(const vec2& other)
		{
			return compare(other);
		}

		bool vec2::operator!=(const vec2& other)
		{
			return notEqual(other);
		}

		vec2& operator+(vec2& vecOne, const vec2& vecTwo)
		{
			return vecOne.add(vecTwo);
		}
		vec2& operator-(vec2& vecOne, const vec2& vecTwo)
		{
			return vecOne.subtract(vecTwo);
		}
		vec2& operator*(vec2& vecOne, const vec2& vecTwo)
		{
			return vecOne.multiply(vecTwo);
		}
		vec2& operator/(vec2& vecOne, const vec2& vecTwo)
		{
			return vecOne.divide(vecTwo);
		}

		std::ostream& operator<<(std::ostream& stream, const vec2& vector)
		{
			stream << "vec2: (" << vector.x << ", " << vector.y << ")" << std::endl;
		}
	}
}