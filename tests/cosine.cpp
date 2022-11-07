#include "./../general.hpp"

int main() {
	{
		std::cout << "Cosine of two Vectors" << std::endl;
		float n1[] = {1.0, 0.0};
		float n2[] = {0.0, 1.0};
		float n3[] = {-1.0, 1.0};
		float n4[] = {1.0, -1.0};
		float n5[] = {2.0, 1.0};
		float n6[] = {4.0, 2.0};
		float n7[] = {1.0, 2.0, 3.0};
		float n8[] = {4.0, 5.0, 6.0};
	
		Vector<float> v1(2, n1);
		Vector<float> v2(2, n2);
		Vector<float> v3(2, n3);
		Vector<float> v4(2, n4);
		Vector<float> v5(2, n5);
		Vector<float> v6(2, n6);
		Vector<float> v7(3, n7);
		Vector<float> v8(3, n8);
	
		std::cout << angle_cos<float>(v1, v1) << std::endl;
		std::cout << angle_cos<float>(v1, v2) << std::endl;
		std::cout << angle_cos<float>(v3, v4) << std::endl;
		std::cout << angle_cos<float>(v5, v6) << std::endl;
		std::cout << angle_cos<float>(v7, v8) << std::endl;
	}
	exit(0);
}
