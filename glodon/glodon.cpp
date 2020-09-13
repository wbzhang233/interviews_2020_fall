//
// Created by wbzhang on 2020/9/9.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Action {
	double c;
	int w;

	Action(double _c, int _w) : c(_c), w(_w) {};
};

void backTrack(int &sum, vector<Action> &acts, int &leftC, int &currSum, int first) {
	if (leftC < acts[first].c || first >= acts.size()) {
//	if (leftC <= 0 || first >= acts.size()) {
//		if (leftC < 0) currSum -= acts[first - 1].w;
		sum = max(sum, currSum);
		return;
	}

	// 做选择
	for (int i = first; i < acts.size(); ++i) {
		if (leftC >= acts[i].c) {
			leftC -= acts[i].c;
			currSum += acts[i].w;
			backTrack(sum, acts, leftC, currSum, first + 1); //做选择
			leftC += acts[i].c;
			currSum -= acts[i].w;
		}
	}

}

int main() {
	int n;
	int C;
	cin >> n >> C;
	double tmp1;
	int tmp2;
	vector<Action> acts;
	for (int i = 0; i < n; ++i) {
		cin >> tmp1;
		cin >> tmp2;
		acts.push_back(Action(tmp1, tmp2));
	}

	sort(acts.begin(), acts.end(), [](const Action &aAct, const Action &bAct) {
//		return aAct.c * bAct.w < aAct.w * bAct.c;
		return aAct.c < bAct.c;
	});

	// 1.回溯
	int sum = 0;
	int leftC = C;
	int currSum = 0;
	backTrack(sum, acts, leftC, currSum, 0);


//
//	// 贪心算法
//	int sum = 0;
//	for (int fi = 0; fi < acts.size(); ++fi) {
//		int i = fi;
//		int s = 0;
//		double cm = C;
//		while (cm > 0 && i < acts.size()) {
//			if (cm >= acts[i].c) {
//				cm -= acts[i].c;
//				s += acts[i].w;
//			}
//			i++;
//		}
//		sum = max(sum,s);
//	}

	cout << sum << endl;


	// 动态规划
//	vector<vector<int> > dp(n + 1, vector<int>(C + 1, 0));
//
//	for (int i = 1; i <= n; ++i) {
//		for (int j = 1; j <= C; ++j) {
//			if (j >= ceil(acts[i - 1].c)) {
//				dp[i][j] = max(dp[i][j], dp[i][j - ceil(acts[i - 1].c)] + acts[i - 1].w);
//			} else {
//				dp[i][j] = dp[i - 1][j];
//			}
//		}
//	}

//	cout << dp[n][C] << endl;

}