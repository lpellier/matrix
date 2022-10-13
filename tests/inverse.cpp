#include "./../general.hpp"

int main() {
	{
		std::cout << "Reduced Row Echelon Form of a Matrix" << std::endl;
		float	_n1[] = {1.0, 0.0, 0.0};
		float	_n2[] = {0.0, 1.0, 0.0};
		float	_n3[] = {0.0, 0.0, 1.0};
		float *	n4[] = {_n1, _n2, _n3};
		float	_n5[] = {2.0, 0.0, 0.0};
		float	_n6[] = {0.0, 2.0, 0.0};
		float	_n7[] = {0.0, 0.0, 2.0};
		float *	n8[] = {_n5, _n6, _n7};
		float	_n9[] = {8.0, 5.0, -2.0};
		float	_n10[] = {4.0, 7.0, 20.0};
		float	_n11[] = {7.0, 6.0, 1.0};
		float *	n12[] = {_n9, _n10, _n11};
		
		Matrix<float>	m1 = Matrix<float>(3, 3, n4);
		Matrix<float>	m2 = Matrix<float>(3, 3, n8);
		Matrix<float>	m3 = Matrix<float>(3, 3, n12);

		std::cout << m1.inverse() << std::endl;
		std::cout << m2.inverse() << std::endl;
		std::cout << m3.inverse() << std::endl;
	}
	exit(0);
}
