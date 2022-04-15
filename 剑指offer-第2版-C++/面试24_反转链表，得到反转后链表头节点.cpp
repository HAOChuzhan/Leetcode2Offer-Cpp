#include<iostream>

using namespace std;

/*����24����ת����*/
struct ListNode{
	int val;
	ListNode* next;
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
//ͷ�巨�������� (�ٴθ�ϰһ��)
ListNode* CreateList() {
	ListNode* head,*p;
	head = (ListNode*)malloc(sizeof(ListNode));
	if (head==nullptr) return head;
	
	head->next = NULL;
	int x;
	cout<<"�������������Ľڵ����֣���0������"<<endl;
	cin>>x;
	while(x) {
		p = (ListNode*)malloc(sizeof(ListNode));
		if (p==nullptr) return p;
		p->val = x;
		/*�ص�ط����Ȱѽڵ���룬����ͷ�ڵ��next���ڸýڵ�*/ 
		p->next = head->next;
		head->next = p;
		
		cin>>x;
	}
	return head;
}
/*
ע�����������
1.�����ͷ�ڵ�Ϊ��
2.���������ֻ��һ���ڵ�
3.����������ж���ڵ� 
*/
ListNode* ReverseList(ListNode* head) {
	ListNode* ReverseHead = nullptr;
	ListNode* Node = head;
	ListNode* PreN = nullptr;
	while (Node!=nullptr) {
		ListNode* pnext = Node->next;
		if (pnext==nullptr) ReverseHead = Node;
		Node->next = PreN;
		
		PreN = Node;
		Node = pnext;
	
	}
	return ReverseHead;
}

int main() {
	ListNode* head = CreateList();
	cout<<"�����ͷ�ڵ��ǣ�"<<head->next->val<<endl;
	PrintList(head);
	
	ListNode*newHead = ReverseList(head->next);
	cout<<"�����ͷ�ڵ��ǣ�"<<newHead->val<<endl;
	cout<<"��ת��������ǣ�"; 
	ListNode* phead = newHead;
	while (phead!=nullptr) {
		cout<<phead->val<<"->";
		phead = phead->next;
	} 
	cout<<"NULL"<<endl;
	return 0;
} 
