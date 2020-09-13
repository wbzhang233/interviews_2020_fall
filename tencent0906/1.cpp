//
// Created by wbzhang on 2020/9/6.
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;

	ListNode() : val(0), next(nullptr) {}

	ListNode(int _val) : val(_val), next(nullptr) {}

	ListNode(int _val, ListNode *_next) : val(_val), next(_next) {}
};

int main() {
	int val;

	int n;
	ListNode *head1 = new ListNode();
	ListNode *curr = head1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> val;
		ListNode *tmp = new ListNode(val);
		curr->next = tmp;
		curr = curr->next;
	}
	head1 = head1->next;

	int m;
	ListNode *head2 = new ListNode(0);
	curr = head2;
	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> val;
		ListNode *tmp = new ListNode(val);
		curr->next = tmp;
		curr = curr->next;
	}
	head2 = head2->next;

	// 如果相等，则加入结果；否则，数值大的向后移动
	ListNode *p1 = head1, *p2 = head2;
	while (p1 != nullptr && p2 != nullptr) {
		if (p1->val == p2->val) {
			cout << p1->val << " ";
			p1 = p1->next;
			p2 = p2->next;
		} else if (p1->val > p2->val) {
			p1 = p1->next;
		} else {
			p2 = p2->next;
		}
	}


	// 输出
//	cout << "h" << endl;

}