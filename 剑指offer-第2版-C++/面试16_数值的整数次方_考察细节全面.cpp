#include<iostream>

using namespace std;

/*
���ݹ�ʽ���м򻯳˷��ļ��㣬��Ϊ��ż���������㡣 
*/

double PowerWithExponent(double base, int exponent) {
	if (base==0.0 && exponent<0) return -9999.0;                 //�жϲ�������ѧ���������(�����ķ�ĸ��Ϊ0)
	if (exponent==0) return 1;
	if (exponent==1) return base;

	if (exponent<0) 
	{
		exponent = -exponent;
		if ((exponent&1)==1) {  
			return PowerWithExponent(1.0/(base*base), exponent>>1)*(1.0/base); //�ж���Ϊ����ʱ(ֱ��ʹ��λ���㣬��ȡ��%���Ӹ�Ч) 
		}
		else {
			return PowerWithExponent(1.0/(base*base), exponent>>1);
		}
	}
	else {
		if ((exponent&1)==1) {  
			return PowerWithExponent(base*base, exponent>>1)*base; //�ж���Ϊ����ʱ(ֱ��ʹ��λ���㣬��ȡ��%���Ӹ�Ч) 
		}
		else {
			return PowerWithExponent(base*base, exponent>>1);
		}
	}	
	
}

int main() {
	double res = PowerWithExponent(9.0, -3);
	cout<<res<<endl;
	return 0;
}
