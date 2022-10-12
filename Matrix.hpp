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
	Matrix(size_t rows, size_t cols) {
		this->contents = array(rows, Vector<K>(cols));
	}
	Matrix(size_t rows, size_t cols, K * contents[]) {
		this->contents = array();
		for (size_t i = 0; i < rows; i++) {
			Vector<K>	cur(cols, contents[i]);
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
	
	Vector<K>	get_vertical_vector_at_index(size_t index) const {
		Vector<K> ret(this->contents.size());

		for (size_t i = 0; i < this->contents.size(); i++) {
			ret[i] = (*this)[i][index];
		}
		return ret;
	}

	Matrix	mul_mat(const Matrix & mat) const {
		size_t rows = std::get<0>(this->getSize());
		size_t cols = std::get<1>(mat.getSize());
		
		Matrix	result(rows, cols);

		for (size_t i = 0; i < rows; i++) {
			for (size_t j = 0; j < cols; j++) {
				result[i][j] = (*this)[i].dot(mat.get_vertical_vector_at_index(j)); 
			}
		}
		return result;
	}

	K	trace() const {
		size_t row = 0;
		size_t col = 0;
		K result = K();
		
		while (row < std::get<1>(this->getSize()) && col < std::get<0>(this->getSize())) {
			result += (*this)[row][col];
			row++;
			col++;
		}
		return result;
	}

	Matrix	transpose() const {
		Matrix	result(std::get<1>(this->getSize()), std::get<0>(this->getSize()));

		for (size_t i = 0; i < std::get<1>(this->getSize()); i++) {
			result[i] = this->get_vertical_vector_at_index(i);
		}
		return result;
	}

	Matrix row_echelon() const {
		size_t lead = 0;
		size_t row_count = std::get<0>(this->getSize());
		size_t col_count = std::get<1>(this->getSize());

		Matrix M(*this);

		for (size_t r = 0; r < row_count && lead < col_count; r++) {
			size_t i = r;

			while (M[i][lead] == 0) {
				i++;
				if (i >= row_count) {
					i = r;
					lead++;
					if (lead >= col_count)
						return M;
				}
			}
			Vector<K> tmp = M[i];
			M[i] = M[r];
			M[r] = tmp;

			M[r].scl(1 / M[r][lead]);
			for (i = 0; i < row_count; i++) {
				if (i != r) {
					for (size_t j = 0; j < col_count; j++) {
						M[i][j] += -M[i][lead] * M[r][j];
					}
				}
			}

		}
		

		return M;
	}

};

template <typename K>
std::ostream & operator<<(std::ostream & os, const Matrix<K> & mat) {
	std::vector<Vector<K>> contents = mat.contents;
	if (contents.size() == 0)
		os << "[]" << std::endl;
	else {
		for (size_t i = 0; i < contents.size(); i++) {
			os << contents[i];
		}
	}
	return os;
}
