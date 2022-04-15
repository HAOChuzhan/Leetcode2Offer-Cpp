#include<iostream>

using namespace std;

/*
题目一： 
在时间复杂度O(1)内删除链表节点 
*/ 
struct ListNode{
	int val;
	ListNode *next;
	
};

void PrintList(ListNode* head) {	
	ListNode* p = head->next;
	cout<<"链表为"; 
	while(p) {
		cout<<p->val<<"->";		
		p= p->next; 
	}
	cout<<"NULL"<<endl;
}
ListNode* CreatListTail() {
	int x;
	ListNode* head, *p, *tail;
	head = (ListNode*)malloc(sizeof(ListNode));
	if (head==nullptr)
		return head;
	tail = head;
	cout<<"请输入要录入的数以0结束"<<endl;
	cin>>x;
	while(x!=0) {
		p = (ListNode*)malloc(sizeof(ListNode));
		if (p ==NULL) return p;
		p->val = x;
		
		tail->next = p;
		tail = p;
		tail->next = NULL;
		cin >>x;
	}
	return head;
}
/* 如果直接给出一个链表中需要删除的节点，我们可以轻易的得到其next节点。我们要删除该节点的话，
就可以直接把其next节点的值赋给被删除的节点，然后把其next节点删除，从而实现偷梁换柱。

然后我们需要考虑全面，1.该节点不是尾节点；2.既是头节点又是尾节点; 3.是尾节点，且链表节点不止一个。 
 */ 
void DeleteNode(ListNode **pHead, ListNode *pToDelete) {
	if (!pHead || !pToDelete) return;
	if (pToDelete->next!=nullptr) {
		ListNode* pNext = pToDelete->next;
		cout<<"删除节点是"<<pToDelete->val<<endl; 
		pToDelete->val = pNext->val;
		pToDelete->next = pNext->next;
		delete pNext;
		pNext = nullptr;
	} 
	else if (*pHead==pToDelete) {
		delete pToDelete;
		pToDelete = nullptr;
		*pHead = nullptr;
	}
	else {
		ListNode* Node = *pHead;
		while (Node->next!=pToDelete) {
			Node = Node->next;
		}
		Node->next = nullptr;
		delete pToDelete;
		pToDelete = nullptr;
	}
	
}
/*
题目二： 
删除链表中重复节点： 
加入pPreNode来定位删除节点开始的前一个节点，方便删除节点后与后边的节点相连接。 
*/ 
void DeleteDuplication(ListNode** pHead) {
	if (*pHead==nullptr || pHead==nullptr) 
		return;
	ListNode* pPreNode = nullptr;
	ListNode* pNode = *pHead;
	while (pNode!=nullptr) {
		ListNode* pNext = pNode->next;
		bool needDelete = false;
		if (pNext!=nullptr && pNext->val == pNode->val) {
			needDelete = true;
		}
		if (!needDelete) {
			pPreNode = pNode;
			pNode=pNode->next;
		}
		else {
			int value = pNode->val;
			ListNode *pToDelete = pNode;
			while (pToDelete!=nullptr&&pToDelete->val==value) {
				pNext = pToDelete->next;
				delete pToDelete;
				pToDelete = nullptr;
				pToDelete = pNext;
				
				if (pPreNode==nullptr) {
					*pHead = pNext;
				}
				else 
					pPreNode->next = pNext;
				pNode = pNext;
			}
		}
	}
	
	
}
int main() {
	//创建链表 
	ListNode *head = CreatListTail(); //这里的头指针是空节点 
	PrintList(head);
	
	//删除指定节点 
	ListNode *ToDelete = head->next->next;
	ListNode **pHead = new ListNode*();//(ListNode**)malloc(sizeof(ListNode));
	*pHead = head->next;
	
	
	DeleteNode(pHead, ToDelete);
	PrintList(head);
	//删除重复节点 
	DeleteDuplication(pHead);
	PrintList(head);
	
	return 0;
} 
