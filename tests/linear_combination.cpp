#include "./../general.hpp"

int main() {
	{
		std::cout << "Linear Combination" << std::endl;
		float n1[] = {1.0, 0.0, 0.0};
		float n2[] = {0.0, 1.0, 0.0};
		float n3[] = {0.0, 0.0, 1.0};
		float n4[] = {1.0, 2.0, 3.0};
		float n5[] = {0.0, 10.0, -100.0};
		Vector<float> e1(3, n1);
		Vector<float> e2(3, n2);
		Vector<float> e3(3, n3);

		Vector<float> v1(3, n4);
		Vector<float> v2(3, n5);

		std::vector<Vector<float>> e;
		std::vector<float>			e_coeffs;
		e.push_back(e1);
		e.push_back(e2);
		e.push_back(e3);
		e_coeffs.push_back(10);
		e_coeffs.push_back(-2);
		e_coeffs.push_back(0.5);
		std::vector<Vector<float>> v;
		std::vector<float>			v_coeffs;
		v.push_back(v1);
		v.push_back(v2);
		v_coeffs.push_back(10);
		v_coeffs.push_back(-2);
		std::cout << linear_combination<float>(e, e_coeffs) << std::endl;
		std::cout << linear_combination<float>(v, v_coeffs) << std::endl;
	}
	exit(0);
}
