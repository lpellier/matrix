#pragma once

#include "general.hpp"

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
	Vector<T> & operator[](size_t index) {
		return this->contents[index];
	}
	Vector<T> operator[](size_t index) const {
		return this->contents[index];
	}

	Matrix &	operator+=(const Matrix & rhs) {
		this->add(rhs);
		return *this;
	}

	Matrix &	operator-=(const Matrix & rhs) {
		this->sub(rhs);
		return *this;
	}

	Matrix &	operator*=(const double & rhs) {
		this->scl(rhs);
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
				ret[index] = *ite2;
				index++;
			}
		}
		return ret;
	}
		
	Matrix &	add(const Matrix & other) {
		if (other.contents.size() != this->contents.size() || (this->contents.size() > 0 && this->contents[0].contents.size() != other[0].contents.size())) {
			std::cout << "Matrix Addition failed : different sizes" << std::endl;
			return *this;
		}
		for (size_t i = 0; i < this->contents.size(); i++) {
			this->contents[i].add(other[i]);
		}
		return *this;
	}
	Matrix &	sub(const Matrix & other) {
		if (other.contents.size() != this->contents.size() || (this->contents.size() > 0 && this->contents[0].contents.size() != other[0].contents.size())) {
			std::cout << "Matrix Substraction failed : different sizes" << std::endl;
			return *this;
		}
		for (size_t i = 0; i < this->contents.size(); i++) {
			this->contents[i].sub(other[i]);
		}
		return *this;
	}
	Matrix &	scl(const T & scalar) {
		for (size_t i = 0; i < this->contents.size(); i++) {
			this->contents[i].scl(scalar);
		}
		return *this;
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
				os << " " << contents[cols][lines] << " ";  
			}
			os << "]" << std::endl;
		}
	}
	return os;
}
