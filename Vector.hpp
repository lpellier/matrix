#pragma once

#include "general.hpp"

template <typename T>
class Matrix;

template <typename T>
class Vector {
public:
	typedef typename std::vector<T>	array;
	// data
	array	contents;
	// default constructor
	Vector(void) {
		this->contents = array();
	}
	// parameter constructor
	Vector(const array & contents) {
		this->contents = array(contents);
	}
	Vector(size_t size, T * contents) {
		this->contents = array();
		for (size_t i = 0; i < size; i++) {
			this->contents.push_back(contents[i]);
		}
	}
	Vector(size_t size) {
		this->contents = array(size, T());
	}

	// destructor
	~Vector(void) {
		this->contents.clear();
	}
	// copy constructor
	Vector(Vector const & src) {
		this->contents = array(src.contents);
	}
	// assignment operator
	Vector & operator=(Vector const & src) {
		this->contents = array(src.contents);
		return *this;	
	}

	T & operator[](size_t index) {
		return this->contents[index];
	}
	T  operator[](size_t index) const {
		return this->contents[index];
	}

	Vector &	operator+=(const Vector & rhs) {
		this->add(rhs);
		return *this;
	}

	Vector &	operator-=(const Vector & rhs) {
		this->sub(rhs);
		return *this;
	}

	Vector &	operator*=(const float & rhs) {
		this->scl(rhs);
		return *this;
	}

	// accessors
	size_t			getSize(void) const {
		return this->contents.size();
	}

	// methods
	Matrix<T>	reshapeIntoMatrix(size_t col_nbr) const {
		// ? Matrix of col_nbr columns and ceil(length(vec) / col_nbr) rows
		size_t line_nbr = static_cast<size_t>(ceil(static_cast<float>(this->contents.size()) / col_nbr));
		Matrix<T> ret(col_nbr, line_nbr);
		typename array::const_iterator ite = this->contents.begin();

		for (size_t cols = 0; cols < col_nbr; cols++) {
			for (size_t lines = 0; lines < line_nbr; lines++) {
				ret[cols][lines] = *ite;
				ite++;
			}
		}
		return ret;
	}

	Vector &	add(const Vector & other) {
		for (size_t i = 0; i < this->contents.size(); i++) {
			this->contents[i] += other[i];
		}
		return *this;
	}
	Vector &	sub(const Vector & other) {
		for (size_t i = 0; i < this->contents.size(); i++) {
			this->contents[i] -= other[i];
		}
		return *this;
	}
	Vector &	scl(const T & scalar) {
		for (size_t i = 0; i < this->contents.size(); i++) {
			this->contents[i] *= scalar;
		}
		return *this;
	}

	T		dot(const Vector & v) const {
		T result = 0;
		for (size_t i = 0; i < this->contents.size(); i++) {
			result += this->contents[i] * v.contents[i];
		}
		return result;
	}

	// v a vector(a1, a2, a3)
	// taxicab norm or manhattan norm
	// norm_1 = |a1| + |a2| + |a3|
	float	norm_1() const {
		float result = 0;

		for (size_t i = 0; i < this->contents.size(); i++) {
			result += abs(this->contents[i]);
		}
		return result;
	}
	// euclidian norm
	// norm = sqrt(a1^2 + a2^2 + a3^2)
	float	norm() const {
		float result = 0;
		for (size_t i = 0; i < this->contents.size(); i++) {
			result += pow(this->contents[i], 2);
		}
		result = sqrt(result);
		return result;
	}
	// supremum norm
	// norm_inf = max(|a1|, |a2|, |a3|)
	float	norm_inf() const {
		float result = 0;
		for (size_t i = 0; i < this->contents.size(); i++) {
			if (abs(this->contents[i]) > result) {
				result = abs(this->contents[i]);
			}
		}
		return result;
	}
};

template <typename T>
std::ostream & operator<<(std::ostream & os, const Vector<T> & vec) {
	std::vector<T> contents = vec.contents;
	if (contents.size() == 0) {
		std::cout << "[]" << std::endl;
	}
	else {
		for (typename std::vector<T>::const_iterator ite = contents.begin(); ite != contents.end(); ite++) {
			os << "[ " << *ite << " ]" << std::endl;
		}
	}
	return os;
}
