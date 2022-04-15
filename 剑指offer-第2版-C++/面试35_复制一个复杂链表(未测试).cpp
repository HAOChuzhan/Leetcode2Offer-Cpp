#include<iostream>

using namespace std;
/*
����35 - ��������ĸ���
�����ߣ�
	��һ��������ԭʼ��������нڵ㣬�����ӵ�ԭʼ�ڵ�ĺ�ߣ�
	�ڶ�����������siblingָ�룬��Ӧ�ĸ��ƽڵ��໥���ӣ�
	���������������������ֳ��������� 
*/
struct ListNode{
	int val;
	ListNode* next;
	ListNode* sibling;
};

//class ListNode {
//public:
//	int val;
//	ListNode* next;
//	ListNode(int x): val(x), next(nullptr) {}
//};

//����ԭ����Ľڵ� 
void CloneList(ListNode* head) {
	ListNode* pNode = head;
	while (pNode!=nullptr) {
		ListNode* pClone = new ListNode();
		pClone->val = pNode->val;
		pClone->next = pNode->next;
		pClone->sibling = nullptr;
		
		pNode->next = pClone;
		pNode = pClone->next;
	}
} 
//�����ƵĽڵ��siblingָ��Ҳ��Ӧ��ֵ 
void Clonesibling(ListNode* head) {
	ListNode *pNode = head;
	while (pNode!=nullptr) {
		ListNode* pClone = pNode->next;
		if (pNode->sibling!=nullptr) {
			pClone->sibling = pNode->sibling->next;
		}
		pNode = pClone->next;
	}
} 

//�����Ƶĳ������ 
ListNode* ReconnectNode(ListNode* head) {
	ListNode* pNode = head;
	ListNode* pClone = nullptr;
	ListNode* pCloneNode = nullptr;
	
	if (pNode!=nullptr) {
		pClone = pNode->next;
		pCloneNode = pNode->next;
		pNode->next = pCloneNode->next;
		
		pNode = pNode->next; 
	}
	while (pNode!=nullptr) {
		pCloneNode->next = pNode->next;
		pCloneNode = pCloneNode->next;
		pNode->next = pCloneNode->next;
		pNode = pNode->next; 
	}
	return pClone;
}
//���ϱߵ�������������� 
ListNode* Clone(ListNode* head) {
	CloneList(head);
	Clonesibling(head);
	return ReconnectNode(head);
}

int main () {
//	ListNode* head = new ListNode(3);
//	head->next = new ListNode(2);
	int arr[5] = {1,2,3,4,5};
	cout<<*arr<<endl;
	cout<<&arr+1<<endl;
	cout<<*(*(&arr+1)-1)<<endl;
	
	
	
	return 0;
} 
