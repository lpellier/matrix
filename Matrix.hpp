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
	Matrix(const size_t & rows, const size_t & cols) {
		this->contents = array(rows, Vector<K>(cols));
	}
	Matrix(const size_t & rows, const size_t & cols, K * contents[]) {
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

	bool	isSquare() const {
		return std::get<0>(this->getSize()) == std::get<1>(this->getSize());
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
				coordinate = static_cast<K>(std::fma((*this)[i][j], vec[j], coordinate));
			}
			result[i] = coordinate;
		}
		return result;
	}
	
	Vector<K>	get_vertical_vector_at_index(const size_t & index) const {
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
					M[i] -= M[r] * M[i][lead];
				}
			}
		}
		return M;
	}

	K	determinant2d(const Matrix & mat) const {
		K result = mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
		return result;
	}
	
	K	determinant3d(const Matrix & mat) const {
		K result;
		Matrix	left(2, 2);
		Matrix	center(2, 2);
		Matrix	right(2, 2);
		left[0][0] = mat[1][0];
		left[0][1] = mat[1][1];
		left[1][0] = mat[2][0];
		left[1][1] = mat[2][1];

		center[0][0] = mat[1][0];
		center[0][1] = mat[1][2];
		center[1][0] = mat[2][0];
		center[1][1] = mat[2][2];
		
		right[0][0] = mat[1][1];
		right[0][1] = mat[1][2];
		right[1][0] = mat[2][1];
		right[1][1] = mat[2][2];
	
		result = mat[0][0] * determinant2d(right) - mat[0][1] * determinant2d(center) + mat[0][2] * determinant2d(left);
		return result;
	}

	K determinant4d(const Matrix & mat) const {
		K result;

		K left_n1[] = {mat[1][0], mat[1][1], mat[1][2]};
		K left_n2[] = {mat[2][0], mat[2][1], mat[2][2]};
		K left_n3[] = {mat[3][0], mat[3][1], mat[3][2]};
		K * left_n[] = {left_n1, left_n2, left_n3};

		K center_left_n1[] = {mat[1][0], mat[1][1], mat[1][3]};
		K center_left_n2[] = {mat[2][0], mat[2][1], mat[2][3]};
		K center_left_n3[] = {mat[3][0], mat[3][1], mat[3][3]};
		K * center_left_n[] = {center_left_n1, center_left_n2, center_left_n3};

		K center_right_n1[] = {mat[1][0], mat[1][2], mat[1][3]};
		K center_right_n2[] = {mat[2][0], mat[2][2], mat[2][3]};
		K center_right_n3[] = {mat[3][0], mat[3][2], mat[3][3]};
		K * center_right_n[] = {center_right_n1, center_right_n2, center_right_n3};

		K right_n1[] = {mat[1][1], mat[1][2], mat[1][3]};
		K right_n2[] = {mat[2][1], mat[2][2], mat[2][3]};
		K right_n3[] = {mat[3][1], mat[3][2], mat[3][3]};
		K * right_n[] = {right_n1, right_n2, right_n3};

		Matrix	left(3, 3, left_n);
		Matrix	center_left(3, 3, center_left_n);
		Matrix	center_right(3, 3, center_right_n);
		Matrix	right(3, 3, right_n);

		result = mat[0][0] * determinant3d(right) - mat[0][1] * determinant3d(center_right) + mat[0][2] * determinant3d(center_left) - mat[0][3] * determinant3d(left);
		return result;
	}

	K	determinant() const {
		if (!this->isSquare())
			return K();
		else if (this->contents.size() == 2)
			return determinant2d(*this);
		else if (this->contents.size() == 3)
			return determinant3d(*this);
		else if (this->contents.size() == 4)
			return determinant4d(*this);
		else
			return K();
	}

	K	cofactor(const size_t & i, const size_t & j) const {
		Matrix deleted(std::get<0>(this->getSize()) - 1, std::get<1>(this->getSize()) - 1);
		size_t row_index = 0;
		size_t col_index = 0;

		for (size_t row = 0; row < this->contents.size(); row++) {
			if (row != i) {
				for (size_t col = 0; col < (*this)[row].contents.size(); col++) {
					if (col != j) {
						deleted[row_index][col_index] = (*this)[row][col];
						col_index++;
						if (col_index > std::get<1>(this->getSize()) - 2)
							col_index = 0;
					}
				}
				row_index++;
			}
		}

		K result = std::pow(-1, i + 1 + j + 1) * deleted.determinant();
		return result;
	}

	Matrix inverse() const {
		Matrix result(std::get<0>(this->getSize()), std::get<1>(this->getSize()));

		for (size_t i = 0; i < std::get<0>(this->getSize()); i++) {
			for (size_t j = 0; j < std::get<1>(this->getSize()); j++) {
				result[i][j] = this->cofactor(i, j);
			}
		}
		result = result.transpose();
		result.scl(1 / this->determinant());
		return result;
	}

	size_t rank() const {
		Matrix reduced = this->row_echelon();
		size_t rank = 0;
		for (size_t i = 0; i < reduced.contents.size(); i++) {
			if (!reduced[i].isZeroVector())
				rank++;
		}
		return rank;
	}
};

template <typename K>
std::ostream & operator<<(std::ostream & os, const Matrix<K> & mat) {
	std::vector<Vector<K>> contents = mat.contents;
	size_t len = 0;
	for (size_t i = 0; i < contents.size(); i++) {
		for (size_t j = 0; j < contents[i].getSize(); j++) {
			std::string convert = std::to_string(contents[i][j]);
			if (convert.length() > len)
				len = convert.length();
		}
	}
	if (contents.size() == 0)
		os << "[ ]" << std::endl;
	else {
		for (size_t i = 0; i < contents.size(); i++) {
			os << "[ ";
			for (size_t j = 0; j < contents[i].getSize(); j++) {
				os << std::setw(len / 2) << contents[i][j] << std::setw(len / 2) << " ";
			}
			os << "]" << std::endl;
		}
	}
	return os;
}
