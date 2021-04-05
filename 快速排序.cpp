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
int getpivot(int *a, int L, int R) { //快速排序选主元
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
	cout<<"选取的主元是："<<endl;
	int i = left;
	int j = right-1;
	for(;;) /*for（；；）死循环里的两个；；代表两个空语句，编译器一般会优化掉它们，直接进入循环体。
			while（1）死循环里的1被看成表达式，每循环一次都要判断常量1是不是等于零。
			即，相对来说for式死循环更加高效一点*/
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

