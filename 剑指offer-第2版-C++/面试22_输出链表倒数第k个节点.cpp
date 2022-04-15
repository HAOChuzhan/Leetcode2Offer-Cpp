#include<iostream>
using namespace std;


/*
面试22：链表中倒数第k个节点：
首先我们立马可以想到双指针的思路，让第一个指针先移动k-1个位置再让两个指针同时移动，当第一个指针移到末尾时，则第二个指针指向倒数第k个节点。 
*/ 
struct ListNode{
	int val;
	ListNode *next; 
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
ListNode* CreateList_R() {
	int x;
	ListNode *head, *p, *tail;
	head = (ListNode*)malloc(sizeof(ListNode));
	if (head==nullptr) return head;
	head->next = NULL;
	tail = head;
	cout<<"请输入您所需要建立链表的数，以0结尾："<<endl;
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

/*需要注意几点：
 1.当传入的头指针为空时，或者k值不符合规范则跳出。
 2.当k值大于链表的长度，需要判断不符合条件跳出。 
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
	/*===================头插法创建链表====================*/
	ListNode* phead = CreateList_R(); 
	cout<<"头节点是："<<phead->next->val<<endl;
	PrintList(phead);
	int k = 2;
	cout<<"倒数第"<<k<<"个节点是："<<PrintNodek_R(phead->next, k)<<endl;
	return 0;
} 

/*
举一反三：
假设我们需要求解链表中间的节点的时候，我们同样可以使用快慢指针，一个指针走一步，另外一个指针走两步，
针对总节点数为奇数的那么慢指针恰好走到中间节点。
针对偶数节点的链表=====>那得到中间两个节点。 
*/
