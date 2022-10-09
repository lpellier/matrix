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
Vector<T>	linear_combination(std::vector<Vector<T>> vecs, std::vector<T> coefs);