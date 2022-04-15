#include<iostream>

using namespace std;
typedef long long ll;

//��Ŀһ��쳲��������� 
// ���õݹ������д�n��1 �ļӷ��� 
int Add1toN_recursive(int n) {
	return n<=0?0:n+Add1toN_recursive(n-1);
}

// ���־���ݹ�д��Ч�ʼ������ 
ll Fibonacci(int n) {
	if (n==0) return 0;
	if (n==1) return 1;
	return Fibonacci(n-1)+Fibonacci(n-2);
}
//��������ѭ���ķ�������  
ll  Fibonacci_xunhun(int n) {
	int result[2] = {0,1};
	if (n<2) {
		return result[n];
	}
	ll one = 0;
	ll two = 1;
	ll fiboN = 0;
	for (int i=2; i<=n; i++) {
		fiboN = one + two;
		one =two;
		two = fiboN;
	} 
	return fiboN;
}
/*��������

[ f(n)   f(n-1)     [1 1
  f(n-1) f(n-2)] =   1 0] ��n-1�η��� 

*/
//��Ŀ����������̨�� 
 
int main() {
	
	cout<<Fibonacci_xunhun(50);
	
	return 0;
}
