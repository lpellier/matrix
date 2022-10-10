#include "./../general.hpp"

int main() {
	{
		std::cout << "Matrice reshaped into a Vector" << std::endl;
		float n1[] = {12.2, 16.0, -86.0};
		float n2[] = {2.1, 3.15, 9.9};
		float n3[] = {15.6, 7.2, 4.4};
		float *n4[] = {n1, n2, n3};
		Matrix<float> m1(3, 3, n4);
		std::cout << m1 << std::endl;
		Vector<float> v1 = m1.reshapeIntoVector();
		std::cout << v1 << std::endl;
	}
	exit(0);
}