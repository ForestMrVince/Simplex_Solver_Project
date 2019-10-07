#include <Matrix.h>

bool Project_GetAMatrix(Matrix_typedef *Matrix)
{
	double temp_Element = 0;
	Matrix_Row temp_Row;
	size_t Row_size_Now = 0, Row_size_Before = 0;
	char temp_CharLoop_char = 0;
	bool NewRow_flag = true, NewRow_CharLoop_flag = true, NewRowLoop_flag = true;

	std::cout << "��������ľ���" << std::endl;

	while (NewRow_flag)
	{
		std::cout << "�������µ�һ�У�Ԫ�ؼ��Կո������ÿһ���Է������ַ���������" << std::endl;
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
					std::cout << "�����˿��У��������룺" << std::endl;
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
					std::cout << "�����˿��У��������룺" << std::endl;
				}
				if (Row_size_Now < Row_size_Before)
				{
					std::cout << "��ǰ��Ԫ�ز��㣡�������룺" << std::endl;
				}
				if (Row_size_Now > Row_size_Before)
				{
					std::cout << "��ǰ��Ԫ�ع��࣡ɾ����������о���Ԫ�أ��˳��������" << std::endl;
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
			std::cout << "�Ƿ������µ�һ�У�Y/N����" << std::endl;
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
					std::cout << "�����˴���Ĳ�����" << std::endl;
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
		std::cout << "����Ϊ��" << std::endl;
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

//���桢��ת�á�������ˡ����������ˡ��������

Matrix_typedef Project_MatrixInversion(Matrix_typedef Matrix)//���棬��Ҫ��return��Ϊbool���β����һ����������ĵ�ַ���ڴ洢�����
{
	return Matrix;
}

Matrix_typedef Project_MatrixTransposition(Matrix_typedef Matrix)//��ת��
{
	return Matrix;
}

Matrix_typedef Project_MatrixMultiplication(Matrix_typedef Matrix_front, Matrix_typedef Matrix_back)//�������
{
	Matrix_typedef Matrix;

	return Matrix;
}

Matrix_typedef Project_MatrixMultipliedByNumber(double Number, Matrix_typedef Matrix)//����������
{
	auto MatrixRow_temp = Matrix.begin();//δ���
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

Matrix_typedef Project_MatrixPlusMatrix(Matrix_typedef Matrix_front, Matrix_typedef Matrix_back)//�������
{
	Matrix_typedef Matrix;

	return Matrix;
}