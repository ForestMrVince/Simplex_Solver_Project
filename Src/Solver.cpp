#include "Solver.h"

/*��������⺯������*/
bool Project_solver_main()//������
{
	if (!Question_Input())
	{
		std::cout << "�����������Ч������" << std::endl;
		return false;
	}

	if (!TwoPhaseMethod_main())//�������׶η����
	{
		std::cout << "���׶η����ʧ�ܣ�����" << std::endl;
		return false;
	}
	else
	{
		std::cout << "���׶η����ɹ�������" << std::endl;
		return true;
	}
}


/*����¼�뺯��*/
static bool Question_Input()
{
	std::cout << "���������A��" << std::endl;
	if (!GetMatrix_A())
	{
		std::cout << "����ľ���A��Ч" << std::endl;
		return false;
	}

	std::cout << "���������b��" << std::endl;
	if (!GetMatrix_b())
	{
		std::cout << "����ľ���b��Ч" << std::endl;
		return false;
	}

	std::cout << "���������c��" << std::endl;
	if (!GetMatrix_c())
	{
		std::cout << "����ľ���c��Ч" << std::endl;
		return false;
	}

	x_init();//��ʼ���Ա���������x

	return true;
}

static bool GetMatrix_A()
{
	Matrix_typedef Matrix;
	if (!Project_GetAMatrix(&Matrix))
	{
		return false;
	}
	A = Matrix;
	m = A.size();			//��ʼ������m
	n = A.begin()->size();	//��ʼ������n
	return true;
}

static bool GetMatrix_b()
{
	Matrix_typedef Matrix;
	std::cout << "Ϊ�����뷽�㣬������b��ת��" << std::endl;
	if (!Project_GetAMatrix(&Matrix))
	{
		return false;
	}
	Matrix = Project_MatrixTransposition(Matrix);//�������b��ת�ã�ת��һ�£����������b

	if (Matrix.size() != m)//�ж������b�������Ƿ��A���������
	{
		return false;
	}
	else
	{
		if (Matrix.begin()->size() != 1)//�ж������b�Ƿ�Ϊ������
		{
			return false;
		}
		else
		{
			b = Matrix;//¼��b
			return true;
		}
	}
}

static bool GetMatrix_c()
{
	Matrix_typedef Matrix;
	std::cout << "Ϊ�����뷽�㣬������c��ת��" << std::endl;
	if (!Project_GetAMatrix(&Matrix))
	{
		return false;
	}
	Matrix = Project_MatrixTransposition(Matrix);//�������c��ת�ã�ת��һ�£����������c

	if (Matrix.size() != n)//�ж������c�������Ƿ��A���������
	{
		return false;
	}
	else
	{
		if (Matrix.begin()->size() != 1)//�ж������c�Ƿ�Ϊ������
		{
			return false;
		}
		else
		{
			c = Matrix;//¼��c
			return true;
		}
	}
}

static void x_init()
{
	Matrix_Row x_T_RowTemp(n, 0);
	x.push_back(x_T_RowTemp);//��ʱxΪ����������x��ת��
	x = Project_MatrixTransposition(x);//��xת�û���
}
/*����¼�뺯��*/

/*���׶η���⺯��*/
static bool TwoPhaseMethod_main()//���׶η�������
{
	b_2 = b;//b_2�ĳ�ʼ��
	x_2_init();
	c_2_init();
	A_2_init();

	if (!Simplex_Solver_main(A_2, c_2, b_2, x_2))//��ʼ����һ�׶�
	{
		std::cout << "��һ�׶����ʧ�ܣ�����" << std::endl;
		return false;
	}

	Matrix_typedef c_s_x_s_Mult_Result;
	if (!Project_MatrixMultiplication(Project_MatrixTransposition(c_s), x_s, &c_s_x_s_Mult_Result))//����
	{
		std::cout << "��һ�׶μ������ʧ�ܣ�����" << std::endl;
		return false;
	}
	if ((c_s_x_s_Mult_Result[0])[0] != 0)
	{
		std::cout << "��һ�׶μ���֤����ԭ���ⲻ���У�����" << std::endl;
		return false;
	}
	std::cout << "��һ�׶����ɹ�������" << std::endl;

	for (size_t i_x = 0; i_x < x.size(); i_x++)//�����˹�����
	{
		(x[i_x])[0] = (x_s[i_x])[0];
	}

	void EraseAllVariables();//��ձ�������
	if (!Simplex_Solver_main(A, c, b, x))//��ʼ���ڶ��׶�
	{
		std::cout << "�ڶ��׶����ʧ�ܣ�����" << std::endl;
		return false;
	}

	return true;
}

