#include <Project.h>

int main()
{
	/*size_t Determinant_n = 5, Determinant_m = 1;//Çî¾Ù¾ØÕó²âÊÔ
	Matrix_Row FullyArrangedRow_temp(Determinant_n, 0);
	for (size_t i = 0; i < Determinant_n; i++)
	{
		Determinant_m = Determinant_m * (Determinant_n - i);
	}
	Matrix_typedef FullyArranged(Determinant_m, FullyArrangedRow_temp);

	FullyArranged_fun(&FullyArranged, Determinant_n);

	Project_ShowAMatrix(&FullyArranged);*/

	/*Project_GetAMatrix(&Matrix);//¾ØÕóÊäÈë²âÊÔ
	Project_ShowAMatrix(&Matrix);
	Matrix = Project_MatrixMultipliedByNumber(1.5,Matrix);
	Project_ShowAMatrix(&Matrix);
	Matrix = Project_MatrixTransposition(Matrix);
	Project_ShowAMatrix(&Matrix);
	Project_MatrixPlusMatrix(Matrix, Matrix, &Matrix);
	Project_ShowAMatrix(&Matrix);

	Matrix_Row Matrix_frontRow_temp(4, 1), Matrix_backRow_temp(2,1);//¾ØÕóÏà³Ë²âÊÔ
	Matrix_typedef Matrix_front(2, Matrix_frontRow_temp), Matrix_back(4, Matrix_backRow_temp);
	Project_MatrixMultiplication(Matrix_front, Matrix_back, &Matrix);
	Project_ShowAMatrix(&Matrix);*/

	/*Matrix_Row Row{3,4,2,1};//ÇóÄæĞòÊı²âÊÔ
	std::cout << ReverseOrderNumber_fun(Row) << std::endl;*/
	
	/*Matrix_Row Row{ 1,1,1,1 };//ĞĞÁĞÊ½¼ÆËã²âÊÔ
	Matrix.push_back(Row);
	Row = { 0,2,0,0 };
	Matrix.push_back(Row);
	Row = { 0,0,2,0 };
	Matrix.push_back(Row);
	Row = { 0,0,0,2 };
	Matrix.push_back(Row);
	std::cout << Project_Determinant(Matrix) << std::endl;*/

	/*Matrix_Row Row{ 2,1 };//ÇóÄæ¾ØÕó²âÊÔ
	Matrix.push_back(Row);
	Row = { 1,1 };
	Matrix.push_back(Row);
	Project_ShowAMatrix(&Matrix);
	Project_MatrixInversion(Matrix, &Matrix);
	Project_ShowAMatrix(&Matrix);*/

	std::cout << "hello world" << std::endl;

	system("pause");
}