#include<iostream>

using namespace std;
typedef long long ll;
/*
突然遇到一个简单的问题，以下还有阶乘的实现方法。 
面试23：找到链表环中的入口节点 
*/
struct ListNode{
	int val;
	ListNode *next; 
}; 

//法1：阶乘的递归实现 
ll Stage(int n) {

	if (n<0) return -9999;
 	if (n==1||n==0) return 1;
	
	return n*Stage(n-1);
	
}
//法2：阶乘的循环实现
long long Stage_R(int n) {
	
	if (n<0) return -9999;
 	if (n==1||n==0) return 1;
 	
	long long res = 1;
 	
 	for (int i=2; i<=n; i++) {
 		res *= i;
	}
	return res;
} 
//先判断链表是否存在环，也可以使用快慢指针来进行。如果快指针追上了慢指针那么就存在环，如果快指针到了末尾都没有遇到慢指针，那么就不存在环。

/*先判断是否有环,如果没有环的话是返回nullptr，有环的情况下我们会得到环中的一个随机节点，方便下边函数找到环中节点数目*/
ListNode* MeetingNode(ListNode* head) {
	if (head==nullptr) return nullptr;
	ListNode* slow = head->next;
	if (slow==nullptr) return nullptr;
	ListNode* fast = slow->next;
	while(slow!=nullptr&&fast!=nullptr) {
		if (slow==fast)
			return fast;
		slow = slow->next;
		fast = fast->next;
		if (fast!=nullptr) fast = fast->next;
	} 
	return nullptr;
} 
/*找出链表中环环的节点数目,进而找出环的入口节点(就是环的初始节点前一个节点)*/
ListNode* EntryNodeOfLoop(ListNode* head) {
	ListNode* MeetingNode = MeetingNode(head);
	if (MeetingNode==nullptr) return nullptr;
	
	//然后开始计算环中节点数
	int nodesInLoop = 1;
	ListNode* pmeeting = MeetingNode;
	while (pmeeting->next!=MeetingNode) {
		pmeeting = pmeeting->next;
		++nodesInLoop;
	}
	pmeeting = head;
	while (nodesInLoop--) {
		pmeeting = pmeeting->next;
	}
	/*再同时移动这两个指针，他们就会在入口节点中相遇*/
	ListNode* phead = head;
	while (phead!=pmeeting) {
		phead = phead->next;
		pmeeting = pmeeting->next;
	}
	return pmeeting;
	
} 

int main() {
	long k = 20;
	cout<<Stage(k)<<endl;
	cout<<Stage_R(k)<<endl;
	
	return 0;
} 