//���׶η���ʼ��
static void x_2_init()
{
	xa = b_2;
	x_2 = x;

	auto xa_T = Project_MatrixTransposition(xa);
	auto x_2_T = Project_MatrixTransposition(x_2);

	if (!Project_MatrixMerging(x_2_T, xa_T, &x_2_T))//�ϲ���������
	{
		std::cout << "����ϲ�ʧ�ܣ�����" << std::endl;
		return;
	}

	x_2 = Project_MatrixTransposition(x_2_T);
}

static void c_2_init()
{
	Matrix_Row ca_RowTemp(xa.size(), 1);
	Matrix_typedef ca;
	ca.push_back(ca_RowTemp);

	Matrix_Row c_2_RowTemp(x.size(), 0);
	c_2.push_back(c_2_RowTemp);

	if (!Project_MatrixMerging(c_2, ca, &c_2))//�ϲ���������
	{
		std::cout << "c_2 ����ϲ�ʧ�ܣ�����" << std::endl;
		return;
	}
	c_2 = Project_MatrixTransposition(c_2);
}

static void A_2_init()
{
	Matrix_Row Aa_RowTemp(xa.size(), 0);

	for (size_t i=0; i < xa.size(); i++)
	{
		Aa_RowTemp[i] = 1;
		Aa.push_back(Aa_RowTemp);
		Aa_RowTemp[i] = 0;
	}

	if (Aa.size() != xa.size())//test
	{
		std::cout << "Aa��������" << std::endl;//test
	}
	else//test
	{
		if (Aa.begin()->size() != xa.size())//test
		{
			std::cout << "Aa��������" << std::endl;//test
		}
	}
	
	A_2 = A;//���Ȱ�A�ĳ�Ա�������������ΪA_2�ǰ�Aaƴ����A����

	if (!Project_MatrixMerging(A_2, Aa, &A_2))//�ϲ���������
	{
		return;
	}
}
/*���׶η���⺯��*/

/*�������������(��Bland����)*/
//bool Simplex_Solver_main(Matrix_typedef A_s_temp, Matrix_typedef c_s_temp, Matrix_typedef b_s_temp, Matrix_typedef x_s_temp)//�������������������
static bool Simplex_Solver_main(Matrix_typedef A_s_temp, Matrix_typedef c_s_temp, Matrix_typedef b_s_temp, Matrix_typedef x_s_temp)//�������������������
{
	if (!Simplex_Solver_init(A_s_temp, c_s_temp, b_s_temp, x_s_temp))//��ʼ�������α���
	{
		std::cout << "��ʼ�����󣡣���" << std::endl;
		return false;
	}

	while (!Simplex_Solver_OptimalityTest())			//���������Լ���
	{
		if (!Simplex_Solver_SeekOptimizationDirection())		//���Ľ�����
		{
			return false;
		}

		if (!Simplex_Solver_FindLambda())					//��ⲽ��
		{
			return false;
		}

		if (!Simplex_Solver_SetConfig())					//��ⲽ��
		{
			return false;
		}
	}

	return true;
}

//���������η���ʼ��
static bool Simplex_Solver_init(Matrix_typedef A_s_temp, Matrix_typedef c_s_temp, Matrix_typedef b_s_temp, Matrix_typedef x_s_temp)
{
	A_s = A_s_temp; c_s = c_s_temp; b_s = b_s_temp; x_s = x_s_temp;
	m_s = A_s_temp.size(); n_s = c_s.size();
	Matrix_typedef N_T, B_T;
	Matrix_Row Row_temp;
	IN.push_back(Row_temp);//��IN�����һ����
	IB.push_back(Row_temp);//��IB�����һ����

	IN.begin()->clear();
	N_T.clear();
	cN.clear();
	xN.clear();
	IB.begin()->clear();
	B_T.clear();
	cB.clear();
	xB.clear();
	size_t i = 0;
	for (auto x_s_Row_temp : x_s)
	{
		for (auto x_s_RowElement_temp : x_s_Row_temp)
		{
			if (x_s_RowElement_temp == 0)	//��ʼ���ǻ�
			{
				IN.begin()->push_back(i);										//��ʼ���ǻ��ű꼯
				N_T.push_back((Project_MatrixTransposition(A_s))[i]);		//��ʼ��A�еķǻ����󣬵�ת��
				cN.push_back(c_s[i]);
				xN.push_back(x_s[i]);
			}
			else							//��ʼ����
			{
				IB.begin()->push_back(i);										//��ʼ�����ű꼯
				B_T.push_back((Project_MatrixTransposition(A_s))[i]);		//��ʼ��A�еĻ����󣬵�ת��
				cB.push_back(c_s[i]);
				xB.push_back(x_s[i]);
			}
		}
		i++;
	}
	//���B���Ƿ��󡪡��޸�
	while (B_T.size() != B_T.begin()->size())
	{
		B_T.push_back(*(N_T.end() - 1));
		N_T.erase(N_T.end() - 1);
		
		IB.begin()->push_back(*(IN.begin()->end() - 1));
		IN.begin()->erase(IN.begin()->end() - 1);

		cB.push_back(*(cN.end() - 1));
		cN.erase(cN.end() - 1);

		xB.push_back(*(xN.end() - 1));
		xN.erase(xN.end() - 1);
	}
	//�޸���
	B = Project_MatrixTransposition(B_T);
	N = Project_MatrixTransposition(N_T);
	

	Matrix_Row r_row_temp(n_s,0);
	Matrix_typedef r_temp;
	r_temp.push_back(r_row_temp);
	r_temp = Project_MatrixTransposition(r_temp);
	r = r_temp;//r�Ǹ�������

	if ((IB[0]).size() != m_s)//test
	{
		std::cout << "IB ��ʼ�����󣡣���" << std::endl;
		return false;
	}

	return true;
}

