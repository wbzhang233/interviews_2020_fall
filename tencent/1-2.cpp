//
// Created by wbzhang on 2020/9/20.
//

#include<iostream>      //区间动态规划
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int main()
{
	int N;
	cin>>N;
	vector<int> c(N);
	vector<vector<int>> f(N,vector<int>(N,INT_MAX));    //存放结果，f[i][j]表示从下标i堆到下标j堆的最小成本
	vector<int> sum(N);                                 //存放当前金币和，用于bp计算
	for(int i=0;i<N;i++)
	{
		cin>>c[i];
		f[i][i]=0;                    //对角线初始化为0，其余为INT_MAX
		if(i==0)
			sum[i]=c[i];
		else sum[i] = sum[i - 1]+c[i];
	}
	for(int len=1;len<=N;len++)     //枚举长度，长度为1表示本身
	{
		for(int j=0;j+len<N+1;j++)          //枚举起点
		{
			int end=j+len-1;               //计算终点
			for(int i=j;i<end;i++)            //枚举分割点
				f[j][end]=min(f[j][end],f[j][i]+f[i+1][end]+sum[end]-sum[j]+c[j]);
		}
	}
	cout<<f[0][N-1]<<endl;
	return 0;
}