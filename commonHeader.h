//
// Created by wbzhang on 2020/8/6.
//

#ifndef INTERVIEWS_COMMONHEADER_H
#define INTERVIEWS_COMMONHEADER_H

#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <array>
#include <forward_list>

#include <algorithm>
#include <numeric>
#include <cctype>
#include <cstdio>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode ():val(0), next(nullptr){}
    ListNode (int _val):val(_val), next(nullptr){}
    ListNode (int _val,ListNode* _next):val(_val), next(_next){}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


#endif //INTERVIEWS_COMMONHEADER_H
