#include "./../general.hpp"

int main() {
	{
		std::cout << "Vector initialization" << std::endl;
		Vector<float> v1;
		Vector<float> v2(5);
		float numbers[] = {10.0, 15.0, 3.2};
		Vector<float> v3(3, numbers);
		Vector<float> v4(v3);
		std::vector<float> e1;
		e1.push_back(5.0);
		e1.push_back(15.0);
		e1.push_back(-5.0);
		e1.push_back(85.0);
		e1.push_back(56.0);
		Vector<float> v5(e1);
		Vector<float> v6 = v5;

		std::cout << v1 << std::endl;
		std::cout << v2 << std::endl;
		std::cout << v3 << std::endl;
		std::cout << v4 << std::endl;
		std::cout << v5 << std::endl;		
		std::cout << v6 << std::endl;
	}
	exit(0);
}
