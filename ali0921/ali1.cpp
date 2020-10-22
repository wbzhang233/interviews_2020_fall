//
// Created by wbzhang on 2020/9/21.
//

#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int _val):val(_val){
		this->next = NULL;
	};

};

// 递归打印链表
void printList(ListNode* head)
{
	if(head==NULL) return;
	cout<<head->val<<" ";
	printList(head->next);
}

// 合并
ListNode* merge(ListNode* headA,ListNode* headB)
{
	if(headA==NULL) return headB;
	if(headB==NULL) return headA;

	ListNode* res;
	// 比较大小
	if( headA->val < headB-> val){
		res = headA;
		res->next = merge(headA->next,headB);
	}else{
		res = headB;
		res->next = merge(headA,headB->next);
	}

	return res;
}

int main()
{
	ListNode* headA = new ListNode(1);
	// 构建链表A
	ListNode* curr = headA;
	for (int i = 2; i < 10; ++i) {
		if(i%2==0) continue;
		ListNode* newNode = new ListNode(i);
		curr->next = newNode;
		curr = curr->next;
	}
	cout<<"list A..."<<endl;
	printList(headA);

	// 构建链表B
	ListNode* headB = new ListNode(0);
	curr = headB;
	for (int i = 2; i < 10; ++i) {
		if(i%2==1) continue;
		ListNode* newNode = new ListNode(i);
		curr->next = newNode;
		curr = curr->next;
	}
	cout<<endl<<"list B..."<<endl;
	printList(headB);

	//
	ListNode* res = merge(headA,headB);

	cout<<endl<<"result:"<<endl;
	printList(res);


	return 0;
}