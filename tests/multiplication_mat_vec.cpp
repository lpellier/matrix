#include "./../general.hpp"

int main() {
	{
		std::cout << "Multiplication of a Matrix by a Vector" << std::endl;
		float	_n1[] = {1.0, 0.0};
		float	_n2[] = {0.0, 1.0};
		float *	n3[] = {_n1, _n2};
		float	n4[] = {4.0, 2.0};
		float	_n5[] = {2.0, 0.0};
		float	_n6[] = {0.0, 2.0};
		float *	n7[] = {_n5, _n6};
		float	_n8[] = {2.0, -2.0};
		float	_n9[] = {-2.0, 2.0};
		float *	n10[] = {_n8, _n9};
		
		Matrix<float>	m1 = Matrix<float>(2, 2, n3);
		Matrix<float>	m2 = Matrix<float>(2, 2, n7);
		Matrix<float>	m3 = Matrix<float>(2, 2, n10);
		Vector<float>	v1 = Vector<float>(2, n4);

		std::cout << m1.mul_vec(v1) << std::endl;
		std::cout << m2.mul_vec(v1) << std::endl;
		std::cout << m3.mul_vec(v1) << std::endl;
	}
	exit(0);
}
