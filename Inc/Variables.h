#pragma once

#include <Project.h>

/*ȫ�ֱ�������*/
//extern Matrix_typedef Matrix;

/*��׼�ͱ���*/
extern Matrix_typedef A;//��ά����?? �� ??
extern Matrix_typedef c;//��������??ά�ȣ�
extern Matrix_typedef b;//��������??ά�ȣ�
extern Matrix_typedef x;//��������δ֪��������Ҫ���룬??ά�ȣ�
extern size_t m;//ά��??������Ҫ����
extern size_t n;//ά��??������Ҫ����

/*����׼�Ͳ�ֱ���*/
//���������ı���
extern Matrix_typedef A_s;//��ά����??_s �� ??_s
extern Matrix_typedef c_s;//��������??_sά�ȣ�
extern Matrix_typedef b_s;//��������??_sά�ȣ�
extern Matrix_typedef x_s;//����������ʼ�㣬����Ҫ���룬??_sά�ȣ�
extern size_t m_s;//ά��??_s������Ҫ����
extern size_t n_s;//ά��??_s������Ҫ����
//A��ֳɵ�
extern Matrix_typedef B;//����?? �� ??�ķ���
extern Matrix_typedef N;//�ǻ���?? �� (?? ? ??) ά�ľ���
//c��ֳɵ�
extern Matrix_typedef cB;//��c������Ϊ ?? ������������
extern Matrix_typedef cN;//�ǻ�c������Ϊ ?? ? ?? ������������
//x��ֳɵ�
extern Matrix_typedef xB;//������������Ϊ ?? ������������
extern Matrix_typedef xN;//�ǻ�����������Ϊ ?? ? ?? ������������

/*�����̱���*/
/*�����±꼯��*/
extern Matrix_typedef IB;//���������±꼯��		���ǳ���Ҫ��������
extern Matrix_typedef IN;//�ǻ��������±꼯��		���ǳ���Ҫ��������
/*����������ر���*/
extern Matrix_typedef r;//��Լ�������������еı�����0���������š��ȼ���rN��0.��
extern Matrix_typedef rB;//������Լ��������������Ϊ ?? ������������
extern Matrix_typedef rN;//�ǻ�����Լ��������������Ϊ ?? ? ?? ����������
/*�������б����*/
extern Matrix_typedef w_T;//�����γ���w��ת��
extern size_t q;//��ǰ��ɨ�赽�ķǻ������ĽǱ꣬������������Ǳ�
extern size_t jp;//��ǰ��ɨ�赽�Ļ������ĽǱ꣬���ǳ��������Ǳ�
extern double xq;//ĳһ���ǻ����������е�xq��0���������š��ȼ���r��0��rN��0.��
extern double rq;//xq��Ӧ�ģ�r����˵��rN�ĳ�Ա����
extern double cq;//xq��Ӧ�ģ�c����˵��cN�ĳ�Ա����
extern Matrix_typedef Nq;//xq��Ӧ�ģ�N�е�������
extern Matrix_typedef Aq;//xq��Ӧ�ģ�A�е�����������Nq��ȣ���ΪN�Ǵ�A�в�ֳ����ģ�
/*�Ľ�����*/
//�Ľ�����
extern Matrix_typedef D;//dq���ɵľ���
extern Matrix_typedef dq;//Dq��xq��Ӧ���У��Ľ�����
//����
extern double lambda;//��������

/*���׶η�����*/
extern Matrix_typedef xa;//�˹���������������δ֪��������Ҫ���룬??ά�ȣ�����ʼ��Ϊb����������������ɺ�xa����ȫΪ0������ԭ���ⲻ���С�
extern Matrix_typedef Aa;//���׶η��У��˹���������Ӧ��A���еľ���ʵ��Ϊ��λ��Iά��Ϊ?? �� ??
//extern Matrix_typedef x_2;//���׶η����ܱ������������ǽ�xaƴ��x���棬ά����??+??ά�ȡ���ʼ����ǰ���xȫΪ0�������xa=b
extern Matrix_typedef x_2;//���׶η����Ա�����������xaƴ��ԭ����x������棬ά��Ϊ ?? + ?? = n_s, m = m_s
extern Matrix_typedef c_2;//���׶η���һ�׶ε�c����ʼ��ΪֵȫΪ1����������ά��Ϊ??����ʱB=I����ʱ��λ��Iά��Ϊ?? �� ??
extern Matrix_typedef A_2;//���׶η��У��˹���������Ӧ��A���еľ���ʵ��Ϊ��λ��Iά��Ϊ?? �� ??���������ƴ�ӵ�ԭ����A�ĺ����γɵľ���ά��Ϊ?? �� (?? + ??)
extern Matrix_typedef b_2;//���׶η��е���������??ά�ȣ