//
// Created by wbzhang on 2020/10/18.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int getRes(vector<int> &nums) {
	int n = nums.size();
	if (n <= 2) return nums.back();
	sort(nums.begin(), nums.end());

	int res = 0;
	vector<int> dp(n,0);
	dp[0]= nums[0];
	dp[1] = nums[1];
	dp[2] = nums[0]+nums[1]+nums[2];

	for(int i=3;i<n;++i){
		dp[i] = min(dp[i-1]+nums[0]+nums[i],dp[i-2]+nums[i]+nums[0]+2*nums[1]);
	}
	return dp[n-1];

}

int main() {
	int N;
	cin >> N;
	vector<int> nums;
	int x;
	for (int i = 0; i < N; ++i) {
		scanf("%d", &x);
		nums.push_back(x);
	}

	cout << getRes(nums) << endl;
}