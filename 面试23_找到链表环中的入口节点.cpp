#include<iostream>

using namespace std;
typedef long long ll;
/*
ͻȻ����һ���򵥵����⣬���»��н׳˵�ʵ�ַ����� 
����23���ҵ������е���ڽڵ� 
*/
struct ListNode{
	int val;
	ListNode *next; 
}; 

//��1���׳˵ĵݹ�ʵ�� 
ll Stage(int n) {

	if (n<0) return -9999;
 	if (n==1||n==0) return 1;
	
	return n*Stage(n-1);
	
}
//��2���׳˵�ѭ��ʵ��
long long Stage_R(int n) {
	
	if (n<0) return -9999;
 	if (n==1||n==0) return 1;
 	
	long long res = 1;
 	
 	for (int i=2; i<=n; i++) {
 		res *= i;
	}
	return res;
} 
//���ж������Ƿ���ڻ���Ҳ����ʹ�ÿ���ָ�������С������ָ��׷������ָ����ô�ʹ��ڻ��������ָ�뵽��ĩβ��û��������ָ�룬��ô�Ͳ����ڻ���
 

int main() {
	long k = 20;
	cout<<Stage(k)<<endl;
	cout<<Stage_R(k)<<endl;
	
	return 0;
} 
