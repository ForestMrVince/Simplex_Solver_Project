#include <Matrix.h>

bool Project_GetAMatrix(Matrix_typedef *Matrix)
{
	double temp_Element = 0;
	Matrix_Row temp_Row;
	size_t Row_size_Now = 0, Row_size_Before = 0;
	char temp_CharLoop_char = 0;
	bool NewRow_flag = true, NewRow_CharLoop_flag = true, NewRowLoop_flag = true;

	std::cout << "请输入你的矩阵：" << std::endl;

	while (NewRow_flag)
	{
		std::cout << "请输入新的一行（元素间以空格隔开，每一行以非数字字符结束）：" << std::endl;
		while (NewRowLoop_flag)
		{
			while (std::cin >> temp_Element)
			{
				temp_Row.push_back(temp_Element);
			}
			if (Row_size_Before == 0)
			{
				Row_size_Before = temp_Row.size();
				if (Row_size_Before == 0)
				{
					std::cout << "输入了空行！继续输入：" << std::endl;
				}
				else
				{
					NewRowLoop_flag = false;
				}
			}
			else
			{
				Row_size_Now = temp_Row.size();
				if (Row_size_Now == 0)
				{
					std::cout << "输入了空行！继续输入：" << std::endl;
				}
				if (Row_size_Now < Row_size_Before)
				{
					std::cout << "当前行元素不足！继续输入：" << std::endl;
				}
				if (Row_size_Now > Row_size_Before)
				{
					std::cout << "当前行元素过多！删除输入的所有矩阵元素！退出输入程序！" << std::endl;
					Matrix->clear();
					return false;
				}
				if (Row_size_Now == Row_size_Before)
				{
					NewRowLoop_flag = false;
				}
			}
			std::cin.clear();
			std::cin.ignore();
		}
		Matrix->push_back(temp_Row);
		temp_Row.clear();
		NewRowLoop_flag = true;

		while(NewRow_CharLoop_flag)
		{
			std::cout << "是否输入新的一行（Y/N）：" << std::endl;
			std::cin >> temp_CharLoop_char;
			switch (temp_CharLoop_char)
			{
				case 'Y':
					NewRow_flag = 1;
					NewRow_CharLoop_flag = false;
					break;

				case 'N':
					NewRow_flag = 0;
					NewRow_CharLoop_flag = false;
					break;

				default:
					std::cout << "输入了错误的操作符" << std::endl;
					break;
			}
			temp_CharLoop_char = 0;
			std::cin.clear();
			std::cin.ignore();
		}
		NewRow_CharLoop_flag = true;
	}

	return true;
}

bool Project_ShowAMatrix(Matrix_typedef *Matrix)
{
	if (Matrix->size() == 0)
	{
		std::cout << "矩阵为空" << std::endl;
		return false;
	}
	else
	{
		for (auto MatrixRow_temp : *Matrix)
		{
			for (auto MatrixElement_temp : MatrixRow_temp)
			{
				std::cout << MatrixElement_temp << ' ';
			}
			std::cout << std::endl;
		}
	}
	return true;
}

//求逆、求转置、矩阵相乘、数与矩阵相乘、矩阵相加

Matrix_typedef Project_MatrixInversion(Matrix_typedef Matrix)//求逆，需要把return改为bool，形参添加一个矩阵变量的地址用于存储逆矩阵
{
	return Matrix;
}

Matrix_typedef Project_MatrixTransposition(Matrix_typedef Matrix)//求转置
{
	return Matrix;
}

Matrix_typedef Project_MatrixMultiplication(Matrix_typedef Matrix_front, Matrix_typedef Matrix_back)//矩阵相乘
{
	Matrix_typedef Matrix;

	return Matrix;
}

Matrix_typedef Project_MatrixMultipliedByNumber(double Number, Matrix_typedef Matrix)//数与矩阵相乘
{
	auto MatrixRow_temp = Matrix.begin();//未完成
	for (auto MatrixRow_temp : Matrix)
	{
		for (auto MatrixElement_temp : MatrixRow_temp)
		{
			std::cout << MatrixElement_temp << ' ';
		}
		std::cout << std::endl;
	}

	return Matrix;
}

Matrix_typedef Project_MatrixPlusMatrix(Matrix_typedef Matrix_front, Matrix_typedef Matrix_back)//矩阵相加
{
	Matrix_typedef Matrix;

	return Matrix;
}