#include "Variables.h"

/*全局变量定义*/
//Matrix_typedef Matrix;//test

/*标准型变量*/
Matrix_typedef A;//二维矩阵，𝑚 × 𝑛
Matrix_typedef c;//列向量（𝑛维度）
Matrix_typedef b;//列向量（𝑛维度）
Matrix_typedef x;//列向量（未知数，不需要输入，𝑛维度）

/*求解标准型拆分变量*/
//A拆分成的
Matrix_typedef B;//基（𝑚 × 𝑚的方阵）
Matrix_typedef N;//非基（𝑚 × (𝑛 − 𝑚) 维的矩阵）
//c拆分成的
Matrix_typedef cB;//基c（长度为 𝑚 的零列向量）
Matrix_typedef cN;//非基c（长度为 𝑛 − 𝑚 的零列向量）
//x拆分成的
Matrix_typedef xB;//基变量（长度为 𝑚 的零列向量）
Matrix_typedef xN;//非基变量（长度为 𝑛 − 𝑚 的零列向量）

/*求解过程变量*/
/*迭代运算相关变量*/
Matrix_typedef r;//既约费用向量（所有的变量≥0，则结果最优。等价于rN≥0.）
Matrix_typedef rB;//基，既约费用向量（长度为 𝑚 的零列向量）
Matrix_typedef rN;//非基，既约费用向量（长度为 𝑛 − 𝑚 的列向量）
/*变量下标集合*/
Matrix_typedef IB;//基变量的下标集合			※非常重要！！！！
Matrix_typedef IN;//非基变量的下标集合		※非常重要！！！！
/*最优性判别变量*/
double xq = 0;//某一个非基变量（所有的xq≥0，则结果最优。等价于r≥0或rN≥0.）
double rq = 0;//xq对应的，r或者说是rN的成员变量
double cq = 0;//xq对应的，c或者说是cN的成员变量
Matrix_typedef Nq;//xq对应的，N中的列向量
Matrix_typedef Aq;//xq对应的，A中的列向量（与Nq相等，因为N是从A中拆分出来的）
/*改进变量*/
//改进方向
Matrix_typedef D;//dq构成的矩阵
Matrix_typedef dq;//Dq的xq对应的列
//步长
double lambda;//迭代步长

/*两阶段法变量*/
Matrix_typedef xa;//人工变量，列向量（未知数，不需要输入，𝑚维度），初始化为b！！！！，迭代完成后xa必须全为0，否则原问题不可行。
Matrix_typedef x_2;//两阶段法的总变量列向量，是将xa拼在x后面，维度是𝑛+𝑚维度。初始化后，前面的x全为0，后面的xa=b
Matrix_typedef c_2;//两阶段法第一阶段的c，初始化为值全为1的列向量，维度为𝑚，此时B=I，此时单位阵I维度为𝑚 × 𝑚