//
// Created by wbzhang on 2020/9/21.
//
#include <iostream>
#include <vector>
using namespace std;


void getVec(int n,vector<int> &nums)
{
	nums.clear();
	while(n!=0){
		nums.push_back(n%10);
		n /= 10;
	}

}

int main()
{
	int x = 123456;
	vector<int> nums;
	getVec(x,nums);
	for(auto ele:nums)
		cout<<ele<<" ";

	return 0;
}