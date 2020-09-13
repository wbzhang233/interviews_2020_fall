//
// Created by wbzhang on 2020/9/1.
//

//
// Created by wbzhang on 2020/9/1.
//

#include <iostream>
#include <vector>

using namespace std;

int longestCommonSubsequence(string text1, string text2)
{
	int m = text1.size(), n = text2.size();
	// int dp[m+1][n+1];
	vector<vector<int> > dp(m + 1, vector<int>(n + 1));
	for (int i = 1; i < m + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (text1[i] == text2[j])
			{
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}
	return dp[m][n];
}


int main()
{
	int n,m;
	cin>>n>>m;
	string s,t;
	cin>>s;
	cin>>t;

	int ans = 0;

	int lng = min(n,m);
//	vector<vector<int> > dp(n+1,vector<int>(m+1,0));
//	// 求lcs,
//
//	for(int i=1;i<n;i++){
//		for(int j=1;j<m;j++){
//			if(s[i]==t[i]){
//				dp[i][j] = dp[i-1][j-1]+1;
//			}else{
//				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
//			}
//		}
//	}
//	// 然后求lcs在S中的最长子串


	int lcs = longestCommonSubsequence(s,t);

	// 结果为lcs的长度的排列
//	ans = dp[n][m]*(dp[n][m]-1)/2;

	cout<<lcs*(lcs-1)<<endl;

	return 0;
}