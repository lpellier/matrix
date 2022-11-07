#include "./../general.hpp"

// !

int main() {
	{
		std::cout << "Determinant of a Matrix" << std::endl;
		float	_n1[] = {1.0, -1.0};
		float	_n2[] = {-1.0, 1.0};
		float *	n3[] = {_n1, _n2};
		float	_n4[] = {2.0, 0.0, 0.0};
		float	_n5[] = {0.0, 2.0, 0.0};
		float	_n6[] = {0.0, 0.0, 2.0};
		float *	n7[] = {_n4, _n5, _n6};
		float	_n8[] = {8.0, 5.0, -2.0};
		float	_n9[] = {4.0, 7.0, 20.0};
		float	_n10[] = {7.0, 6.0, 1.0};
		float *	n11[] = {_n8, _n9, _n10};
		float	_n12[] = {8.0, 5.0, -2.0, 4.0};
		float	_n13[] = {4.0, 2.5, 20.0, 4.0};
		float	_n14[] = {8.0, 5.0, 1.0, 4.0};
		float	_n15[] = {28.0, -4.0, 17.0, 1.0};
		float *	n16[] = {_n12, _n13, _n14, _n15};
		
		Matrix<float>	m1 = Matrix<float>(2, 2, n3);
		Matrix<float>	m2 = Matrix<float>(3, 3, n7);
		Matrix<float>	m3 = Matrix<float>(3, 3, n11);
		Matrix<float>	m4 = Matrix<float>(4, 4, n16);

		std::cout << m1.determinant() << std::endl;
		std::cout << m2.determinant() << std::endl;
		std::cout << m3.determinant() << std::endl;
		std::cout << m4.determinant() << std::endl;
	}
	exit(0);
}
