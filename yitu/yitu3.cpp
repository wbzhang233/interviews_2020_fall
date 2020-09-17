//
// Created by wbzhang on 2020/9/17.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int AtoB = 17;
const int BtoC = 29;

struct coins {
	int a, b, c, p;
	int cost; // 总消耗
	float rate; //性价比
	// 构造函数
	coins(int _a, int _b, int _c, int _p = 0) : a(_a), b(_b), c(_c), p(_p) {
		this->cost = a * AtoB * BtoC + b * BtoC + c;
		this->rate = float(p) / this->cost;  //性能提升除以价格
	};

	// 构造函数2
	coins(int _cost, int _p = 0) : cost(_cost), p(_p) {
		this->a = _cost / AtoB;
		_cost = _cost % AtoB;
		this->b = _cost / BtoC;
		_cost = _cost % BtoC;
		this->c = _cost;
		this->rate = float(p) / this->cost;
	}

	// 拷贝构造函数
	coins(const coins& coins1){
		this->a = coins1.a;
		this->b = coins1.b;
		this->c = coins1.c;
		this->p = coins1.p;
		this->cost = coins1.cost;
		this->rate = coins1.rate;
	}

	void clear() {
		this->a = this->b = this->c = this->p = this->cost = 0;
		this->rate = 0.0;
	}

	// 重载减法
	coins operator-(const coins &coinsK) {
		/*// 先用小的
		coins res(0,0,0,0);
		if(this->c >= coinsK.c){
			res.c = this->c - coinsK.c;
		}else if(){
			res.c = this->c +
		}*/
		// 总金币
		if (this->cost < coinsK.cost) {
			return coins(0, 0, 0, 0);
		}

		int cost = this->cost - coinsK.cost;
		return coins(cost, 0);
	}

	// 重载等于
	void operator=(coins coinsK) {
		this->a = coinsK.a;
		this->b = coinsK.b;
		this->c = coinsK.c;
		this->p = coinsK.p;
		this->cost = coinsK.cost;
		this->rate = coinsK.rate;
	}

	// 重载-=
	void operator-=(const coins &coinsK) {
		// 总金币
		if (this->cost < coinsK.cost) {
			this->clear();
		} else {
			int cost = this->cost - coinsK.cost;
			int p = 0;

			this->cost =cost;
			this->a = cost / (AtoB*BtoC);
			cost = cost % (AtoB*BtoC);
			this->b = cost / BtoC;
			cost = cost % BtoC;
			this->c = cost;
			this->rate = float(p) / this->cost;
		}
	}

	// 重载小于运算
	bool operator<(const coins &coinsK) {
		return this->rate > coinsK.rate; //性价比高
	}
};

int main() {
	int N, K1, K2;
	cin >> N >> K1 >> K2;
	int X, Y, Z;
	cin >> X >> Y >> Z;
	coins money(X, Y, Z); //当前资金

	vector<coins> objects;
	int a, b, c, p;
	for (int i = 0; i < N; ++i) {
		scanf("%d%d%d%d", &a, &b, &c, &p);
		objects.push_back(coins(a, b, c, p));
	}

	// 贪心算法
//	if (K2 <= K1 ) {
//		sort(objects.begin(), objects.end());
//
//		int i = 0;
//		while (money.cost > 0 && i < objects.size() && K2 <= K1) {
//			if(money.cost >= objects[i].cost){
//				money -= objects[i];
//				K2 += objects[i].p;
//			}
//			++i;
//		}
//	}

	// 动态规划
	if(K2 <=K1){
		// money的cost以及
		int m = objects.size();
		int amount = money.cost;
		vector<vector<int> > dp(m,vector<int>(amount+1,0) );

		for(int i=0;i<objects.size();++i){
			for(int v=objects[i].cost;v<amount;++v){
				if(v>=objects[i].cost) {
					dp[i][v] = max(dp[i][v],dp[i][v-objects[i].cost]+objects[i].p);
				}
			}
		}

		K2 += dp[m-1][amount];
	}


	if (K2>K1 && money.cost >= 0) {
		cout << "YES" << endl;
		cout << money.a << " " << money.b << " " << money.c << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}

//3 9 7
//2 2 2
//2 2 2 3
//1 1 1 2
//3 3 3 4


