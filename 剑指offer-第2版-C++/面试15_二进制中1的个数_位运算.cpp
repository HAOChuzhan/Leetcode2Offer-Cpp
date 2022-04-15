#include<iostream>

using namespace std;


// 这种方法不适用于负数，可能会引起死循环。 
int oneofnum1(int n) {
	int count = 0;
	while(n>0) {
		if (n&1) {
			count++;
		}
		n = n>>1;
	}
	return count; 
}
// 数字不变每次将与数字异或的flag标志左移一位 
int oneofnum2(int n) {
	int count = 0;
	unsigned int flag = 1;
	while(flag) {
		if (n&flag) count++;
		flag = flag<<1;
	}
	return count;
}
/* 
 通过规律发现，一个数减1后的数与原先的数进行与操作后，会把整个数中最右边的1消除掉。
 因此我们可以通过这样操作的次数来发现该数的二进制表示有多少个1  
*/
int oneofnum3(int n) {
	int count = 0;
	while (n) {
		++count;
		n = (n-1)&n;
	}
	return count;
}

int main() {
	
	cout<<oneofnum3(127)<<endl;
	return 0;
}
