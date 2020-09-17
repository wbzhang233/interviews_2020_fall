//
// Created by wbzhang on 2020/9/12.
//

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <memory.h>

using namespace std;



class Trie {
private:
	bool isEnd; // 是否为最后一个字母
	Trie *next[26]; // 字母表

public:
	/** Initialize your data structure here. */
	Trie() {
		isEnd = false;
		memset(next, 0, sizeof(next));
	}

	void insert(string key) {
		Trie *node = this;
		for (char ch : key) {
			if (node->next[ch - 'a'] == NULL) {
				node->next[ch - 'a'] = new Trie();
			}
			node = node->next[ch - 'a'];
		}
		node->isEnd = true;
	}

	bool search(string word) {
		Trie *node = this;
		for (char ch:word) {
			if (node->next[ch - 'a'] == NULL) {
				return false;
			} else {
				node = node->next[ch - 'a'];
			}
		}
		return node->isEnd;
	}

	bool prefix(string pref) {
		Trie *node = this;
		for (char ch:pref) {
			if (node->next[ch - 'a'] == NULL) {
				return false;
			} else {
				node = node->next[ch - 'a'];
			}
		}
		return true;
	}

	int longestPrefix(string pref) {
		Trie *node = this;
		int res = 0;
		for (char ch:pref) {
			if (node->next[ch - 'a'] == NULL) {
				return res;
			} else {
				node = node->next[ch - 'a'];
				res += 1;
			}
		}
		return res;
	}


};

// 使用栈，即考虑出栈序列问题
// 使用前缀树
bool rightStackSeries(string s1, string s2, string s3, int K) {
	if (s1.size() + s2.size() != s3.size()) return false;

	int i = 0;
	int n = s3.size();

	while (!s3.empty() && K > 0) {
		if(s3.empty() ) return true;
		Trie *trie1 = new Trie();
		trie1->insert(s3);

		// 查找最长公共前缀，入栈；算做一次操作
		int l1 = trie1->longestPrefix(s1);
		int l2 = trie1->longestPrefix(s2);

		// 截取，再查找
		if (l1 > l2) {
			// 截取s1
			s1 = string(s1.begin() + l1, s1.end());
			s3 = string(s3.begin() + l1, s3.end());
			i += l1;
		} else if(l2>=l1 && l2!=0) {
			s2 = string(s2.begin() + l2, s2.end());
			s3 = string(s3.begin() + l2, s3.end());
			i += l2;
		}else if(l1 ==0 && l2==0){
			return false;
		}

		K--;
		if(K<0){
			return false;
		}
		if(i>=n) return true;

	}
	if(K<0){
		return false;
	}
	return true;
}

int main() {
	int T, K;
	cin >> T;

	string s1, s2, s3;
	while (T > 0) {
		cin >> s1 >> s2 >> s3;
		cin >> K;
		// 输出

		cout << rightStackSeries(s1, s2, s3, K) << endl;
		--T;
	}


	return 0;
}