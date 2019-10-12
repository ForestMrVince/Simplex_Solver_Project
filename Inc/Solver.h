#pragma once

#include <Project.h>

/*��������⺯������*/
bool Project_solver_main();		//������

/*����¼�뺯��*/
static bool Question_Input();	//��������
static bool GetMatrix_A();		//��ȡ��׼���е�A
static bool GetMatrix_b();		//��ȡ��׼���е�b
static bool GetMatrix_c();		//��ȡ��׼���е�c
static void x_init();			//��ʼ���Ա���������x
/*����¼�뺯��*/

/*���׶η���⺯��*/
static bool TwoPhaseMethod_main();	//���׶η�������
static void x_2_init();				//ԭ�������x���˹�����xa�ϲ����x_2��ʼ��
static void c_2_init();				//��ʼ��һ�׶������c
static void A_2_init();				//��ʼ��һ�׶������A
/*���׶η���⺯��*/

/*�������������*/
static bool Simplex_Solver_main(Matrix_typedef A_s_temp, Matrix_typedef c_s_temp, Matrix_typedef b_s_temp, Matrix_typedef x_s_temp);	//�������������������
static bool Simplex_Solver_init(Matrix_typedef A_s_temp, Matrix_typedef c_s_temp, Matrix_typedef b_s_temp, Matrix_typedef x_s_temp);	//���������η���ʼ��
static bool Simplex_Solver_OptimalityTest();																							//�����Լ���
static bool Simplex_Solver_SeekOptimizationDirection();																					//���Ľ�����
static bool Simplex_Solver_FindLambda();																								//��ⲽ��
static bool Simplex_Solver_SetConfig();																									//��������
void EraseAllVariables();																												//��ձ�������
/*�������������*/

//TEST
//bool Simplex_Solver_main(Matrix_typedef A_s_temp, Matrix_typedef c_s_temp, Matrix_typedef b_s_temp, Matrix_typedef x_s_temp);	//�������������������