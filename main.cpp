#include "general.hpp"

int main() {
	// {	
	// 	std::cout << "Vector initialization" << std::endl;
	// 	Vector<float> test_vec;
	// 	Vector<float> test_vec1(5);
	// 	Vector<float> test_vec2(test_vec1);

	// 	std::cout << test_vec << std::endl << test_vec1 << std::endl;
	// }
	// {
	// 	std::cout << "Vector reshaped into Matrices" << std::endl;
	// 	Vector<float> test_vec(6);
	// 	test_vec[4] = 10;
	// 	std::cout << test_vec << std::endl;
	// 	Matrix<float> test_mat = test_vec.reshapeIntoMatrix(1);
	// 	std::cout << test_mat << std::endl;
	// 	test_mat = test_vec.reshapeIntoMatrix(2);
	// 	std::cout << test_mat << std::endl;
	// 	test_mat = test_vec.reshapeIntoMatrix(3);
	// 	std::cout << test_mat << std::endl;
	// 	test_mat = test_vec.reshapeIntoMatrix(4);
	// 	std::cout << test_mat << std::endl;
	// 	test_mat = test_vec.reshapeIntoMatrix(6);
	// 	std::cout << test_mat << std::endl;
	// }
	// {	
	// 	std::cout << "Matrix Initialization" << std::endl;
	// 	Matrix<float> test_mat;
	// 	Matrix<float> test_mat1(5, 5);
	// 	Matrix<float> test_mat2(test_mat1);

	// 	std::cout << test_mat << std::endl << test_mat1 << std::endl;
	// }	
	// {
	// 	std::cout << "Matrix reshaped into Vectors" << std::endl;
	// 	Matrix<float> test_mat(2, 3);
	// 	test_mat[1][1] = 10;
	// 	std::cout << test_mat << std::endl;
	// 	Vector<float> test_vec = test_mat.reshapeIntoVector();
	// 	std::cout << test_vec << std::endl;
	// }

	// {
	// 	std::cout << "Vector add / sub / scl" << std::endl;
	// 	Vector<float> test_vec(3);
	// 	Vector<float> test_vec1(3);
	// 	Vector<float> test_vec2(4);
	// 	test_vec[0] = 1;
	// 	test_vec[1] = -2;
	// 	test_vec[2] = 1.50;
	// 	test_vec1[0] = 4;
	// 	test_vec1[1] = 7;
	// 	test_vec1[2] = -18;
	// 	test_vec2[0] = 2;
	// 	test_vec2[1] = -2.5;
	// 	test_vec2[2] = 2.75;
	// 	test_vec2[3] = 2.75;
	// 	std::cout << test_vec;
	// 	std::cout << "+" << std::endl << test_vec1 << std::endl;
	// 	test_vec.add(test_vec1);
	// 	std::cout << test_vec << std::endl;
	// 	test_vec.add(test_vec2);
	// 	std::cout << test_vec << "-" << std::endl << test_vec1 << std::endl;
	// 	test_vec.sub(test_vec1);
	// 	std::cout << test_vec << std::endl;
	// 	std::cout << test_vec << "*" << std::endl << "5" << std::endl << std::endl;
	// 	test_vec.scl(5);
	// 	std::cout << test_vec;
	// }
	// {
	// 	std::cout << "Matrix add / sub / scl" << std::endl;
	// 	Matrix<float> test_mat(2, 2);
	// 	Matrix<float> test_mat1(2, 2);
	// 	Matrix<float> test_mat2(1, 1);
	// 	test_mat[0][0] = 1;
	// 	test_mat[0][1] = 2;
	// 	test_mat[1][0] = 3;
	// 	test_mat[1][1] = 4;
	// 	test_mat1[0][0] = 5;
	// 	test_mat1[0][1] = 6;
	// 	test_mat1[1][0] = 7;
	// 	test_mat1[1][1] = 8;
	// 	test_mat2[0][0] = 10;
	// 	std::cout << test_mat;
	// 	std::cout << "+" << std::endl << test_mat1 << std::endl;
	// 	test_mat.add(test_mat1);
	// 	std::cout << test_mat << std::endl;
	// 	test_mat.add(test_mat2);
	// 	std::cout << test_mat << "-" << std::endl << test_mat1 << std::endl;
	// 	test_mat.sub(test_mat1);
	// 	std::cout << test_mat << std::endl;
	// 	std::cout << test_mat << "*" << std::endl << "5" << std::endl << std::endl;
	// 	test_mat.scl(5);
	// 	std::cout << test_mat;
	// }
	{
		std::cout << "Linear Combination" << std::endl;
		Vector<double> e1(3, 1.0, 0.0, 0.0);
		Vector<double> e2(3, 0.0, 1.0, 0.0);
		Vector<double> e3(3, 0.0, 0.0, 1.0);

		Vector<double> v1(3, 1.0, 2.0, 3.0);
		Vector<double> v2(3, 0.0, 10.0, -100.0);

		std::vector<Vector<double>> e;
		std::vector<double>			e_coeffs;
		e.push_back(e1);
		e.push_back(e2);
		e.push_back(e3);
		e_coeffs.push_back(10);
		e_coeffs.push_back(-2);
		e_coeffs.push_back(0.5);
		std::vector<Vector<double>> v;
		std::vector<double>			v_coeffs;
		v.push_back(v1);
		v.push_back(v2);
		v_coeffs.push_back(10);
		v_coeffs.push_back(-2);
		std::cout << linear_combination<double>(e, e_coeffs) << std::endl;
		std::cout << linear_combination<double>(v, v_coeffs) << std::endl;
	}
	// {
	// 	std::cout << "Linear Interpolation" << std::endl;
	// 	Vector<double>	v1 = Vector<double>(2, 2.0, 1.0);
	// 	Vector<double>	v2 = Vector<double>(2, 4.0, 2.0);
	// 	Vector<double>	v3 = Vector<double>(2, 3.0, 4.0);
	// 	Vector<double>	v4 = Vector<double>(2, 20.0, 10.0);
	// 	Vector<double>	v5 = Vector<double>(2, 30.0, 40.0);

	// 	std::cout << lerp<double>(0.0, 1.0, 0.0) << std::endl;
	// 	std::cout << lerp<double>(0.0, 1.0, 1.0) << std::endl;
	// 	std::cout << lerp<double>(0.0, 1.0, 0.5) << std::endl;
	// 	std::cout << lerp<double>(21.0, 42.0, 0.3) << std::endl;
	// 	std::cout << lerp<Vector<double>>(v1, v2, 0.3) << std::endl;

	// 	Matrix<double> m1(2, 1);
	// 	m1[0] = v1;
	// 	m1[1] = v3;
	// 	Matrix<double> m2(2, 1);
	// 	m2[0] = v4;
	// 	m2[1] = v5;
	// 	std::cout << lerp<Matrix<double>>(m1, m2, 0.5) << std::endl;
	// }
	exit(0);
}