#include<iostream>
#include<string.h>
using namespace std;


/*
��ӡ��1������nλ������������3ʱ�����ӡ��1��999�����֡�
��Ϊû�涨���ֵ�n�ķ�Χ����ֱ�������ͻ����ǳ����͵�ʱ��������
���ʱ�����Ǿ�Ҫ����ʹ��������ַ�����ɸ���Ŀ�� 
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
