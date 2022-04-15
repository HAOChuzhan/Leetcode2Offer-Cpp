#include<iostream>

using namespace std;

/*
根据公式进行简化乘方的计算，分为奇偶次幂来计算。 
*/

double PowerWithExponent(double base, int exponent) {
	if (base==0.0 && exponent<0) return -9999.0;                 //判断不符合数学规则的条件(分数的分母不为0)
	if (exponent==0) return 1;
	if (exponent==1) return base;

	if (exponent<0) 
	{
		exponent = -exponent;
		if ((exponent&1)==1) {  
			return PowerWithExponent(1.0/(base*base), exponent>>1)*(1.0/base); //判断幂为奇数时(直接使用位运算，比取余%更加高效) 
		}
		else {
			return PowerWithExponent(1.0/(base*base), exponent>>1);
		}
	}
	else {
		if ((exponent&1)==1) {  
			return PowerWithExponent(base*base, exponent>>1)*base; //判断幂为奇数时(直接使用位运算，比取余%更加高效) 
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
