#include<iostream>
using namespace std;


/*
����22�������е�����k���ڵ㣺
����������������뵽˫ָ���˼·���õ�һ��ָ�����ƶ�k-1��λ����������ָ��ͬʱ�ƶ�������һ��ָ���Ƶ�ĩβʱ����ڶ���ָ��ָ������k���ڵ㡣 
*/ 
struct ListNode{
	int val;
	ListNode *next; 
}; 
void PrintList(ListNode* phead) {
	ListNode* head = phead->next; 
	cout<<"����Ϊ��";
	while (head) {
		cout<<head->val<<"->";
		head = head->next;
	}
	cout<<"NULL"<<endl;
}
ListNode* CreateList_R() {
	int x;
	ListNode *head, *p, *tail;
	head = (ListNode*)malloc(sizeof(ListNode));
	if (head==nullptr) return head;
	head->next = NULL;
	tail = head;
	cout<<"������������Ҫ���������������0��β��"<<endl;
	cin>>x;
	while(x) {
		p = (ListNode*)malloc(sizeof(ListNode));
		if (p==nullptr) return p;
		p->val = x;
		tail->next = p;
		tail = p;
		tail->next = NULL;
		cin>>x;
	}
	return head;
	
}

/*��Ҫע�⼸�㣺
 1.�������ͷָ��Ϊ��ʱ������kֵ�����Ϲ淶��������
 2.��kֵ��������ĳ��ȣ���Ҫ�жϲ��������������� 
 */ 
int PrintNodek_R(ListNode* head, int k) {
	if (head==nullptr || k<=0) return -9999;
	ListNode* p1 =head;
	ListNode* p2 =head;
	while(--k) {
		p2 = p2->next;
		if (p2==nullptr) return -9999; 
	}
	while (p2->next) {
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1->val;
} 

int main() {
	/*===================ͷ�巨��������====================*/
	ListNode* phead = CreateList_R(); 
	cout<<"ͷ�ڵ��ǣ�"<<phead->next->val<<endl;
	PrintList(phead);
	int k = 2;
	cout<<"������"<<k<<"���ڵ��ǣ�"<<PrintNodek_R(phead->next, k)<<endl;
	return 0;
} 

/*
��һ������
����������Ҫ��������м�Ľڵ��ʱ������ͬ������ʹ�ÿ���ָ�룬һ��ָ����һ��������һ��ָ����������
����ܽڵ���Ϊ��������ô��ָ��ǡ���ߵ��м�ڵ㡣
���ż���ڵ������=====>�ǵõ��м������ڵ㡣 
*/
