#include <Project.h>

int main()
{
	Project_GetAMatrix(&Matrix);
	Project_ShowAMatrix(&Matrix);
	Matrix = Project_MatrixMultipliedByNumber(1.5,Matrix);
	Project_ShowAMatrix(&Matrix);
	Matrix = Project_MatrixTransposition(Matrix);
	Project_ShowAMatrix(&Matrix);
	Project_MatrixPlusMatrix(Matrix, Matrix, &Matrix);
	Project_ShowAMatrix(&Matrix);

	Matrix_Row Matrix_frontRow_temp(4, 1), Matrix_backRow_temp(2,1);
	Matrix_typedef Matrix_front(2, Matrix_frontRow_temp), Matrix_back(4, Matrix_backRow_temp);
	Project_MatrixMultiplication(Matrix_front, Matrix_back, &Matrix);
	Project_ShowAMatrix(&Matrix);

	std::cout << "hello world" << std::endl;

	system("pause");
}