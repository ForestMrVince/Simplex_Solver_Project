#include <Project.h>

int main()
{
	Project_GetAMatrix(&Matrix);
	Project_ShowAMatrix(&Matrix);
	Matrix = Project_MatrixMultipliedByNumber(2,Matrix);
	Project_ShowAMatrix(&Matrix);

	std::cout << "hello world" << std::endl;

	system("pause");
}