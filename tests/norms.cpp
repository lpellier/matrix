#include "./../general.hpp"

int main() {
	{	std::cout << "Norms of a Vector" << std::endl;
		float n1[] = {0.0, 0.0, 0.0};
		float n2[] = {1.0, 2.0, 3.0};
		float n3[] = {-1.0, -2.0};
	
		Vector<float> v1(3, n1);
		Vector<float> v2(3, n2);
		Vector<float> v3(2, n3);
	
		std::cout << v1.norm_1() << ", " << v1.norm() << ", " << v1.norm_inf() << std::endl;
		std::cout << v2.norm_1() << ", " << v2.norm() << ", " << v2.norm_inf() << std::endl;
		std::cout << v3.norm_1() << ", " << v3.norm() << ", " << v3.norm_inf() << std::endl;
	}
	exit(0);
}
