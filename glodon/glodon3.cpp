//
// Created by wbzhang on 2020/9/9.
//

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

bool isNonDup(unordered_map<int,int> hist)
{
	for(auto ele:hist){
		if(ele.second > 1) return false;
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	vector<int> nums;
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		nums.push_back(num);
	}

	// 最小堆排序
	priority_queue<int,vector<int>,greater<int> > pq; // 小顶堆
	unordered_map<int,int> hist;
	for(auto ele:nums){
		pq.push(ele);
		hist[ele]++;
	}


	while( !isNonDup(hist) ){

		int x = pq.top();
		pq.pop();
		hist[x]--;

		pq.push(2*x);
		hist[2*x]++;
	}

	while(!pq.empty() ){
		cout<<pq.top()<<" ";
		pq.pop();
	}


	return 0;
}

//5
//5 5 5 5 4