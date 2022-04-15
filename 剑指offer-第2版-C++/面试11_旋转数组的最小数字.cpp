#include<iostream>

using namespace std;

int FindMin(int *a, int length) {
	if (a == nullptr || length <=0) {
		return -9999;
	}
	int index1 = 0;
	int indexend = length-1;
	int indexmid = index1; //初始化为index1的目的是，当存在把前边0个数搬到后边去的时候，while循环根本进不去，所以最后的结果就是第一个数，即indexmid = index1 
	while(a[index1]>=a[indexend]) {
		if ((indexend-index1)==1) { //查找结束的条件是，两个指针分布在两个数组的分界处，后边的指针即是我们查找的结果 
			indexmid = indexend;
			break;
		}
		indexmid = (index1+indexend)/2;
		if (a[indexmid]>=a[index1]) {
			index1 = indexmid;
		}
		else if (a[indexmid]<=a[indexend]) {
			indexend = indexmid;
		}
		
	}
	return a[indexmid];
} 
/* 
上述的解法但不满足{0,1,1,1,1}的反转 可能反转后indexmid 无法判断位于哪一个递增数组中
例如：
{1,0,1,1,1}和{1,1,1,0,1} 
这个时候直接在这个范围内搜索最小的数 
*/ 
int MinNum(int *a, int left, int right) {
	int res = a[left];
	for (int i=left+1; i<=right; i++) {
		if (res>a[i]) {
			res = a[i];
		}	
	}
	return res;
}
int FindMin2(int *a, int length) {
	if (a==nullptr || length <=0) {
		return -9999;
	} 
	int index1 = 0;
	int indexend = length-1;
	int indexmid = index1;
	while (a[index1]>=a[indexend]) {
		if ((indexend-index1)==1) {
			indexmid = indexend;
			break;
		}
		indexmid = (index1+indexend)/2;
		if (a[index1]==a[indexend] && a[indexmid]==a[indexend]) { //特殊情况下需要顺序查找最小的数字 
			return MinNum(a, index1, indexend);
		}
		if(a[indexmid]>=a[index1]) {
			index1 = indexmid;
		}
		else if (a[indexmid]<=a[indexend]) {
			indexend = indexmid;
		}
	}
	return a[indexmid];
} 

int main() {
	int a[] = {1,1,1,0,1};
//	cout<<sizeof(a)<<endl; 
	int res = FindMin2(a, sizeof(a)/sizeof(int));
	cout<<"Result:"<<res<<endl; 
//	cout<<sizeof(bool)<<endl; //1 
	return 0;
} 
