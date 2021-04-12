#include<iostream>
#include<string.h>
using namespace std;


/*
打印从1到最大的n位数，例如输入3时，会打印出1到999的数字。
因为没规定数字的n的范围所以直接用整型或者是长整型的时候会溢出。
这个时候我们就要考虑使用数组或字符串完成该题目。 
*/ 


bool Increment(char *number) {
	bool Isoverflow = false;
	int TakeOver = 0;
	int nLength = strlen(number);
	for (int i=nLength-1; i>=0; i--) {
		int nSum = number[i]-'0'+TakeOver;
		if (i==nLength - 1) nSum++;
		if  (nSum>=10) {
			if (i==0) Isoverflow = true;
			else {
				nSum -= 10;
				TakeOver = 1;
				number[i] = '0'+nSum;
			}
		} 
		else {
			number[i] = '0'+nSum;
			break;
		}
	}
	return Isoverflow;
}
void PrintNumber(char *number) {
	int nLength = strlen(number);
	bool isBeginning = true;
	for (int i=0; i<nLength; i++) {
		if (isBeginning&&number[i]!='0')
			isBeginning = false;
		if (!isBeginning) cout<<number[i];
	}
	cout<<"\t";
}

void PrintToMaxOfNDigital(int n) {
	if (n<=0) return;
	char *number = new char[n+1];
	memset(number, '0', n);
	number[n] = '\0';
	
	while (!Increment(number)) {
		PrintNumber(number);
	}
	delete[] number;
} 


int main() {
	
	PrintToMaxOfNDigital(55);
	return 0;
} 
