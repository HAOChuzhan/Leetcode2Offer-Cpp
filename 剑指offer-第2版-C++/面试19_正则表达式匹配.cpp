#include<iostream>
#include<string.h>
using namespace std;

bool matchCore(char* str, char* pattern) {
	if (*str=='\0'&&*pattern=='\0') return true;
	if (*str!='\0'&&*pattern=='\0') return false;
	
	//���������������Ҫ���ǵ�,����Ӧƥ����ַ���pattern+1 = '*'�������µļ������ 
	if (*(pattern+1)=='*') {
		if (*pattern==*str ||(*pattern=='.'&&*str!='\0')) 
			return matchCore(str+1, pattern+2) || matchCore(str+1, pattern) || matchCore(str, pattern+2);
		else 
			return matchCore(str, pattern+2);
	}
	if (*str==*pattern||(*str!='\0'&&*pattern=='.')) return matchCore(str+1, pattern+1);
	
	return false;
}
bool match(char *str, char *pattern) {
	if (str==nullptr ||pattern==nullptr) {
		return false;
	}
	return matchCore(str, pattern);
}
int main () {

	char str[] = "agsgsf"; 
	string var;
	
	/*
	char* s="ABC"; �൱�
	char* s={'A', 'B', 'C', '\0' };
	��char���ݵ�ԭ��һ�£�ֻ�Ǳ�﷽ʽ��һ�� 
	*/
	char pattern1[] = ".*";
	char pattern2[] = "ab*ac*ca";

	var = (match(str,pattern1)==1)?"YES":"NO";
	cout<<"ƥ���Ƿ�ɹ���"<<var<<endl;
	
	return 0;
} 
