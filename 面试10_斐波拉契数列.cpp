#include<iostream>

using namespace std;
typedef long long ll;

//题目一：斐波拉契数列 
// 利用递归来进行从n到1 的加法。 
int Add1toN_recursive(int n) {
	return n<=0?0:n+Add1toN_recursive(n-1);
}

// 此种经典递归写法效率及其低下 
ll Fibonacci(int n) {
	if (n==0) return 0;
	if (n==1) return 1;
	return Fibonacci(n-1)+Fibonacci(n-2);
}
//方法二：循环的方法进行  
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
/*方法三：

[ f(n)   f(n-1)     [1 1
  f(n-1) f(n-2)] =   1 0] 的n-1次方。 

*/
//题目二：青蛙跳台阶 
 
int main() {
	
	cout<<Fibonacci_xunhun(50);
	
	return 0;
}
