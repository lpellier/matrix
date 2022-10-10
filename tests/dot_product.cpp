#include "./../general.hpp"

int main() {
	{
		float n1[] = {0.0, 0.0};
		float n2[] = {1.0, 1.0};
		float n3[] = {-1.0, 6.0};
		float n4[] = {3.0, 2.0};
	
		Vector<float> v1(2, n1);
		Vector<float> v2(2, n2);
		Vector<float> v3(2, n3);
		Vector<float> v4(2, n4);
	
		std::cout << v1.dot(v2) << std::endl;
		std::cout << v2.dot(v2) << std::endl;
		std::cout << v3.dot(v4) << std::endl;
	}
	exit(0);
}
