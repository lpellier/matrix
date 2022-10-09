#include "Matrix.hpp"
#include "Vector.hpp"

int main() {
	{	
		Vector<float> test_vec;
		Vector<float> test_vec1(5);
		Vector<float> test_vec2(test_vec1);

		std::cout << test_vec << std::endl << test_vec1 << std::endl;
	}
	{
		Vector<float> test_vec(6);
		test_vec.contents[4] = 10;
		std::cout << test_vec << std::endl;
		Matrix<float> test_mat = test_vec.reshapeIntoMatrix(1);
		std::cout << test_mat << std::endl;
		test_mat = test_vec.reshapeIntoMatrix(2);
		std::cout << test_mat << std::endl;
		test_mat = test_vec.reshapeIntoMatrix(3);
		std::cout << test_mat << std::endl;
		test_mat = test_vec.reshapeIntoMatrix(4);
		std::cout << test_mat << std::endl;
		test_mat = test_vec.reshapeIntoMatrix(6);
		std::cout << test_mat << std::endl;
	}
	{
		Matrix<float> test_mat(2, 3);
		test_mat.contents[1].contents[1] = 10;
		std::cout << test_mat << std::endl;
		Vector<float> test_vec = test_mat.reshapeIntoVector();
		std::cout << test_vec << std::endl;
	}
	{	
		Matrix<float> test_mat;
		Matrix<float> test_mat1(5, 5);
		Matrix<float> test_mat2(test_mat1);

		std::cout << test_mat << std::endl << test_mat1 << std::endl;
	}	
	exit(0);
}