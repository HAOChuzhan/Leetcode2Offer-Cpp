#include<iostream>

using namespace std;
typedef long long ll;
/*
突然遇到一个简单的问题，以下还有阶乘的实现方法。 
面试23：找到链表环中的入口节点 
*/
struct ListNode{
	int val;
	ListNode *next; 
}; 

//法1：阶乘的递归实现 
ll Stage(int n) {

	if (n<0) return -9999;
 	if (n==1||n==0) return 1;
	
	return n*Stage(n-1);
	
}
//法2：阶乘的循环实现
long long Stage_R(int n) {
	
	if (n<0) return -9999;
 	if (n==1||n==0) return 1;
 	
	long long res = 1;
 	
 	for (int i=2; i<=n; i++) {
 		res *= i;
	}
	return res;
} 
//先判断链表是否存在环，也可以使用快慢指针来进行。如果快指针追上了慢指针那么就存在环，如果快指针到了末尾都没有遇到慢指针，那么就不存在环。
 

int main() {
	long k = 20;
	cout<<Stage(k)<<endl;
	cout<<Stage_R(k)<<endl;
	
	return 0;
} 
