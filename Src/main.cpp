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

	std::cout << "hello world" << std::endl;

	system("pause");
}