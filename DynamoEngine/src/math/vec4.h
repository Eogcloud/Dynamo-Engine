#pragma once
#include <iostream>

namespace dynamo{
	namespace math{

		struct vec4
		{
			float x;
			float y;
			float z;
			float w;

			vec4();
			vec4(const float& x, const float& y, const float& z, const float& w);

			vec4& add(const vec4& other);
			vec4& subtract(const vec4& other);
			vec4& multiply(const vec4& other);
			vec4& divide(const vec4& other);
			bool compare(const vec4& other);
			bool notEqual(const vec4& other);

			vec4& operator+=(const vec4& other);
			vec4& operator-=(const vec4& other);
			vec4& operator*=(const vec4& other);
			vec4& operator/=(const vec4& other);
			bool operator==(const vec4& other);
			bool operator!=(const vec4& other);

			friend vec4& operator+(vec4 vecOne, const vec4& vecTwo);
			friend vec4& operator-(vec4 vecOne, const vec4& vecTwo);
			friend vec4& operator*(vec4 vecOne, const vec4& vecTwo);
			friend vec4& operator/(vec4 vecOne, const vec4& vecTwo);

			friend std::ostream& operator<<(std::ostream& stream, const vec4& vector);
		};

	}
}