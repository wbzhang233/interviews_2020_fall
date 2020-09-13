//
// Created by wbzhang on 2020/8/13.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// 贪心算法，排序即可



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

	// 尽可能选择奖励大，耗时小
	sort(pots.begin(),pots.end(),[](vector<int> vec1,vector<int> vec2){return vec1[1]*vec2[0]>vec1[0]*vec2[1]; });

	int k= 0;
	while(m>0 && k<pots.size()){
		ans += pots[k][1];
		m -= pots[k][0];
	}

	// 0-1背包问题



	cout << ans << endl;
	return 0;
}