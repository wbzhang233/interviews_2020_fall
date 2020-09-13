//
// Created by wbzhang on 2020/9/3.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

struct thing {
	int price,weight,v;
	thing(int a,int b,int c):price(a),weight(b),v(c){};
	thing():price(0),weight(0),v(0){};

} items[N];

//struct Item {
//	int p, w, v;
//
//	bool operator< (const Item &item) const {
//		if (v != item.v) return v > item.v;
//		else if (p != item.p) return p < item.p;
//		else return w < item.w;
//	}
//} items[N];

int main()
{
	int n,m,k;
	cin>>n>>m>>k;

	vector<thing> things;
	int price,weight,v;
	for(int i=0;i<n;i++){
		cin>> price>>weight>>v;
		thing th(price,weight,v);
		things.push_back(th);
	}

	sort(things.begin(),things.end(),
	[](thing a,thing b){
		if(a.v>b.v) return true;
		else if(a.v==b.v && a.price <b.price) return true;
		return false;
	});

	// 背包问题 - 动态规划
	int dp[n][m][k] ;
	for(int kk=0; kk<n; kk++){
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < k; ++j) {
				dp[kk][i][j] = 0;
			}
		}
	}


	for(int i=0;i<n;i++){
		for(int j = m;j>things[i].weight;j--){
			for(int kk = k; kk>things[i].price;kk-- ){
				dp[i][j][kk] = max( dp[i][j][kk-things[i].price] +1,dp[i][j][kk] );
			}
		}
	}

	cout<<dp[n-1][m-1][k-1]<<endl;

//	cout<<2<<endl;

	return 0;
}


