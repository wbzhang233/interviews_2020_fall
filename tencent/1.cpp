//
// Created by wbzhang on 2020/8/23.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 寻找pq中差距最小的两个元素
void getTwo(priority_queue<int,vector<int>, greater<int> > &pq,int &a,int &b){
	// 全弹出
	vector<int> vec;
	while(!pq.empty()){
		vec.push_back(pq.top());
		pq.pop();
	}
	int mindiff = INT_MAX;
	int minInd = 0;
	for(int i=1;i<vec.size();i++){
		if(abs(vec[i]-vec[i-1])<mindiff ){
			mindiff = abs(vec[i]-vec[i-1]);
			minInd = i;
		}
	}
	a = vec[minInd];
	b = vec[minInd-1];

	for(int i=0;i<vec.size();i++){
		if(i!=minInd && i!=minInd-1){
			pq.push(vec[i]);
		}
	}

}


int getMinCost(vector<int> nums)
{
	priority_queue<int,vector<int>, greater<int> > pq;
	for(auto ele:nums) pq.push(ele);
	int ans = 0;
	// 每次选择最小的两个进行合并(选择差最小的两个进行合并才对)
	while(pq.size()>=2){
//		int f1 = pq.top();pq.pop();
//		int f2 = pq.top();pq.pop();

		int f1,f2;
		getTwo(pq,f1,f2);

		ans += f1+f2;
		pq.push(f1+f2);
	}

	return ans;
}

int main()
{
	int T;
//	cin>>T;
	T =1;

	while(T>0){
#if 0
		int n,x;
		cin>>n;
		vector<int> nums(0);
		for(int i=0;i<n;i++){
			cin>>x; nums.push_back(x);
		}
#elif 1
		int n = 4;
		vector<int> nums = {2,2,3,3};
#endif
		// 算法
		int ans;
		ans = getMinCost(nums);

		// 输出
		cout<<ans<<endl;
		T--;
	}



	return 0;
}
