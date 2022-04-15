#include<iostream>

using namespace std;

/*
��Ŀһ�� 
��ʱ�临�Ӷ�O(1)��ɾ������ڵ� 
*/ 
struct ListNode{
	int val;
	ListNode *next;
	
};

void PrintList(ListNode* head) {	
	ListNode* p = head->next;
	cout<<"����Ϊ"; 
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
	cout<<"������Ҫ¼�������0����"<<endl;
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
/* ���ֱ�Ӹ���һ����������Ҫɾ���Ľڵ㣬���ǿ������׵ĵõ���next�ڵ㡣����Ҫɾ���ýڵ�Ļ���
�Ϳ���ֱ�Ӱ���next�ڵ��ֵ������ɾ���Ľڵ㣬Ȼ�����next�ڵ�ɾ�����Ӷ�ʵ��͵��������

Ȼ��������Ҫ����ȫ�棬1.�ýڵ㲻��β�ڵ㣻2.����ͷ�ڵ�����β�ڵ�; 3.��β�ڵ㣬������ڵ㲻ֹһ���� 
 */ 
void DeleteNode(ListNode **pHead, ListNode *pToDelete) {
	if (!pHead || !pToDelete) return;
	if (pToDelete->next!=nullptr) {
		ListNode* pNext = pToDelete->next;
		cout<<"ɾ���ڵ���"<<pToDelete->val<<endl; 
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
��Ŀ���� 
ɾ���������ظ��ڵ㣺 
����pPreNode����λɾ���ڵ㿪ʼ��ǰһ���ڵ㣬����ɾ���ڵ�����ߵĽڵ������ӡ� 
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
	//�������� 
	ListNode *head = CreatListTail(); //�����ͷָ���ǿսڵ� 
	PrintList(head);
	
	//ɾ��ָ���ڵ� 
	ListNode *ToDelete = head->next->next;
	ListNode **pHead = new ListNode*();//(ListNode**)malloc(sizeof(ListNode));
	*pHead = head->next;
	
	
	DeleteNode(pHead, ToDelete);
	PrintList(head);
	//ɾ���ظ��ڵ� 
	DeleteDuplication(pHead);
	PrintList(head);
	
	return 0;
} 
