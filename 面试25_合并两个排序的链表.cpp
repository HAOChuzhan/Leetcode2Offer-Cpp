#include<iostream>

using namespace std;

/*面试25 —合并两个增序的链表，最终的链表也是增序的*/
typedef int ElemType;

struct ListNode{
	int val;
	ListNode* next;
}; 
void PrintList(ListNode* phead) {
	ListNode* head = phead->next; 
	cout<<"链表为：";
	while (head) {
		cout<<head->val<<"->";
		head = head->next;
	}
	cout<<"NULL"<<endl;
}
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
	/*注意这里尾插法建立的链表，头节点是空指针*/
	ListNode* head1 = Creat_LinkList_R(); 
	ListNode* head2 = Creat_LinkList_R();	
	PrintList(head1);
	PrintList(head2);
	ListNode* head3 = MergeTwoList(head1->next, head2->next);
	
	/*打印出两个合并的链表*/
	cout<<"合并后的链表是："; 
	ListNode* phead = head3;
	while (phead!=nullptr) {
		cout<<phead->val<<"->";
		phead = phead->next;
	} 
	cout<<"NULL"<<endl;
	
	return 0;
}
