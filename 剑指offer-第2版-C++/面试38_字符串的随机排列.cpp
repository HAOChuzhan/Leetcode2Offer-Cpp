#include<iostream>
#include<string.h> 
#include<algorithm>
using namespace std;
/*
面试38_字符串的排列

输入一个字符串，打印出该字符串中字符的所有排列。 
例如：
	str = "abc"; 则其有6种排列方式 
*/

void Permutation(char* str, char* begin) {
	if (*begin=='\0') {
		cout<<str<<endl;
	}
	else {
		for (char* ch=begin; *ch!='\0'; ++ch) {
			char tmp = *ch;
			*ch = *begin;
			cout<<"tmp1:"<<tmp<<" begin:"<<*begin<<endl; 
			*begin = tmp;
			
			Permutation(str, begin+1);
			
			tmp = *ch;
			*ch = *begin;
			cout<<"tmp2:"<<tmp<<" begin:"<<*begin<<endl; 
			*begin = tmp;
			
			
		}
	}
}
void Printstring(char* str) {
	if (str==nullptr) return;
	Permutation(str, str);
} 
/*举一反三： 
题目2： 
假设不是求解字符的所有排列，我们只是求字符的所有组合。例如给了a,b,c三个字符，他们的组合有a,b,c,ab,ac,bc,abc.   ab和ba是同一个组合 

*/


/*
题目3:
输入一个含有8个数字的数组，判断有没有可能把这8个数字分别放到正方体的8个顶点上，使得正方体上三组相对面四个顶点的和相等
 

*/ 


/*
题目4：
在一个8×8的棋盘上，摆着8个旗子，计算有多少种摆法使得任意两个皇后不在同一行同一列或者对角线上。
 
*/ 
int cnt = 0; //记录方法的次数 

void PrintArray(int a[], int len) {

	for (int i=0; i<len; i++) {
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
bool eight_check(int a[]) {
	for (int i=0; i<8; i++) {
		for (int j=i+1; j<8; j++) {
			if ((i-j)==a[i]-a[j] || j-i ==a[i]-a[j]) return false;
		}
	}
	return true;
}
void MethodNum(int a[], int begin) {
	if (begin==8) {
//		PrintArray(a,8);	
		if (eight_check(a)) {
			cnt++;
			PrintArray(a,8);
			cout<<cnt<<endl;
		} 
	}
	else {
		for (int i=begin; i<8; i++) {
			/*
			int tmp = a[i];
			a[i] = a[begin];
			a[begin] = tmp;
			*/
			swap(a[i], a[begin]) ;
			MethodNum(a, begin+1);
			//回溯 
			swap(a[i], a[begin]) ;
			/*
			tmp = a[i];
			a[i] = a[begin];
			a[begin] = tmp;
			*/
		}
	}
} 


int main () {
	char str[]= "abc";
	int a[8] = {0,1,2,3,4,5,6,7};
//	cout<<"===>"<<*(a+8)<<endl;
	cout<<sizeof(a)/sizeof(int)<<endl;
	cout<<"总的摆法有："<<endl;

	MethodNum(a, 0);
	/*==============字符串的所有排列方式================*/ 
//	Printstring(str);
	return 0;
}
