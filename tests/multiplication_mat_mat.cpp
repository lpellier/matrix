#include "./../general.hpp"

int main() {
	{
		std::cout << "Multiplication of a Matrix by a Matrix" << std::endl;
		float	_n1[] = {1.0, 0.0};
		float	_n2[] = {0.0, 1.0};
		float *	n3[] = {_n1, _n2};
		float	_n4[] = {2.0, 1.0};
		float	_n5[] = {4.0, 2.0};
		float *	n6[] = {_n4, _n5};
		float	_n7[] = {3.0, -5.0};
		float	_n8[] = {6.0, 8.0};
		float *	n9[] = {_n7, _n8};
		
		Matrix<float>	m1 = Matrix<float>(2, 2, n3);
		Matrix<float>	m2 = Matrix<float>(2, 2, n6);
		Matrix<float>	m3 = Matrix<float>(2, 2, n9);

		std::cout << m1.mul_mat(m1) << std::endl;
		std::cout << m1.mul_mat(m2) << std::endl;
		std::cout << m3.mul_mat(m2) << std::endl;
	}
	exit(0);
}
