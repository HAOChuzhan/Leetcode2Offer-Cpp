#include<iostream>

using namespace std;


struct ListNode {
	int val;
	ListNode* next;
};
//������ĩβ����ڵ� 
void AddtoTail(ListNode** phead, int value) {
	ListNode* pnew = nullptr;
	pnew->val = value;
	pnew->next = nullptr;
	
	if (*phead==nullptr) {
		*phead = pnew;
	}
	else {
		ListNode* pNode = *phead;
		while (pNode->next!=nullptr) {
			pNode = pNode->next;
		}
		pNode->next = pnew;
	}
}
//���������ҵ���һ������ĳֵ�ýڵ㲢ɾ���ýڵ�
void RemoveNode(ListNode** phead, int value) {
	if (*phead==nullptr || phead==nullptr) {
		return;
	}
	ListNode* ptoremove = nullptr;
	if ((*phead->value)==value) {
		ptoremove = *phead;
		*phead = *phead->next;	
	}
	else {
		ListNode* pNode = *phead;
		while(pNode->next!=nullptr&&pNode->next->val != value) {
			pNode = pNode->next;
		}
		if (pNode->next!=nullptr&&pNode->next->val == value) {
			ptoremove = pNode->next;
			pNode->next = pNode->next->next;
		}
	}
	if (ptoremove!=nullptr) {
		delete ptoremove;
		ptoremove = nullptr;
	}
} 
int mian() {
	
	return 0;
} 
