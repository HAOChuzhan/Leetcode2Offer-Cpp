#include<iostream>

using namespace std;

struct BinaryTreeNode {
	int val;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	BinaryTreeNode* parent;
};

BinaryTreeNode* GetNext(BinaryTreeNode* pNode) {
	if (pNode==nullptr) {
		return nullptr;
	}
	BinaryTreeNode* pNext = nullptr;
	if (pNode->right!=nullptr) {
		BinaryTreeNode* pRight = pNode->right;
		while (pRight->left!=nullptr) {
			pRight = pRight->left;
		}
		pNext = pRight;
	}
	//���ýڵ�û���ҽڵ㣬���ж��丸�ڵ㣬��һֱ���ϱ������鿴���Ƿ�����Ϊ���ڵ����ڵ�Ľڵ㣬��ýڵ�������һ���ڵ㡣 
	else if (pNode->parent!=nullptr) {
		BinaryTreeNode* pParent = pNode->parent;
		BinaryTreeNode* pCurrent = pNode;
		while (pParent!=nullptr && pCurrent==pParent->right) {
			pCurrent = pParent;
			pParent = pParent->parent;
		}
		pNext = pParent;
	}
	return pNext;
} 


int main() {
		
	
	return 0;
}
