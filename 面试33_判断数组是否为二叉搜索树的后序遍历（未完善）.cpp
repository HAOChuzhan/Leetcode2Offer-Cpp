#include<iostream>
#include<string.h>
using namespace std;

/*
面试33 - 首先这道题我们要明白BST的后序遍历序列的特点，序列的最后一个值是bst的根节点，然后就是bst的特点，左孩子的值一定小于右孩子。

这道题类似于面试7中的 重建二叉树，都是利用了二叉树的根节点，然后递归地去处理根节点的左右子树 
 
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
	string res = VerifySeqOfBST(seq, len)==1?"是":"否"; 
	cout<<"是否是BST的后序遍历序列："<<res;
	
	return 0;
}
