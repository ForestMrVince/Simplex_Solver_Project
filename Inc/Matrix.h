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