#include<iostream>
#include<stack>
using namespace std;


int deletehead() {
	stack<int> s1;
	stack<int> s2;
	
	if (s2.size()<=0) {
		while (s1.size()>0) {
			int a = s1.top();
			s1.pop();
			s2.push(a);
		}	
		return -1;
	}
	if (s2.size()==0) {
		cout<<"这个队列是空的"<<endl;
	}
	int b = s2.top();
	s2.pop();
	return b;
}




int main() {
	int a = 8;
	int b = 8<<1; //位运算有与、或、异或、左移右移。 
	cout<<b<<endl; 
	
	return 0;
} 
