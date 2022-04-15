#include<iostream>
#include<string.h>
using namespace std;

/*
面试20  请实现一个函数来判断字符串是否表示数值。
例如： "+100"."5e2"、"-123"  及 、"-1E-16"都是表示数值。 
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
	char str1[] = "3.e555"; //我们此处小数点后的0可以省略 
	char str2[] = "3e.49" ; //这种阶数不为整数，所以表示错误 
	
	string res = (isNumeric(str2)==1)?"Yes":"No";
	cout<<"该字符串是否能表达数值："<<res<<endl;
	return 0;
} 
