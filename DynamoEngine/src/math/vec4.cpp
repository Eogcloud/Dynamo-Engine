#include "vec4.h"

namespace dynamo{
	namespace math{
		
		vec4::vec4()
		{
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
			w = 0.0f;
		}

		vec4::vec4(const float& x, const float& y, const float& z, const float& w)
		{
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}

		vec4& vec4::add(const vec4& other)
		{
			x += other.x;
			y += other.y;
			z += other.z;
			w += other.w;
			return *this;
		}
			
		vec4& vec4::subtract(const vec4& other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
			w -= other.w;
			return *this;
		}
				
		vec4& vec4::multiply(const vec4& other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;
			w *= other.w;
			return *this;
		}
				
		vec4& vec4::divide(const vec4& other)
		{
			x /= other.x;
			y /= other.y;
			z /= other.z;
			w /= other.w;
			return *this;
		}

		bool vec4::compare(const vec4& other)
		{
			if (x == other.x && y == other.y && z == other.z && w == other.w)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		bool vec4::notEqual(const vec4& other)
		{
			if (x == other.x && y == other.y && z == other.z && w == other.w)
			{
				return false;
			}
			else
			{
				return true;
			}
		}

		vec4& vec4::operator+=(const vec4& other)
		{
			return add(other);
		}
		
		vec4& vec4::operator-=(const vec4& other)
		{
			return subtract(other);
		}
		
		vec4& vec4::operator*=(const vec4& other)
		{
			return multiply(other);
		}
		
		vec4& vec4::operator/=(const vec4& other)
		{
			return divide(other);
		}

		bool vec4::operator==(const vec4& other)
		{
			return compare(other);
		}

		bool vec4::operator!=(const vec4& other)
		{
			return notEqual(other);
		}

		vec4& operator+(vec4 vecOne, const vec4& vecTwo)
		{
			return vecOne.add(vecTwo);
		}
		vec4& operator-(vec4 vecOne, const vec4& vecTwo)
		{
			return vecOne.subtract(vecTwo);
		}
		vec4& operator*(vec4 vecOne, const vec4& vecTwo)
		{
			return vecOne.multiply(vecTwo);
		}
		vec4& operator/(vec4 vecOne, const vec4& vecTwo)
		{
			return vecOne.divide(vecTwo);
		}

		std::ostream& operator<<(std::ostream& stream, const vec4& vector)
		{
			return stream << "vec4: (" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << ")" << std::endl;
		}
	}
}