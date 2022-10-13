#include "./../general.hpp"

int main() {
	{
		std::cout << "Reduced Row Echelon Form of a Matrix" << std::endl;
		float	_n4[] = {1.0, 0.0, 0.0};
		float	_n5[] = {0.0, 1.0, 0.0};
		float	_n6[] = {0.0, 0.0, 1.0};
		float *	n7[] = {_n4, _n5, _n6};
		float	_n8[] = {1.0, 2.0, 0.0, 0.0};
		float	_n9[] = {2.0, 4.0, 0.0, 0.0};
		float	_n10[] = {-1.0, 2.0, 1.0, 1.0};
		float *	n11[] = {_n8, _n9, _n10};
		float	_n12[] = {8.0, 5.0, -2.0};
		float	_n13[] = {4.0, 7.0, 20.0};
		float	_n14[] = {7.0, 6.0, 1.0};
		float	_n15[] = {21.0, 18.0, 7.0};
		float *	n16[] = {_n12, _n13, _n14, _n15};
		
		Matrix<float>	m1 = Matrix<float>(3, 3, n7);
		Matrix<float>	m2 = Matrix<float>(3, 4, n11);
		Matrix<float>	m3 = Matrix<float>(4, 3, n16);

		std::cout << m1.rank() << std::endl;
		std::cout << m2.rank() << std::endl;
		std::cout << m3.rank() << std::endl;
	}
	exit(0);
}
