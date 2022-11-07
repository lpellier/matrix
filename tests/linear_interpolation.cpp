#include "./../general.hpp"

int main() {
	{
		std::cout << "Linear Interpolation" << std::endl;
		float	n1[] = {2.0, 1.0};
		float	n2[] = {4.0, 2.0};
		float	n3[] = {3.0, 4.0};
		float	n4[] = {20.0, 10.0};
		float	n5[] = {30.0, 40.0};
		Vector<float>	v1 = Vector<float>(2, n1);
		Vector<float>	v2 = Vector<float>(2, n2);
		Vector<float>	v3 = Vector<float>(2, n3);
		Vector<float>	v4 = Vector<float>(2, n4);
		Vector<float>	v5 = Vector<float>(2, n5);

		std::cout << lerp<float>(0.0, 1.0, 0.0) << std::endl;
		std::cout << lerp<float>(0.0, 1.0, 1.0) << std::endl;
		std::cout << lerp<float>(0.0, 1.0, 0.5) << std::endl;
		std::cout << lerp<float>(21.0, 42.0, 0.3) << std::endl;
		std::cout << lerp<Vector<float>>(v1, v2, 0.3) << std::endl << std::endl;

		float * n6[] = {n1, n3};
		float * n7[] = {n4, n5};
		Matrix<float> m1(2, 2, n6);
		Matrix<float> m2(2, 2, n7);
		std::cout << lerp<Matrix<float>>(m1, m2, 0.5) << std::endl;
	}
	exit(0);
}
