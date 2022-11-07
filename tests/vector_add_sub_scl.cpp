#include "./../general.hpp"

int main() {
	{
		std::cout << "Vector add / sub / scl" << std::endl;
		float n1[] = {5.0, 16.5, 8.0};
		float n2[] = {-5.0, -16.5, -8.0};
		float n3[] = {1.0, 0.0, 1.0};
		float n4 = 15;
		Vector<float>	v1(3, n1);
		Vector<float>	v2(3, n2);
		Vector<float>	v3(3, n3);
		std::cout << v1 << std::endl << "+" << std::endl << v2 << std::endl << '=' << std::endl;
		v1.add(v2);
		std::cout << v1 << std::endl;

		std::cout << "------------" << std::endl;
	
		std::cout << v1 << std::endl << "-" << std::endl << v3 << std::endl << '=' << std::endl;
		v1.sub(v3);
		std::cout << v1 << std::endl;
		
		std::cout << "------------" << std::endl;
	
		std::cout << v1 << std::endl << "*" << std::endl << n4 << std::endl << '=' << std::endl;
		v1.scl(n4);
		std::cout << v1 << std::endl;
	}
	exit(0);
}
