#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <tuple>
#include <vector>

#include "Vector.hpp"

template <typename T>
class Vector;

template <typename T>
class Matrix {
public:
	typedef typename std::vector<Vector<T>>	array;
	// data
	array	contents;
	// default constructor
	Matrix(void) {
		this->contents = array();
	}
	// parameter constructor
	Matrix(const array & contents) {
		this->contents = array(contents);
	}
	Matrix(size_t col_nbr, size_t row_nbr) {
		this->contents = array(col_nbr, Vector<T>(row_nbr));
	}

	// destructor
	~Matrix(void) {
		this->contents.clear();
	}
	// copy constructor
	Matrix(Matrix const & src) {
		this->contents = array(src.contents);
	}
	// assignment operator
	Matrix & operator=(Matrix const & src) {
		this->contents = array(src.contents);
		return *this;	
	}

	// accessors
	std::tuple<size_t, size_t>		getSize(void) const { // cols, rows
		return std::make_tuple(this->contents.size(), (this->contents.size() == 0 ? 0 : this->contents[0].contents.size()));
	}

	// methods
	Vector<T> reshapeIntoVector() const {
		std::tuple<size_t, size_t> size = this->getSize();
		Vector<T> ret(std::get<0>(size) * std::get<1>(size));
		size_t index = 0;

		for (typename array::const_iterator ite = this->contents.begin(); ite != this->contents.end(); ite++) {
			for (typename std::vector<T>::const_iterator ite2 = (*ite).contents.begin(); ite2 != (*ite).contents.end(); ite2++) {
				ret.contents[index] = *ite2;
				index++;
			}
		}
		return ret;
	}
		
	void	add(const Matrix & other) {
		if (other.contents.size() != this->contents.size() || (this->contents.size() > 0 && this->contents[0].contents.size() != other.contents[0].contents.size())) {
			std::cout << "Matrix Addition failed : different sizes" << std::endl;
			return ;
		}
		for (size_t i = 0; i < this->contents.size(); i++) {
			this->contents[i].add(other.contents[i]);
		}
	}
	void	sub(const Matrix & other) {
		if (other.contents.size() != this->contents.size() || (this->contents.size() > 0 && this->contents[0].contents.size() != other.contents[0].contents.size())) {
			std::cout << "Matrix Substraction failed : different sizes" << std::endl;
			return ;
		}
		for (size_t i = 0; i < this->contents.size(); i++) {
			this->contents[i].sub(other.contents[i]);
		}
	}
	void	scl(const T & scalar) {
		for (size_t i = 0; i < this->contents.size(); i++) {
			this->contents[i].scl(scalar);
		}
	}
};

template <typename T>
std::ostream & operator<<(std::ostream & os, const Matrix<T> & mat) {
	std::vector<Vector<T>> contents = mat.contents;
	if (contents.size() == 0)
		os << "[]" << std::endl;
	else {
		for (size_t lines = 0; lines < contents[0].contents.size(); lines++) {
			os << "[";
			for (size_t cols = 0; cols < contents.size(); cols++) {
				os << " " << contents[cols].contents[lines] << " ";  
			}
			os << "]" << std::endl;
		}
	}
	return os;
}
