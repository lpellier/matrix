

#include "./../general.hpp"

int main() {
	{
		std::cout << "Matrix add / sub / scl" << std::endl;
		float n1[] = {12.2, 16.0, -86.0};
		float n2[] = {2.1, 3.15, 9.9};
		float n3[] = {15.6, 7.2, 4.4};
		float *n4[] = {n1, n2, n3};
		float n5[] = {0.5, 6.1, 0.86};
		float n6[] = {1.2, 15.3, 9.9};
		float n7[] = {6.15, 2.7, 4.4};
		float *n8[] = {n5, n6, n7};
		float n9 = 5.0;
	
		Matrix<float> m1(3, 3, n4);
		Matrix<float> m2(3, 3, n8);
	
		std::cout << m1 << "+" << std::endl << m2 << '=' << std::endl;
		m1.add(m2);
		std::cout << m1;

		std::cout << "------------" << std::endl;
	
		std::cout << m1 << "-" << std::endl << m2 << '=' << std::endl;
		m1.sub(m2);
		std::cout << m1;
		
		std::cout << "------------" << std::endl;
	
		std::cout << m1 << "*" << std::endl << n9 << std::endl << '=' << std::endl;
		m1.scl(n9);
		std::cout << m1 << std::endl;
	}
	exit(0);
}
