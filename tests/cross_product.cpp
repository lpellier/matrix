#include "./../general.hpp"

int main() {
	{
		std::cout << "Cross Product for two 3D Vectors" << std::endl;
		float n1[] = {0.0, 0.0, 1.0};
		float n2[] = {1.0, 0.0, 0.0};
		float n3[] = {1.0, 2.0, 3.0};
		float n4[] = {4.0, 5.0, 6.0};
		float n5[] = {4.0, 2.0, -3.0};
		float n6[] = {-2.0, -5.0, 16.0};

		Vector<float>	v1(3, n1);
		Vector<float>	v2(3, n2);
		Vector<float>	v3(3, n3);
		Vector<float>	v4(3, n4);
		Vector<float>	v5(3, n5);
		Vector<float>	v6(3, n6);
		
		std::cout << cross_product(v1, v2) << std::endl << std::endl;
		std::cout << cross_product(v3, v4) << std::endl << std::endl;
		std::cout << cross_product(v5, v6) << std::endl << std::endl;
	}
	exit(0);
}

