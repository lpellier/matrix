#include "./../general.hpp"

int main() {
	{
		std::cout << "Trace of a Matrix" << std::endl;
		float	_n1[] = {1.0, 0.0};
		float	_n2[] = {0.0, 1.0};
		float *	n3[] = {_n1, _n2};
		float	_n4[] = {2.0, -5.0, 0.0};
		float	_n5[] = {4.0, 3.0, 7.0};
		float	_n6[] = {-2.0, 3.0, 4.0};
		float *	n7[] = {_n4, _n5, _n6};
		float	_n8[] = {-2.0, -8.0, 4.0};
		float	_n9[] = {1.0, -23.0, 4.0};
		float	_n10[] = {0.0, 6.0, 4.0};
		float *	n11[] = {_n8, _n9, _n10};
		
		Matrix<float>	m1 = Matrix<float>(2, 2, n3);
		Matrix<float>	m2 = Matrix<float>(3, 3, n7);
		Matrix<float>	m3 = Matrix<float>(3, 3, n11);

		std::cout << m1.trace() << std::endl;
		std::cout << m2.trace() << std::endl;
		std::cout << m3.trace() << std::endl;
	}
	exit(0);
}
