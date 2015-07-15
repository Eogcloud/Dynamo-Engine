#pragma once
#include <iostream>

namespace dynamo{
	namespace math{

		struct vec3
		{
			float x;
			float y;
			float z;

			vec3();
			vec3(const float& x, const float& y, const float& z);

			vec3& add(const vec3& other);
			vec3& subtract(const vec3& other);
			vec3& multiply(const vec3& other);
			vec3& divide(const vec3& other);
			bool compare(const vec3& other);
			bool notEqual(const vec3& other);

			vec3& operator+=(const vec3& other);
			vec3& operator-=(const vec3& other);
			vec3& operator*=(const vec3& other);
			vec3& operator/=(const vec3& other);
			bool operator==(const vec3& other);
			bool operator!=(const vec3& other);

			friend vec3& operator+(vec3 vecOne, const vec3& vecTwo);
			friend vec3& operator-(vec3 vecOne, const vec3& vecTwo);
			friend vec3& operator*(vec3 vecOne, const vec3& vecTwo);
			friend vec3& operator/(vec3 vecOne, const vec3& vecTwo);

			friend std::ostream& operator<<(std::ostream& stream, const vec3& vector);
		};

	}
}