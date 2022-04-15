#include<iostream>
#include<bits/stdc++.h> //万能头文件 
#include<stack>
using namespace std;

typedef int ElemType;

struct ListNode{
	int val;
	ListNode* next;
}; 
//尾插法建立单链表
ListNode * Creat_LinkList_R()
{
    ElemType x;
    ListNode *head,*p,*tail;//tail是尾指针
    head = (ListNode*)malloc(sizeof(ListNode));
    if(head == NULL)
        return head;
    head -> next = NULL;
    tail = head; //一开始尾指针指向头指针的位置
    cout<<"请输入要录入的数以0结束"<<endl;
    cin >> x;
    while(x != 0)
    {
        p = (ListNode*) malloc(sizeof(ListNode));
        if(p == NULL)
            return head;
        p -> val = x;
        tail -> next = p; //将p插入到尾节点的后面
        tail = p;   //修改尾节点的指向
        tail -> next = NULL;    //将尾节点的指针域修改为空
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
    cout<<"请输入要录入的数以0结束"<<endl;
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
	
	cout<<"头节点是："<<phead->next->val<<endl;
	PrintListReverse_recursively(phead->next);
	return 0;
} 
