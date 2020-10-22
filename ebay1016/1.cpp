//
// Created by wbzhang on 2020/10/16.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;

	int a,b,c;
	//map<int,int> ump;
	vector<vector<int> > op;
	int l = INT_MAX;
	int h = INT_MIN;

	while(m>0){
		cin>>a>>b>>c;
		op.push_back({a,b,c});
		l = min(l,a);
		h = max(h,b);

		--m;
	}

	// 将[1,n]对应于[l,h],h-n+1==n
	vector<int> vec(n+1,0);
	for(auto pp:op){
		for(int i=pp[0];i<=pp[1];++i){
			vec[i-l+1]+=pp[2];
		}
	}

	for(int i=1;i<vec.size();++i){
		cout<<vec[i]<<" ";
	}

	/*for(auto ele:ump){
		cout<<ele.second<<" ";
	}*/

}

//5 2
//1 3 1
//2 5 2