#include "vec3.h"

namespace dynamo{
	namespace math{
		
		vec3::vec3()
		{
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
		}

		vec3::vec3(const float& x, const float& y, const float& z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}

		vec3& vec3::add(const vec3& other)
		{
			x += other.x;
			y += other.y;
			z += other.z;
			return *this;
		}
			
		vec3& vec3::subtract(const vec3& other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
			return *this;
		}
				
		vec3& vec3::multiply(const vec3& other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;
			return *this;
		}
				
		vec3& vec3::divide(const vec3& other)
		{
			x /= other.x;
			y /= other.y;
			z /= other.z;
			return *this;
		}

		bool vec3::compare(const vec3& other)
		{
			if (x == other.x && y == other.y && z == other.z)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		bool vec3::notEqual(const vec3& other)
		{
			if (x == other.x && y == other.y && z == other.z)
			{
				return false;
			}
			else
			{
				return true;
			}
		}

		vec3& vec3::operator+=(const vec3& other)
		{
			return add(other);
		}
		
		vec3& vec3::operator-=(const vec3& other)
		{
			return subtract(other);
		}
		
		vec3& vec3::operator*=(const vec3& other)
		{
			return multiply(other);
		}
		
		vec3& vec3::operator/=(const vec3& other)
		{
			return divide(other);
		}

		bool vec3::operator==(const vec3& other)
		{
			return compare(other);
		}

		bool vec3::operator!=(const vec3& other)
		{
			return notEqual(other);
		}

		vec3& operator+(vec3 vecOne, const vec3& vecTwo)
		{
			return vecOne.add(vecTwo);
		}
		vec3& operator-(vec3 vecOne, const vec3& vecTwo)
		{
			return vecOne.subtract(vecTwo);
		}
		vec3& operator*(vec3 vecOne, const vec3& vecTwo)
		{
			return vecOne.multiply(vecTwo);
		}
		vec3& operator/(vec3 vecOne, const vec3& vecTwo)
		{
			return vecOne.divide(vecTwo);
		}

		std::ostream& operator<<(std::ostream& stream, const vec3& vector)
		{
			return stream << "vec3: (" << vector.x << ", " << vector.y << ", " << vector.z << ")" << std::endl;
		}
	}
}