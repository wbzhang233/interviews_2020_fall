//
// Created by wbzhang on 2020/9/3.
//

#include <iostream>
#include <vector>

using namespace std;

int n;
int minCost = INT_MAX;
void backTrack(	vector<vector<int> > &board,int cost,int i,int j){
	if(i>=n || j>=n || i<0 || j<0) return;
	else if(i==n-1 && j==n-1){
		minCost = min(minCost,cost);
		return;
	}

	// 做选择
	backTrack(board, cost+abs(board[i][j-1]-board[i][j]) ,i,j-1); //左
	backTrack(board, cost+abs(board[i][j+1]-board[i][j]),i,j+1); //右
	backTrack(board, cost+abs(board[i-1][j]-board[i][j]) ,i-1,j); //上
	backTrack(board, cost+abs(board[i+1][j]-board[i][j]) ,i+1,j); //下
}

int main()
{
	int N;
	cin>>N;
	vector<vector<int> > board;
	n = N;

	for(int i=0;i<N;i++){
		vector<int> vec;
		int x;
		for(int j=0;j<N;j++){
			cin>>x;
			vec.push_back(x);
		}
		board.push_back(vec);
	}

	// 动态规划 dp为走到第i，j个格子的最小计分
	vector<vector<int> > dp(N,vector<int>(N,0));
	// base case
	dp[0][0] = 0;

	// 无后效性
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(i==0 &&j==0){
				continue;
			}else if(i==0 && j>0){
				dp[i][j] = dp[i][j-1]+abs(board[i][j]-board[i][j-1]);
			}else if(i>0 && j==0){
				dp[i][j] = dp[i-1][j]+abs(board[i][j]-board[i-1][j]);
			}else{
				dp[i][j] = min(dp[i-1][j]+abs(board[i][j] - board[i-1][j]),dp[i][j-1]+abs(board[i][j]-board[i][j-1]) );
			}
		}
	}
	cout<<dp[N-1][N-1]<<endl;

//	// 回溯法
//	backTrack(board,0,0,0);
//	cout<<minCost<<endl;

	return 0;
}