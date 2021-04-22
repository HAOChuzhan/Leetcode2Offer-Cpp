#include<iostream>

using namespace std;
typedef long long ll;
/*
ͻȻ����һ���򵥵����⣬���»��н׳˵�ʵ�ַ����� 
����23���ҵ������е���ڽڵ� 
*/
struct ListNode{
	int val;
	ListNode *next; 
}; 

//��1���׳˵ĵݹ�ʵ�� 
ll Stage(int n) {

	if (n<0) return -9999;
 	if (n==1||n==0) return 1;
	
	return n*Stage(n-1);
	
}
//��2���׳˵�ѭ��ʵ��
long long Stage_R(int n) {
	
	if (n<0) return -9999;
 	if (n==1||n==0) return 1;
 	
	long long res = 1;
 	
 	for (int i=2; i<=n; i++) {
 		res *= i;
	}
	return res;
} 
//���ж������Ƿ���ڻ���Ҳ����ʹ�ÿ���ָ�������С������ָ��׷������ָ����ô�ʹ��ڻ��������ָ�뵽��ĩβ��û��������ָ�룬��ô�Ͳ����ڻ���

/*���ж��Ƿ��л�,���û�л��Ļ��Ƿ���nullptr���л�����������ǻ�õ����е�һ������ڵ㣬�����±ߺ����ҵ����нڵ���Ŀ*/
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
/*�ҳ������л����Ľڵ���Ŀ,�����ҳ�������ڽڵ�(���ǻ��ĳ�ʼ�ڵ�ǰһ���ڵ�)*/
ListNode* EntryNodeOfLoop(ListNode* head) {
	ListNode* MeetingNode = MeetingNode(head);
	if (MeetingNode==nullptr) return nullptr;
	
	//Ȼ��ʼ���㻷�нڵ���
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
	/*��ͬʱ�ƶ�������ָ�룬���Ǿͻ�����ڽڵ�������*/
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
