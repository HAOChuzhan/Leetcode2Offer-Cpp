#include<iostream>
#include<string.h> 
#include<algorithm>
using namespace std;
/*
����38_�ַ���������

����һ���ַ�������ӡ�����ַ������ַ����������С� 
���磺
	str = "abc"; ������6�����з�ʽ 
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
/*��һ������ 
��Ŀ2�� 
���費������ַ����������У�����ֻ�����ַ���������ϡ��������a,b,c�����ַ������ǵ������a,b,c,ab,ac,bc,abc.   ab��ba��ͬһ����� 

*/


/*
��Ŀ3:
����һ������8�����ֵ����飬�ж���û�п��ܰ���8�����ֱַ�ŵ��������8�������ϣ�ʹ��������������������ĸ�����ĺ����
 

*/ 


/*
��Ŀ4��
��һ��8��8�������ϣ�����8�����ӣ������ж����ְڷ�ʹ�����������ʺ���ͬһ��ͬһ�л��߶Խ����ϡ�
 
*/ 
int cnt = 0; //��¼�����Ĵ��� 

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
			//���� 
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
	cout<<"�ܵİڷ��У�"<<endl;

	MethodNum(a, 0);
	/*==============�ַ������������з�ʽ================*/ 
//	Printstring(str);
	return 0;
}
