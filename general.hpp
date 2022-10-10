#pragma once

#include <stdarg.h>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <tuple>
#include "Matrix.hpp"
#include "Vector.hpp"

template <typename T>
Vector<T>	linear_combination(std::vector<Vector<T>> vecs, std::vector<T> coefs) {
	if (vecs.size() == 0 || vecs.size() != coefs.size())
		return Vector<T>();
	Vector<T> ret(vecs[0].contents.size());
	for (size_t i = 0; i < coefs.size(); i++) {
		vecs[i].scl(coefs[i]);
		ret.add(vecs[i]);
	}
	return ret;
}

// linear interpolation between two values a and b
// interpolate(a, b, t) -> (b - a) * t + a
template <typename V>
V	lerp(const V & u, const V & v, double t) {
	V res = v;
	res -= u;
	res *= t;
	res += u;
	return res;
}
