#include<iostream>

using namespace std;

/*����25 ���ϲ�����������������յ�����Ҳ�������*/
typedef int ElemType;

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

ListNode* MergeTwoList(ListNode* head1, ListNode* head2) {
	if (head1==nullptr) {
		return head2;
	} 
	else if (head2==nullptr) {
		return head1;
	}
	ListNode* MergeHead = nullptr;
	if (head1->val < head2->val) {
		MergeHead = head1;
		MergeHead->next = MergeTwoList(head1->next, head2);
	}
	else {
		MergeHead = head2;
		MergeHead->next = MergeTwoList(head1, head2->next);
	}
	return MergeHead;
} 

int main () {
	/*ע������β�巨����������ͷ�ڵ��ǿ�ָ��*/
	ListNode* head1 = Creat_LinkList_R(); 
	ListNode* head2 = Creat_LinkList_R();	
	PrintList(head1);
	PrintList(head2);
	ListNode* head3 = MergeTwoList(head1->next, head2->next);
	
	/*��ӡ�������ϲ�������*/
	cout<<"�ϲ���������ǣ�"; 
	ListNode* phead = head3;
	while (phead!=nullptr) {
		cout<<phead->val<<"->";
		phead = phead->next;
	} 
	cout<<"NULL"<<endl;
	
	return 0;
}
