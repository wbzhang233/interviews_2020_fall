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
	sort(nums.begin(), nums.end());
	if (n <= 2) return nums.back();
	if(n==3) return accumulate(nums.begin(),nums.end(),0);

	int res =0;
	if(nums[n-1]+nums[0]<=2*nums[1]){
		res = nums[n-1]+nums[n-2]+2*nums[0];
	}else{
		res = nums[n-1]+nums[0]+2*nums[1];
	}
	return  res;
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