//
// Created by wbzhang on 2020/9/6.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<string, int> strint;

// 字符串比较
bool cmp(const strint &strint1, const strint &strint2) {
	return strint1.second < strint2.second;
}

int main() {
	int N, K;
	cin >> N >> K;

	vector<string> strs;
	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		strs.push_back(str);
	}

//	vector<string> strs = {"abc", "bfd", "abcde", "bdc", "bfd", "abcde", "bfd"};
//	int K = 2;

	sort(strs.begin(), strs.end());
	map<string, int> mp;
	for (auto st:strs) {
		mp[st]++;
	}
	vector<strint> vec(mp.begin(), mp.end());

	sort(vec.begin(), vec.end(), cmp);

	// 输出前K多
	int i = vec.size() - 1;
	int j = 0, ind = i;
	while (j < K) {
		while (i >= 1 && vec[i].second == vec[i - 1].second) {
			i--;
		}
		cout << vec[i].first << " " << vec[i].second << endl;
		j++;
		i--;
	}


	// 输出前K少
	for (int i = 0; i < K; i++) {
		cout << vec[i].first << " " << vec[i].second << endl;
	}

}