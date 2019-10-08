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
	size_t m = 0, n = 0;//m��n��

	m = Matrix.size();//������ȡ
	n = Matrix.begin()->size();//������ȡ

	Matrix_Row MatrixRow_Transp(m, 0);
	Matrix_typedef Matrix_Transp(n, MatrixRow_Transp);

	size_t i = 0;
	size_t j = 0;
	for (auto MatrixRow_temp : Matrix)
	{
		for (auto MatrixElement_temp : MatrixRow_temp)
		{
			(Matrix_Transp[j])[i] = MatrixElement_temp;
			j++;
		}
		i++;
	}

	return Matrix_Transp;
}

bool Project_MatrixMultiplication(Matrix_typedef Matrix_front, Matrix_typedef Matrix_back, Matrix_typedef *MatrixMultiplicated)//�������
{
	size_t m_front = Matrix_front.size(), n_front = Matrix_front.begin()->size(), m_back = Matrix_back.size(), n_back = Matrix_back.begin()->size();
	if (n_front == m_back)
	{
		Matrix_Row MatrixMultiplicatedRow_temp(n_back, 0);
		Matrix_typedef MatrixMultiplicated_temp(m_front, MatrixMultiplicatedRow_temp);
		size_t i0 = 0;//����Matrix_front��ÿһ�е�����Ԫ���ã�

		auto Matrix_front_p = Matrix_front.begin();
		for (size_t i = 0; i < m_front; i++)
		{
			for (size_t j = 0; j < n_back; j++)
			{
				for (auto Matrix_backRow_temp : Matrix_back)
				{
					(MatrixMultiplicated_temp[i])[j] = (MatrixMultiplicated_temp[i])[j] + (*Matrix_front_p)[i0] * Matrix_backRow_temp[j];
					i0++;
				}
				i0 = 0;
			}
			Matrix_front_p = Matrix_front_p + 1;
		}

		*MatrixMultiplicated = MatrixMultiplicated_temp;
		return true;
	}

	std::cout << "����ά�Ȳ�����Ҫ�󣬲���ִ����˲�����" << std::endl;
	return false;
}

Matrix_typedef Project_MatrixMultipliedByNumber(double Number, Matrix_typedef Matrix)//����������
{
	auto MatrixRow_p = Matrix.begin();
	for (size_t i = 0; i < Matrix.size(); i++)
	{
		auto MatrixElement_p = MatrixRow_p->begin();
		for (size_t j = 0; j < MatrixRow_p->size(); j++)
		{
			*MatrixElement_p = (*MatrixElement_p) * Number;
			MatrixElement_p = MatrixElement_p + 1;
		}
		MatrixRow_p = MatrixRow_p + 1;
	}

	return Matrix;
}

bool Project_MatrixPlusMatrix(Matrix_typedef Matrix_front, Matrix_typedef Matrix_back, Matrix_typedef *MatrixAdded)//�������
{
	size_t m_front = Matrix_front.size(), n_front = Matrix_front.begin()->size(), m_back = Matrix_back.size(), n_back = Matrix_back.begin()->size();
	if ((m_front == m_back)&&(n_front == n_back))
	{
		Matrix_Row MatrixAddedRow_temp(n_front, 0);
		Matrix_typedef MatrixAdded_temp(m_front, MatrixAddedRow_temp);

		auto Matrix_front_p = Matrix_front.begin();
		auto Matrix_back_p = Matrix_back.begin();
		for (size_t i = 0; i < m_front; i++)
		{
			auto Matrix_frontElement_p = Matrix_front_p->begin();
			auto Matrix_backElement_p = Matrix_back_p->begin();
			for (size_t j = 0; j < n_front; j++)
			{
				(MatrixAdded_temp[i])[j] = *Matrix_frontElement_p + *Matrix_backElement_p;
				Matrix_frontElement_p = Matrix_frontElement_p + 1;
				Matrix_backElement_p = Matrix_backElement_p + 1;
			}
			Matrix_front_p = Matrix_front_p + 1;
			Matrix_back_p = Matrix_back_p + 1;
		}

		*MatrixAdded = MatrixAdded_temp;
		return true;
	}

	std::cout << "����ά�Ȳ���ͬ������ִ����Ӳ�����" << std::endl;
	return false;
}