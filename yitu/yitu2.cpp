//
// Created by wbzhang on 2020/9/17.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// 动态规划
int getMinTimeByDP(vector<vector<char> > &mp,vector<int> &cost,int &x,int &y)
{
	int res = 0;



	return res;
}


int main()
{
	int T;
	cin >> T;
	static int n,m;
	static int x,y;
	vector<int> cost;
	//static int a,b,c,d;
	vector<vector<char> > mp;

	while(T>0){
		// 处理输入
		cin >> n >> m;
		cin >> x >> y;
		int c;
		for(int i=0;i<4;++i){
			cin >> c;
			cost.push_back(c);
		}
		//cin >> a >> b >> c >> d;
		mp.clear();
		for(int i=0;i<n;++i){
			vector<char> rVec;
			char ch;
			for(int j=0;j<m;++j){
				//scanf("%c",&ch);
				cin >> ch;
				rVec.push_back(ch);
			}
			mp.push_back(rVec);
		}

		// 输出结果
		cout<< getMinTimeByDP() <<endl;
		// 循环
		--T;
	};

	return 0;
}