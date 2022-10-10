#include "./../general.hpp"

int main() {
	{
		std::cout << "Vector reshaped into Matrices" << std::endl;
		float numbers[] = {0, 1, 2, 3, 4, 5};
		Vector<float> v1(6, numbers);
		std::cout << v1 << std::endl;
		Matrix<float> m1 = v1.reshapeIntoMatrix(1);
		std::cout << m1 << std::endl;
		m1 = v1.reshapeIntoMatrix(2);
		std::cout << m1 << std::endl;
		m1 = v1.reshapeIntoMatrix(3);
		std::cout << m1 << std::endl;
		m1 = v1.reshapeIntoMatrix(4);
		std::cout << m1 << std::endl;
		m1 = v1.reshapeIntoMatrix(6);
		std::cout << m1 << std::endl;
	}
	exit(0);
}
