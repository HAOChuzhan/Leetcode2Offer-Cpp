#include<iostream>
using namespace std;

/*
���������˳��ʹ������λ��ż����ǰ�� 
*/

//����1 ֱ�ӱ���һ�飬��ż���Ƶ�ĩβ������������ǰ�ƶ�һλ��ʱ�临�Ӷ�ΪO(n^2) 
void swaptheOE1(int *a, int len) {
	if (a==nullptr) return;

	for (int i=0; i<len; i++) {
	
		if (a[i]%2 == 0) {                        //Ϊż����ʱ�� 
			cout<<"���֣�"<<a[i]<<endl;
			int tmp = a[i];
			for (int j=i; j<len-1; j++) {
				a[j] = a[j+1];
			} 
			a[len-1] = tmp;
		}
	}
	
}
//����2 ֱ������˫ָ�����ǰ���ż������������λ�ã�ʱ�临�Ӷȿռ临�Ӷȶ���O(n) 
void swaptheOE2(int *a, int len) {
	if (a==nullptr) return;
	
	int i = 0;
	int j = len-1;
	
	while (i<j) {
		while(a[i]%2==1) {
			++i;
			if (i==len) break;
		}
		while(a[j]%2==0) {
			--j;
			if (j<0) break;
		}
		
		if (i>=j) break;
		
		int tmp = a[i];
		a[i] = a[j];
		a[j] =tmp;
		i++;j--;
	}
}
// ����3 ��Ҫ�������ȴ�С�ռ�����飬ֱ�ӱ���һ�飬������������ͷ�˿�ʼ��䣬ż��������β�˿�ʼ��� 
void swaptheOE3(int *a, int len) {
	
	
	
}
 
int main() {
	int a1[] = {2,4,3,7,8,5,3,2,1};
	int a2[] = {2,0,0,0,0,0,2,2,22,2};
	
	int len = sizeof(a1)/sizeof(int);
	cout<<len<<endl;
	swaptheOE2(a1, len);
	
    /**************************���չʾ**************************/	
	for (int i=0; i<len; i++) {
		cout<<a1[i]<<" "; 
	}
	cout<<endl;
	
	return 0;
} 
