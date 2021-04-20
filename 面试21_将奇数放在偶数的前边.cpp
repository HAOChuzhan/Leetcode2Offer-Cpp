#include<iostream>
using namespace std;

/*
调整数组的顺序使得奇数位于偶数的前边 
*/

//方法1 直接遍历一遍，让偶数移到末尾，其余数字向前移动一位，时间复杂度为O(n^2) 
void swaptheOE1(int *a, int len) {
	if (a==nullptr) return;

	for (int i=0; i<len; i++) {
	
		if (a[i]%2 == 0) {                        //为偶数的时候 
			cout<<"数字："<<a[i]<<endl;
			int tmp = a[i];
			for (int j=i; j<len-1; j++) {
				a[j] = a[j+1];
			} 
			a[len-1] = tmp;
		}
	}
	
}
//方法2 直接利用双指针进行前后的偶数和奇数互换位置，时间复杂度空间复杂度都是O(n) 
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
// 方法3 需要额外的相等大小空间的数组，直接遍历一遍，将奇数从数组头端开始填充，偶数从数组尾端开始添加 
void swaptheOE3(int *a, int len) {
	
	
	
}
 
int main() {
	int a1[] = {2,4,3,7,8,5,3,2,1};
	int a2[] = {2,0,0,0,0,0,2,2,22,2};
	
	int len = sizeof(a1)/sizeof(int);
	cout<<len<<endl;
	swaptheOE2(a1, len);
	
    /**************************结果展示**************************/	
	for (int i=0; i<len; i++) {
		cout<<a1[i]<<" "; 
	}
	cout<<endl;
	
	return 0;
} 
