//
// Created by wbzhang on 2020/9/12.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void mShuffle(vector<int> &nums){
	int n = nums.size();
	// N/2为后半部分第一张
//	for(int i=0;i<n/2;i++){
//		int tmp = nums[i];
//
//	}

	vector<int> fpart(nums.begin(),nums.begin()+n/2);
	vector<int> lpart(nums.begin()+n/2,nums.end() );

	for(int i=0;i<n/2 ;i++){
		nums[2*i] = lpart[i];
		nums[2*i+1] = fpart[i];
	}

}

int main()
{
	int N,M;
	cin >> N>>M;
	vector<int> nums;
	int x;
	for(int i=0;i<N;i++){
		scanf("%d",&x);
		nums.push_back(x);
	}

	//
	while(M>0){
		mShuffle(nums);
		M--;
	}
	for(auto ele:nums){
		cout<<ele<<" ";
	}

	return 0;
}