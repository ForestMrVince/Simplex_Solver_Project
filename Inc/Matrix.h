#pragma once

#include <Project.h>

//�������㺯������
bool Project_GetAMatrix(Matrix_typedef *Matrix);	//�������뺯��
bool Project_ShowAMatrix(Matrix_typedef *Matrix);	//��ʾһ������
bool Project_MatrixInversion(Matrix_typedef Matrix, Matrix_typedef *MatrixReversed);//����
Matrix_typedef Project_MatrixTransposition(Matrix_typedef Matrix);//��ת��
bool Project_MatrixMultiplication(Matrix_typedef Matrix_front, Matrix_typedef Matrix_back, Matrix_typedef *MatrixMultiplicated);//�������
Matrix_typedef Project_MatrixMultipliedByNumber(double Number, Matrix_typedef Matrix);//����������
bool Project_MatrixPlusMatrix(Matrix_typedef Matrix_front, Matrix_typedef Matrix_back, Matrix_typedef *MatrixAdded);//�������
static Matrix_typedef AdjugateMatrix_fun(Matrix_typedef Matrix);//����������;

//����ʽ����
double Project_Determinant(Matrix_typedef Determinant);//����ʽ
static void FullyArranged_fun(Matrix_typedef *FullyArranged, size_t n);//������ʽ������������Ͼ���
static void FullyArranged_fun_Exhaustive(Matrix_typedef *FullyArranged, Matrix_Row FullyArrangedRowElement_temp, size_t start, size_t n, std::vector<size_t> *Line, std::vector<size_t> *factorial_vec);//������ʽ������������Ͼ���������ٵݹ麯��
static double ReverseOrderNumber_fun(Matrix_Row FullyArranged_row);//��������
static void ReverseOrderNumber_fun_Exhaustive(double *Number, Matrix_Row Row);//����������������ٵݹ麯��

//����������
bool Project_MatrixMerging(Matrix_typedef Matrix_front, Matrix_typedef Matrix_back, Matrix_typedef *Matrix_Merged);//ǰ��ϲ��������󣬡�δ����BUG

//��������
void Project_SelectionSort(Matrix_Row &arr);//��С��������

//test
//void FullyArranged_fun(Matrix_typedef *FullyArranged, size_t n);
//double ReverseOrderNumber_fun(Matrix_Row FullyArranged_row);//��������