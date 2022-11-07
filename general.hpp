#pragma once

#include <stdarg.h>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <tuple>
#include <iomanip>
#include "Matrix.hpp"
#include "Vector.hpp"

template <typename K>
Vector<K>	linear_combination(const std::vector<Vector<K>> & vecs, const std::vector<K> & coefs) {
	Vector<K> ret(vecs[0].contents.size());
	for (size_t i = 0; i < coefs.size(); i++) {
		ret.add(vecs[i] * coefs[i]);
	}
	return ret;
}

// linear interpolation between two values a and b
// interpolate(a, b, t) -> (b - a) * t + a
template <typename V>
V	lerp(const V & u, const V & v, float t) {
	V res = v;
	res -= u;
	res *= t;
	res += u;
	return res;
}

template<typename K>
float	angle_cos(const Vector<K> & u, const Vector<K> & v) {
	float result = u.dot(v) / (u.norm() * v.norm());
	return result;
}

// sine = sqrt(1 - angle_cos(u, v)^2)
template<typename K>
float	angle_sine(const Vector<K> & u, const Vector<K> & v) {
	float result = sqrt(1 - pow(angle_cos(u, v), 2));
	return result;
}

template<typename K>
Vector<K>	cross_product(const Vector<K> & u, const Vector<K> & v) {
	K coordinates[] = { 
		u[1]*v[2] - u[2]*v[1],
		u[2]*v[0] - u[0]*v[2],
		u[0]*v[1] - u[1]*v[0]
		};
	Vector<K>	result(3, coordinates);
	
	return result;
}
