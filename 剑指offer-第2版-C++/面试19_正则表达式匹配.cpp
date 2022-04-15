#include<iostream>
#include<string.h>
using namespace std;

bool matchCore(char* str, char* pattern) {
	if (*str=='\0'&&*pattern=='\0') return true;
	if (*str!='\0'&&*pattern=='\0') return false;
	
	//这种情况下是最需要考虑的,当对应匹配的字符的pattern+1 = '*'，有以下的几种情况 
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
	char* s="ABC"; 相当於
	char* s={'A', 'B', 'C', '\0' };
	跟char数据的原理一致，只是表达方式不一样 
	*/
	char pattern1[] = ".*";
	char pattern2[] = "ab*ac*ca";

	var = (match(str,pattern1)==1)?"YES":"NO";
	cout<<"匹配是否成功？"<<var<<endl;
	
	return 0;
} 
