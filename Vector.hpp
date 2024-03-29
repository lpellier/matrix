#pragma once

#include "general.hpp"

template <typename K>
class Matrix;

template <typename K>
class Vector {
public:
	typedef typename std::vector<K>	array;
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
	Vector(size_t size, K * contents) {
		this->contents = array();
		for (size_t i = 0; i < size; i++) {
			this->contents.push_back(contents[i]);
		}
	}
	Vector(size_t size) {
		this->contents = array(size, K());
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

	K & operator[](size_t index) {
		return this->contents[index];
	}
	K  operator[](size_t index) const {
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

	Vector 	operator*(const float & rhs) const {
		Vector ret(*this);
		ret.scl(rhs);
		return ret;
	}

	bool	contains(K value) {
		for (size_t i = 0; i < this->getSize(); i++) {
			if ((*this)[i] == value)
				return true;
		}
		return false;
	}

	bool	isZeroVector() {
		for (size_t i = 0; i < this->getSize(); i++) {
			if ((*this)[i] != 0)
				return false;
		}
		return true;	
	}

	// accessors
	size_t			getSize(void) const {
		return this->contents.size();
	}

	// methods
	Matrix<K>	reshapeIntoMatrix(size_t col_nbr) const {
		// ? Matrix of col_nbr columns and ceil(length(vec) / col_nbr) rows
		size_t line_nbr = static_cast<size_t>(ceil(static_cast<float>(this->contents.size()) / col_nbr));
		Matrix<K> ret(col_nbr, line_nbr);
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
	Vector &	scl(const K & scalar) {
		for (size_t i = 0; i < this->contents.size(); i++) {
			this->contents[i] *= scalar;
		}
		return *this;
	}

	K		dot(const Vector & v) const {
		K result = 0;
		for (size_t i = 0; i < this->contents.size(); i++) {
			result = static_cast<K>(std::fma(this->contents[i], v.contents[i], result));
		}
		return result;
	}

	// v a vector(a1, a2, a3)
	// taxicab norm or manhattan norm
	// norm_1 = |a1| + |a2| + |a3|
	float	norm_1() const {
		float result = 0;

		for (size_t i = 0; i < this->contents.size(); i++) {
			result += std::abs(this->contents[i]);
		}
		return result;
	}
	// euclidian norm
	// norm = sqrt(a1^2 + a2^2 + a3^2)
	float	norm() const {
		float result = 0;
		for (size_t i = 0; i < this->contents.size(); i++) {
			result += std::pow(this->contents[i], 2);
		}
		result = std::sqrt(result);
		return result;
	}
	// supremum norm
	// norm_inf = max(|a1|, |a2|, |a3|)
	float	norm_inf() const {
		float result = 0;
		for (size_t i = 0; i < this->contents.size(); i++) {
			if (std::abs(this->contents[i]) > result) {
				result = std::abs(this->contents[i]);
			}
		}
		return result;
	}
};


// ? could padd according to longest number in vec
template <typename K>
std::ostream & operator<<(std::ostream & os, const Vector<K> & vec) {
	std::vector<K> contents = vec.contents;
	size_t len = 0;
	for (typename std::vector<K>::const_iterator ite = contents.begin(); ite != contents.end(); ite++) {
		std::string convert = std::to_string(*ite);
		if (convert.length() > len)
			len = convert.length();
	}
	os << "[ ";
	for (typename std::vector<K>::const_iterator ite = contents.begin(); ite != contents.end(); ite++) {
		os << std::setw(len / 2) << *ite << std::setw(len / 2) << " ";
	}
	os << "]";
	return os;
}
