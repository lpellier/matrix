#pragma once

#include "general.hpp"

template <typename K>
class Vector;

template <typename K>
class Matrix {
public:
	typedef typename std::vector<Vector<K> >	array;
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
		this->contents = array(col_nbr, Vector<K>(row_nbr));
	}
	Matrix(size_t col_nbr, size_t row_nbr, K * contents[]) {
		this->contents = array();
		for (size_t i = 0; i < col_nbr; i++) {
			Vector<K>	cur(row_nbr, contents[i]);
			this->contents.push_back(cur);
		}
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
	Vector<K> & operator[](size_t index) {
		return this->contents[index];
	}
	Vector<K> operator[](size_t index) const {
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

	Matrix &	operator*=(const float & rhs) {
		this->scl(rhs);
		return *this;
	}

	// accessors
	std::tuple<size_t, size_t>		getSize(void) const { // cols, rows
		return std::make_tuple(this->contents.size(), (this->contents.size() == 0 ? 0 : this->contents[0].contents.size()));
	}

	// methods
	Vector<K> reshapeIntoVector() const {
		std::tuple<size_t, size_t> size = this->getSize();
		Vector<K> ret(std::get<0>(size) * std::get<1>(size));
		size_t index = 0;

		for (typename array::const_iterator ite = this->contents.begin(); ite != this->contents.end(); ite++) {
			for (typename std::vector<K>::const_iterator ite2 = (*ite).contents.begin(); ite2 != (*ite).contents.end(); ite2++) {
				ret[index] = *ite2;
				index++;
			}
		}
		return ret;
	}
		
	Matrix &	add(const Matrix & other) {
		for (size_t i = 0; i < this->contents.size(); i++) {
			this->contents[i].add(other[i]);
		}
		return *this;
	}
	Matrix &	sub(const Matrix & other) {
		for (size_t i = 0; i < this->contents.size(); i++) {
			this->contents[i].sub(other[i]);
		}
		return *this;
	}
	Matrix &	scl(const K & scalar) {
		for (size_t i = 0; i < this->contents.size(); i++) {
			this->contents[i].scl(scalar);
		}
		return *this;
	}

	Vector<K>	mul_vec(const Vector<K> & vec) const {
		Vector<K> result(vec.getSize());
		size_t vec_size = vec.getSize();

		for (size_t i = 0; i < vec_size; i++) {
			K coordinate = K();
			for (size_t j = 0; j < (*this)[i].getSize(); j++) {
				coordinate += (*this)[i][j] * vec[j];
			}
			result[i] = coordinate;
		}
		return result;
	}
	
	// Matrix	mul_mat(const Matrix & vec) {
		
	// }
};

template <typename K>
std::ostream & operator<<(std::ostream & os, const Matrix<K> & mat) {
	std::vector<Vector<K>> contents = mat.contents;
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
