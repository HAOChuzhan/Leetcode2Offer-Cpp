#include<iostream>
#include<string.h>
using namespace std;

/*
����20  ��ʵ��һ���������ж��ַ����Ƿ��ʾ��ֵ��
���磺 "+100"."5e2"��"-123"  �� ��"-1E-16"���Ǳ�ʾ��ֵ�� 
*/ 
bool scanUnsignedInteger(const char **str) {
	const char *before = *str;
	while (**str!='\0'&&**str>='0'&&**str<='9') ++(*str);
	
	return *str>before;
}

bool scanInterger(const char** str) {
	if (**str=='+'||**str=='-') ++(*str);
	return scanUnsignedInteger(str);
}


bool isNumeric(const char *str) {
	if (str==nullptr) return false;
	bool numeric = scanInterger(&str);
	if (*str=='.') {
		++str;
		numeric = scanUnsignedInteger(&str) || numeric;
	}
	
	if (*str=='e'||*str=='E') {
		++str;
		numeric = numeric&&scanInterger(&str);
	}
	return numeric&&*str=='\0';
}

int main () {
	char str1[] = "3.e555"; //���Ǵ˴�С������0����ʡ�� 
	char str2[] = "3e.49" ; //���ֽ�����Ϊ���������Ա�ʾ���� 
	
	string res = (isNumeric(str2)==1)?"Yes":"No";
	cout<<"���ַ����Ƿ��ܱ����ֵ��"<<res<<endl;
	return 0;
} 
