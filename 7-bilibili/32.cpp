//
// Created by wbzhang on 2020/8/13.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n,m;
	int ans = 0;
	cin >> n>> m;
	vector<vector<int> > pots;
	int a,b;
	for(int i = 0; i < n; i++){
		cin>>a>>b;
		pots.push_back({a,b});
	}

//	n = 4;
//	m = 6;
//	vector<vector<int> > pots={
//		{2,4},{2,35},{1,43},{2,10}
//	};


	// 0-1背包问题
	vector<vector<int>> dp(n+1,vector<int>(m+1,0)); // dp[i][j]表示是否存放第i件物品时，容量为j的最优解
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= m; k++) {
			// 存放 i 号物品（前提是放得下这件物品），当前值等于 该物品奖励值加上 dp[i-1][k-重量]
			int withVi = (k-pots[i-1][0] >= 0) ? (pots[i-1][1]+dp[i-1][k-pots[i-1][0]]) : 0;
			// 不存放 i 号物品
			int withoutVi = dp[i - 1][k];
			dp[i][k] = max(withVi, withoutVi);
		}
	}

	cout << dp[n][m] << endl;
	return 0;
}