//�����Լ���
static bool Simplex_Solver_OptimalityTest()
{
	Matrix_typedef B_Inv, cB_T;
	cB_T = Project_MatrixTransposition(cB);
	if (!Project_MatrixInversion(B, &B_Inv))
	{
		std::cout << "B������󲻴��ڣ�����" << std::endl;
	}
	if (!Project_MatrixMultiplication(cB_T, B_Inv, &w_T))//����w_t
	{
		std::cout << "�󵥴��γ��ӵļ����������" << std::endl;
	}

	Matrix_typedef Matrix_temp, Aq_T, A_s_T = Project_MatrixTransposition(A_s);//Matrix_tempΪw_T��Aq�ĳ˻�
	Aq_T.push_back((*A_s_T.begin()));//��ʼ��Aq_T
	size_t i = 0;

	for (auto temp : IN[0])
	{
		q = temp;

		Aq_T[0] = A_s_T[q];//ȡ��A_s�ĵ�q��
		Aq = Project_MatrixTransposition(Aq_T);

		if (!Project_MatrixMultiplication(w_T, Aq, &Matrix_temp))
		{
			std::cout << "�����Լ�����˷����󣡣���" << std::endl;
			return false;
		}
		cq = (c_s[q])[0];
		rq = cq - (Matrix_temp[0])[0];
		(r[q])[0] = rq;

		if ((rq) < 0)
		{
			i++;//���i==0��ȫ��rq��0�����ʱ�ﵽ����
		}
	}

	if (i == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//���Ľ�����
static bool Simplex_Solver_SeekOptimizationDirection()
{
	//�ҳ�q
	Matrix_Row IN_temp = IN[0];
	Project_SelectionSort(IN_temp);//Ϊʵ��bland����(1)����С��������

	for (auto temp : IN_temp)
	{
		q = temp;
		if ((r[q])[0] < 0)//ʵ��bland����(1)��breakʱ��qʼ������С�ģ���Ϊǰ���IN�����˴�С��������򣬴�ʱq����������Ǳ�
		{
			break;
		}
	}

	//����Ľ�����
	Matrix_typedef B_Inv, B_Inv_Sub0, d, dq_T;//B_Inv_Sub0Ϊ-B_Inv
	Matrix_typedef Aq_T, A_s_T = Project_MatrixTransposition(A_s);
	Aq_T.push_back((*A_s_T.begin()));//��ʼ��Aq_T

	if (!Project_MatrixInversion(B, &B_Inv))
	{
		std::cout << "B������󲻴��ڣ�����" << std::endl;
	}

	B_Inv_Sub0 = Project_MatrixMultipliedByNumber(-1, B_Inv);

	Aq_T[0] = A_s_T[q];//ȡ��A_s�ĵ�q��
	Aq = Project_MatrixTransposition(Aq_T);
	if (!Project_MatrixMultiplication(B_Inv_Sub0, Aq, &d))
	{
		std::cout << "���Ľ��������˷����󣡣���" << std::endl;
		return false;
	}//�����d

	Matrix_Row dq_T_Row_temp(n_s, 0);
	dq_T.push_back(dq_T_Row_temp);

	for (auto j = 0; j < d.size(); j++)
	{
		(dq_T[0])[((IB[0])[j])] = (d[j])[0];
	}
	(dq_T[0])[q] = 1;
	dq = Project_MatrixTransposition(dq_T);//û��ʹ��ƴ�ӣ�Ϊ�˱�֤ÿ��������ÿһ�е��кţ����Ա������кŶ�Ӧ��

	//dq = d;//Project_MatrixMerging
	//dq_T = Project_MatrixTransposition(dq);//��dq��ת�ã�Ϊƴ����׼��
	//Matrix_Row eq_Row_temp(n_s - m_s, 0);
	//Matrix_typedef eq(1, eq_Row_temp);
	//if (!Project_MatrixMerging(dq_T, eq, &dq_T))
	//{
	//	std::cout << "���Ľ����򣬷��������ϲ����󣡣���" << std::endl;
	//	return false;
	//}
	//dq = Project_MatrixTransposition(dq_T);
	//(dq[q])[0] = 1;//��������յ�dq																����������BUG�����Ա����Ĵ�����滻

	size_t i = 0;
	for (auto d_Row_temp : d)
	{
		for (auto d_Row_Element_temp : d_Row_temp)
		{
			if (d_Row_Element_temp <= 0)
			{
				i++;
			}
		}
	}

	if (i == 0)
	{
		std::cout << "���Ľ����򣬽��޽磡����" << std::endl;
		return false;
	}

	return true;
}

//��ⲽ��
static bool Simplex_Solver_FindLambda()
{
	Matrix_Row IB_temp = IB[0];
	double lambda_Now = 0; size_t jp_Now = 0; lambda = 0;
	Project_SelectionSort(IB_temp);//Ϊʵ��bland����(2)����С��������

	for (auto temp : IB_temp)
	{
		jp_Now = temp;
		if ((dq[jp_Now])[0] < 0)//ʵ��bland����(2)��breakʱ��jpʼ������С�ģ���Ϊǰ���IB�����˴�С��������򣬴�ʱjp�ǳ��������Ǳ�
		{
			lambda_Now = -((x_s[jp_Now])[0]) / ((dq[jp_Now])[0]);
			if (lambda == 0)
			{
				lambda = lambda_Now;
				jp = jp_Now;
			}
			else
			{
				if (lambda_Now < lambda)
				{
					lambda = lambda_Now;
					jp = jp_Now;
				}
			}
		}
	}

	return true;
}

//��������
static bool Simplex_Solver_SetConfig()
{
	//����x_s
	Matrix_typedef lambda_dq = Project_MatrixMultipliedByNumber(lambda, dq);
	Project_MatrixPlusMatrix(lambda_dq, x_s, &x_s);

	//����
	//�����/��������Ǳ���IB/IN�е�λ��
	size_t i = 0, j = 0;
	for (auto IB_temp : IB[0])
	{
		if (IB_temp == jp)
		{
			break;
		}
		else
		{
			i++;
		}
	}
	for (auto IN_temp : IN[0])
	{
		if (IN_temp == q)
		{
			break;
		}
		else
		{
			j++;
		}
	}

	//IN��IB����Ԫ��
	double IN_IB_temp = 0;
	IN_IB_temp = (IN[0])[j];
	(IN[0])[j] = (IB[0])[i];
	(IB[0])[i] = IN_IB_temp;

	//N��B����Ԫ��
	Matrix_typedef N_T, B_T;
	Matrix_Row N_B_Row_temp;
	N_T = Project_MatrixTransposition(N);
	B_T = Project_MatrixTransposition(B);
	N_B_Row_temp = N_T[j];
	N_T[j] = B_T[i];
	B_T[i] = N_B_Row_temp;
	N = Project_MatrixTransposition(N_T);
	B = Project_MatrixTransposition(B_T);

	//cN��cB����Ԫ��
	Matrix_Row cN_cB_Row_temp;
	cN_cB_Row_temp = cN[j];
	cN[j] = cB[i];
	cB[i] = cN_cB_Row_temp;

	//xN��xB����Ԫ��
	Matrix_Row xN_xB_Row_temp;
	xN_xB_Row_temp = xN[j];
	xN[j] = xB[i];
	xB[i] = xN_xB_Row_temp;

	return true;
}

//��ձ���
void EraseAllVariables()
{
	//��ձ���
	A_s.clear();
	c_s.clear();
	b_s.clear();
	x_s.clear();
	B.clear();
	N.clear();
	cB.clear();
	cN.clear();
	xB.clear();
	xN.clear();
	IB.clear();
	IN.clear();
	r.clear();
	rB.clear();
	rN.clear();
	w_T.clear();
	Nq.clear();
	Aq.clear();
	D.clear();
	dq.clear();
}