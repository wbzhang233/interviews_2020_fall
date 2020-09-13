//
// Created by wbzhang on 2020/9/1.
//

#include <iostream>
#include <vector>

using namespace std;

int longestCommonSubsequence(string text1, string text2, string &lcs)
{
	int m = text1.size(), n = text2.size();
	vector<vector<int> > dp(m + 1, vector<int>(n + 1,0));

	for (int i = 1; i < m + 1; i++)
	{
		bool flag = false;
		for (int j = 1; j < n + 1; j++)
		{
			if (text1[i-1] == text2[j-1])
			{
				dp[i][j] = 1 + dp[i - 1][j - 1];
				if(!flag) lcs.push_back(text1[i-1]);
				flag = true;
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
//	int n,m;
//	cin>>n>>m;
//	string s,t;
//	cin>>s;
//	cin>>t;

	int n = 4,m=5;
	string s = "accb";
	string t = "abcac";

	// 求lcs
	string lcs;
	int l1 = longestCommonSubsequence(s,t,lcs); //

	// 然后求lcs在S中的最长公共子串
	int maxLength = 0;
	for(int i=0;i<n;i++){
		//以i开头的最长公共子串的长度
		int cur = 0;
		int k= i,j=0;
		while(k<n && j<l1){
			if(s[k] == lcs[j]){
				cur++;
				k++;j++;
			}else{
				j++;
			}
		}
		maxLength = max(maxLength,cur);
	}


	cout<<maxLength*(maxLength+1)/2<<endl;

	return 0;
}