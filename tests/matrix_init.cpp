#include "./../general.hpp"

int main() {
	{
		std::cout << "Matrix initialization" << std::endl;
		Matrix<float> m1;
		Matrix<float> m2(5, 5);
		float n1[] = {12.2, 16.0, -86.0};
		float n2[] = {2.1, 3.15, 9.9};
		float *n4[] = {n1, n2};
		Matrix<float> m3(2, 3, n4);
		Matrix<float> m4(m3);
		std::vector<Vector<float>> e1;
		e1.push_back(Vector<float>(3, n1));
		e1.push_back(Vector<float>(3, n2));
		Matrix<float> m5(e1);
		Matrix<float> m6 = m5;

		std::cout << m1 << std::endl;
		std::cout << m2 << std::endl;
		std::cout << m3 << std::endl;
		std::cout << m4 << std::endl;
		std::cout << m5 << std::endl;
		std::cout << m6 << std::endl;
	}
	exit(0);
}
