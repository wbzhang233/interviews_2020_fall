//
// Created by wbzhang on 2020/9/20.
//

#include <iostream>
#include <vector>

using namespace std;


// 数字要在M和N之间，则 A>=M[0] && A<=N[0]
// A不能为0，其他的可以为0，并且全不相同...满足AB+CD=EF
int m,n;
void backTrack(int &ans,vector<int> &path,vector<bool> &vis,int fi)
{
	if(path.size()==6){
		if(path[0]*10 +path[1] +path[2]*10+path[3] == 10*path[4]+path[5]){
			ans++;
		}
		return;
	}

	// 选择列表
	for(int i=fi;i<10;++i){
		if(path.empty() && i==0){
			continue;
		}else if(!vis[i]){
			path.push_back(i);
			vis[i] = true;
			backTrack(ans,path,vis,fi+1);
			vis[i] = false;
			path.pop_back();
		}
	}

}

int main()
{
	int M,N;
	cin>>M >>N;
	m = M, n =N;

	string sm = to_string(M);
	string sn = to_string(N);

	int ans = 0;
	vector<int> path= {};
	vector<bool> vis(10,false);

	backTrack(ans,path,vis,0);
	cout<<ans<<endl;

	return 0;
}