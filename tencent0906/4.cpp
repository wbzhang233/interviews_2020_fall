//
// Created by wbzhang on 2020/9/6.
//

// 贪心算法
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> nums;
	int x;
	for (int i = 0; i < n; i++) {
		// scanf("%d", x);
		cin>>x;
		nums.push_back(x);
	}

	int m;
	cin >> m;

	sort(nums.begin(), nums.end());
//	auto fb = find(nums.begin(),nums.end(),m);
//	auto ub = upper_bound(nums.begin(),nums.end(),m);
	auto lb = lower_bound(nums.begin(),nums.end(),m);

	if(lb!=nums.end() ) cout<<nums.back()<<endl;
	else{
		int sum = 0, i = 0;
		int mm = m;
		while (mm > 0 && i<nums.size() ) {
			sum += nums[i];
			mm -= nums[i];
			i++;
		}
		// 如果所有和小于m,即i==终点，则输出sum；否则，应当不听最后一曲，而听最长的一曲
		if(i<nums.size())
		{
			sum = 0,i = nums.size()-1;
			while (m > 0 && i>=0 ) {
				sum += nums[i];
				m -= nums[i];
				i--;
			}
		}
		// sum += nums.back()- nums[i-1];

		cout << sum << endl;
	}

}