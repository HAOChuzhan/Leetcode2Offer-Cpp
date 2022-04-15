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
	//若该节点没有右节点，则判断其父节点，并一直往上遍历，查看其是否有作为父节点的左节点的节点，则该节点是其下一个节点。 
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
