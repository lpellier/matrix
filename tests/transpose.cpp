#include "./../general.hpp"

int main() {
	{
		std::cout << "Tranposition of a Matrix" << std::endl;
		float	_n1[] = {1.0, 2.0};
		float	_n2[] = {3.0, 4.0};
		float *	n3[] = {_n1, _n2};
		float	_n4[] = {5.0, 6.0, 7.0};
		float	_n5[] = {8.0, 9.0, 10.0};
		float *	n6[] = {_n4, _n5};
		float	_n7[] = {11.0, 12.0};
		float	_n8[] = {13.0, 14.0};
		float	_n9[] = {15.0, 16.0};
		float *	n9[] = {_n7, _n8, _n9};
		
		Matrix<float>	m1 = Matrix<float>(2, 2, n3);
		Matrix<float>	m2 = Matrix<float>(2, 3, n6);
		Matrix<float>	m3 = Matrix<float>(3, 2, n9);

		std::cout << m1 << "|" << std::endl << m1.transpose() << std::endl;
		std::cout << m2 << "|" << std::endl << m2.transpose() << std::endl;
		std::cout << m3 << "|" << std::endl << m3.transpose() << std::endl;
	}
	exit(0);
}
