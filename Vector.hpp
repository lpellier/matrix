#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

#include "Matrix.hpp"

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
	Vector(size_t size) {
		this->contents = array(size, 0);
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

	// accessors
	size_t			getSize(void) const {
		return this->contents.size();
	}

	// methods
	Matrix<T>	reshapeIntoMatrix(size_t col_nbr) const {
		// ? Matrix of col_nbr columns and ceil(length(vec) / col_nbr) rows
		size_t line_nbr = static_cast<size_t>(ceil(static_cast<double>(this->contents.size()) / col_nbr));
		Matrix<T> ret(col_nbr, line_nbr);
		typename array::const_iterator ite = this->contents.begin();

		for (size_t cols = 0; cols < col_nbr; cols++) {
			for (size_t lines = 0; lines < line_nbr; lines++) {
				ret.contents[cols].contents[lines] = *ite;
				ite++;
			}
		}
		return ret;
	}

	void	add(const Vector & other) {
		if (other.contents.size() != this->contents.size()) {
			std::cout << "Vector Addition failed : different sizes" << std::endl;
			return ;
		}
		for (size_t i = 0; i < this->contents.size(); i++) {
			this->contents[i] += other.contents[i];
		}
	}
	void	sub(const Vector & other) {
		if (other.contents.size() != this->contents.size()) {
			std::cout << "Vector Substraction failed : different sizes" << std::endl;
			return ;
		}
		for (size_t i = 0; i < this->contents.size(); i++) {
			this->contents[i] -= other.contents[i];
		}
	}
	void	scl(const T & scalar) {
		for (size_t i = 0; i < this->contents.size(); i++) {
			this->contents[i] *= scalar;
		}
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
