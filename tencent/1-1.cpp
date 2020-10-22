// 最小堆
// Created by wbzhang on 2020/8/23.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int getMinCost(vector<int> nums)
{
	priority_queue<int,vector<int>, greater<int> > pq;
	for(auto ele:nums) pq.push(ele);
	int ans = 0;
	// 每次选择最小的两个进行合并 (选择差最小的两个进行合并才对)
	while(pq.size()>=2){
		int f1 = pq.top();pq.pop();
		int f2 = pq.top();pq.pop();

		ans += f1+f2;
		pq.push(f1+f2);
	}

	return ans;
}

int main()
{
	int T;
	cin>>T;

	while(T>0){
		int n,x;
		cin>>n;
		vector<int> nums(0);
		for(int i=0;i<n;i++){
			cin>>x; nums.push_back(x);
		}

		// 算法
		int ans = getMinCost(nums);

		// 输出
		cout<<ans<<endl;
		T--;
	}
	return 0;
}
