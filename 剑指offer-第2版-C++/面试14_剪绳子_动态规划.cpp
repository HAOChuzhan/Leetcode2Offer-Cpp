#include<iostream>
#include<cmath>
using namespace std;

int a[9999] = {0}; 


//动态规划方法： 
int MaxlenNtoMsegment1(int length) {
	if (length<2) {
		return 0;
	}
	if (length==2) {
		return 1;
	}
	if (length==3) {
		return 2;
	}
	a[0]=0;
	a[1]=1;
	a[2]=2;
	a[3]=3;
	int max = 0;
	for (int i=4;i<=length; i++) {
		max = 0;
		for (int j=1; j<=i/2; j++) {
			int product = a[j]*a[i-j];
			if (max<product) {
				max = product;
			}
			a[i] = max;
		}
	}
	
	max = a[length];
	
	return max;
} 
//贪婪算法
int MaxlenNtoMsegment2(int length) {
	if (length<2) return 0;
	if (length==2) return 1;
	if (length==3) return 2;
	int timesof3 = length/3;
	int resof3 = length%3;
	
	if (resof3==1) --timesof3;
	int timesof2 = (length-timesof3*3)/2;
	
	return (int)(pow(3,timesof3)*pow(2, timesof2));
	
}

int main() {
	int res = MaxlenNtoMsegment1(10);
	int res2 = MaxlenNtoMsegment2(10);
	cout<<"贪婪算法结果是:"<<res2<<endl;
	
	cout<<"动态规划的结果是:"<<a[10]<<"，或者："<<res<<endl; 
	return 0;
} 
