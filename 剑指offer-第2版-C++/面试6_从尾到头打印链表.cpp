#include<iostream>
#include<bits/stdc++.h> //����ͷ�ļ� 
#include<stack>
using namespace std;

typedef int ElemType;

struct ListNode{
	int val;
	ListNode* next;
}; 
//β�巨����������
ListNode * Creat_LinkList_R()
{
    ElemType x;
    ListNode *head,*p,*tail;//tail��βָ��
    head = (ListNode*)malloc(sizeof(ListNode));
    if(head == NULL)
        return head;
    head -> next = NULL;
    tail = head; //һ��ʼβָ��ָ��ͷָ���λ��
    cout<<"������Ҫ¼�������0����"<<endl;
    cin >> x;
    while(x != 0)
    {
        p = (ListNode*) malloc(sizeof(ListNode));
        if(p == NULL)
            return head;
        p -> val = x;
        tail -> next = p; //��p���뵽β�ڵ�ĺ���
        tail = p;   //�޸�β�ڵ��ָ��
        tail -> next = NULL;    //��β�ڵ��ָ�����޸�Ϊ��
        cin >> x;
    }
    return head;
 
}


ListNode *Creat_LinkList()
{
    int x;
    ListNode *head,*p;
    head = (ListNode*)malloc(sizeof(ListNode));
    if(head == NULL)
        return head;
    head -> next = NULL;
    cout<<"������Ҫ¼�������0����"<<endl;
    cin >> x;
    while(x != 0)
    {
        p = (ListNode*) malloc(sizeof(ListNode));
        if(p == NULL)
            return head;
        p -> val = x;
        p -> next = head -> next;
        head -> next = p;
        cin >> x;
     }
     return head;
}
void PrintListReverse(ListNode* phead) {
	stack<ListNode*> nodes;
	ListNode* pNode = phead;
	while (pNode!=nullptr) {
		nodes.push(pNode);
		pNode = pNode->next;
	}
	while(!nodes.empty()) {
		pNode = nodes.top();
		cout<<pNode->val<<endl;
		nodes.pop();
	}
} 
void PrintListReverse_recursively(ListNode* pHead) {
	if (pHead!=nullptr) {
		if (pHead->next != nullptr) {
			PrintListReverse_recursively(pHead->next);
		}
		cout<<pHead->val<<endl; 
	}  
	
}

int main() {
	
	ListNode* phead = Creat_LinkList_R(); 
	
	cout<<"ͷ�ڵ��ǣ�"<<phead->next->val<<endl;
	PrintListReverse_recursively(phead->next);
	return 0;
} 
