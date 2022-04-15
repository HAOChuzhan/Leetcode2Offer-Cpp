#include<iostream>
//#include<algorithm>
//#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b) {
	int t;
	t = *a;
	*a = *b;
	*b = t;
}
int getpivot(int *a, int L, int R) { //��������ѡ��Ԫ
	int center = (L+R)/2;
	if (a[R]<a[L]) 		swap(&a[R], &a[L]);
	if (a[R]<a[center]) swap(&a[R], &a[center]);
	if (a[center]<a[L]) swap(&a[center], &a[L]);
	swap(&a[center], &a[R-1]);
	return a[R-1];
}

void Quicksort(int *a, int left, int right) {
	
//	cout<<left<<","<<right<<endl; 
	int pivot = getpivot(a, left, right);
	cout<<"ѡȡ����Ԫ�ǣ�"<<endl;
	int i = left;
	int j = right-1;
	for(;;) /*for����������ѭ�������������������������䣬������һ����Ż������ǣ�ֱ�ӽ���ѭ���塣
			while��1����ѭ�����1�����ɱ��ʽ��ÿѭ��һ�ζ�Ҫ�жϳ���1�ǲ��ǵ����㡣
			���������˵forʽ��ѭ�����Ӹ�Чһ��*/
	{
		while(a[++i] < pivot);
		while(a[--j] > pivot);
		if (i<j) swap(&a[i], &a[j]);
		else break;
	}
	swap(&a[i], &a[right-1]);
	Quicksort(a, left, i-1);
	Quicksort(a, i+1, right);
	
}
void Quick_sort(int *a, int N) {
	Quicksort(a, 0 ,N-1);
}

int main() {
	int a[] = {2, 4, 3, 5, 9, 7, 8};
	int len = sizeof(a)/sizeof(int);
	cout<<len<<endl;
	Quick_sort(a, len); 
	for (int i=0; i<7; i++) {
		cout<<a[i]<< " ";
	}
	
	return 0;
}

