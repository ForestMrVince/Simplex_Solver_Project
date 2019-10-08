#pragma once

#include <Project.h>

//矩阵运算函数声明
bool Project_GetAMatrix(Matrix_typedef *Matrix);	//矩阵输入函数
bool Project_ShowAMatrix(Matrix_typedef *Matrix);	//显示一个矩阵
bool Project_MatrixInversion(Matrix_typedef Matrix, Matrix_typedef *MatrixReversed);//求逆
Matrix_typedef Project_MatrixTransposition(Matrix_typedef Matrix);//求转置
bool Project_MatrixMultiplication(Matrix_typedef Matrix_front, Matrix_typedef Matrix_back, Matrix_typedef *MatrixMultiplicated);//矩阵相乘
Matrix_typedef Project_MatrixMultipliedByNumber(double Number, Matrix_typedef Matrix);//数与矩阵相乘
bool Project_MatrixPlusMatrix(Matrix_typedef Matrix_front, Matrix_typedef Matrix_back, Matrix_typedef *MatrixAdded);//矩阵相加

//行列式运算
double Project_Determinant(Matrix_typedef Determinant);//行列式