#include<iostream>
#include<string.h>
using namespace std;

/*
����33 - �������������Ҫ����BST�ĺ���������е��ص㣬���е����һ��ֵ��bst�ĸ��ڵ㣬Ȼ�����bst���ص㣬���ӵ�ֵһ��С���Һ��ӡ�

���������������7�е� �ؽ������������������˶������ĸ��ڵ㣬Ȼ��ݹ��ȥ������ڵ���������� 
 
*/
bool VerifySeqOfBST(int seq[], int len) {
	if (seq==nullptr || len<=0) return false;
	int root = seq[len-1];
	int i=0;
	for (;i<len-1;i++) {
		if (seq[i]>root)
			break;
	} 
	int j=i;
	for (; j<len-1; j++) {
		if (seq[j]<root)
			return false;
	}
	bool left = true;
	if (i>0) {
		left = VerifySeqOfBST(seq, i);
	}
	bool right = true;
	if (j<len-1) right = VerifySeqOfBST(seq+i, len-i-1);
	 
	return (left&&right);
} 

int main() {
	
	int seq[] = {5,7,6,12,9,10,8};
	int len =  sizeof(seq)/sizeof(int);
	cout<<len<<endl;
	string res = VerifySeqOfBST(seq, len)==1?"��":"��"; 
	cout<<"�Ƿ���BST�ĺ���������У�"<<res;
	
	return 0;
}
