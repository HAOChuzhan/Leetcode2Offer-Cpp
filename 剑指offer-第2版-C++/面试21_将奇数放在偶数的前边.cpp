#include<iostream>
using namespace std;

/*
���������˳��ʹ������λ��ż����ǰ�� 
*/

bool isDivideByThree(int n) {
	return (n%3)!=0;
}

bool isEven(int n) {
	return (n&0x1)==0;
}

//����1 ֱ�ӱ���һ�飬��ż���Ƶ�ĩβ������������ǰ�ƶ�һλ��ʱ�临�Ӷ�ΪO(n^2) 



//����2 ֱ������˫ָ�����ǰ���ż������������λ�ã�ʱ�临�Ӷȿռ临�Ӷȶ���O(n) 
//�Ľ��� ���뺯��ͨ�÷�����ʹ�ÿ��԰������Ƶ�ż��ǰ�ߣ���3�������Ƶ�����������ǰ����һ�����⡣ 
void swaptheOE2(int *a, int len, bool (*func)(int)) {
	if (a==nullptr || len==0) return;
	
	int i = 0;
	int j = len-1;
	
	while (i<j) {
		while(i<len && !func(a[i])) ++i;	
		while(j>0 && func(a[j]))   --j;

		if (i<j) {
			int tmp = a[i];
			a[i] = a[j];
			a[j] =tmp;
			i++;j--;
		} 	
	}
}
// ����3 ��Ҫ�������ȴ�С�ռ�����飬ֱ�ӱ���һ�飬������������ͷ�˿�ʼ��䣬ż��������β�˿�ʼ��� 
void swaptheOE3(int *a, int len) {
	
	
}
 
int main() {
	int a1[] = {2,4,3,7,8,5,3,2,1};
	int a2[] = {2,0,0,0,0,0,2,2,22,2};
	
	int len = sizeof(a1)/sizeof(int);
	cout<<len<<endl; //�����С 
	swaptheOE2(a1, len, isDivideByThree);
	
    /**************************���չʾ**************************/	
	for (int i=0; i<len; i++) {
		cout<<a1[i]<<" "; 
	}
	cout<<endl;
	
	return 0;
} 
