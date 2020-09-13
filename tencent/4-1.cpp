//
// Created by wbzhang on 2020/8/23.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

void getLongestSer(vector<int> nums,int &ans)
{
	// 动态规划
	int n=nums.size();
	vector<int> dpU(n,1),dpD(n,1);
	int maxU = dpU[0],maxD=dpD[0];

	// 递增
	for(int i=1;i<n;i++){
		if(nums[i] <=nums[i-1]){
			dpU[i] = dpU[i-1];
		}else{
			dpU[i] = dpU[i-1]+1;
		}
		maxU = max(maxU,dpU[i]);
	}

	// 递减
	for(int i = 0;i<n;i++){
		if(nums[i] <=nums[i-1]){
			dpD[i] = dpD[i+1]+1;
		}else dpD[i] = dpD[i-1];
		maxD = max(maxD,dpD[i]);
	}

//	for(int i=1;i<n;i++){
//		if(nums[i]>nums[i-1]){
//			dpD[i] = dpD[i-1];
//		}else dpD[i] = dpD[i-1]+1;
//		maxD = max(maxD,dpD[i]);
//	}

	ans = max(maxU,maxD);
}

int main()
{
	int T;
	cin>>T;
	while(T>0){
//		int n,x;
//		cin>>n;
//		vector<int> nums;
//		for(int i=0;i<n;i++){
//			cin>>x; nums.push_back(x);
//		}

		int n = 5;
		vector<int> nums = {1,2,4,5,3};

		int ans = 0;

		getLongestSer(nums,ans);
		cout<<ans<<endl;

		--T;
	}

	return 0;
}