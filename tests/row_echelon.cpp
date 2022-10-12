#include "./../general.hpp"

int main() {
	{
		std::cout << "Reduced Row Echelon Form of a Matrix" << std::endl;
		float	_n1[] = {1.0, 0.0, 0.0};
		float	_n2[] = {0.0, 1.0, 0.0};
		float	_n3[] = {0.0, 0.0, 1.0};
		float *	n4[] = {_n1, _n2, _n3};
		float	_n5[] = {1.0, 2.0};
		float	_n6[] = {3.0, 4.0};
		float *	n7[] = {_n5, _n6};
		float	_n8[] = {2.0, 4.0};
		float *	n9[] = {_n5, _n8};
		float	_n10[] = {8.0, 5.0, -2.0, 4.0, 28.0};
		float	_n11[] = {4.0, 2.5, 20.0, 4.0, -4.0};
		float	_n12[] = {8.0, 5.0, 1.0, 4.0, 17.0};
		float *	n13[] = {_n10, _n11, _n12};
		
		Matrix<float>	m1 = Matrix<float>(3, 3, n4);
		Matrix<float>	m2 = Matrix<float>(2, 2, n7);
		Matrix<float>	m3 = Matrix<float>(2, 2, n9);
		Matrix<float>	m4 = Matrix<float>(3, 5, n13);

		std::cout << m1.row_echelon() << std::endl;
		std::cout << m2.row_echelon() << std::endl;
		std::cout << m3.row_echelon() << std::endl;
		std::cout << m4.row_echelon() << std::endl;
	}
	exit(0);
}
