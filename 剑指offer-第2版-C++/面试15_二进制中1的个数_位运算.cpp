#include<iostream>

using namespace std;


// ���ַ����������ڸ��������ܻ�������ѭ���� 
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
// ���ֲ���ÿ�ν�����������flag��־����һλ 
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
 ͨ�����ɷ��֣�һ������1�������ԭ�ȵ�������������󣬻�������������ұߵ�1��������
 ������ǿ���ͨ�����������Ĵ��������ָ����Ķ����Ʊ�ʾ�ж��ٸ�1  
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
