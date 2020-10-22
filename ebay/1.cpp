//
// Created by wbzhang on 2020/9/24.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	long N;
	cin>>N;

	if(N>1){
		vector<long> dp(N+1,0); //第N个格子的跳法，dp(1)=1,dp(2)=1
		dp[1] =1;
		dp[2] = 1;
		for(int n=3;n<=N;++n){
			int k = 0;
			while(n-int(pow(2,k)) >=1 ){
				dp[n] += dp[n-int(pow(2,k)) ];
				k++;
			}
		}
		cout<<dp[N]<<endl;
	}else{
		cout<<N <<endl;
	}

	return 0;
}