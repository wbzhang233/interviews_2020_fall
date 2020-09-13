//
// Created by wbzhang on 2020/9/6.
//

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m, k;

struct Item {
	int p, w, v;

	bool operator< (const Item &item) const {
		if (v != item.v) return v > item.v;
		else if (p != item.p) return p < item.p;
		else return w < item.w;
	}
} items[N];


int main() {
	cin >> n >> m >> k;

	for (int i = 0; i < n; i ++ )
		cin >> items[i].p >> items[i].w >> items[i].v;

	sort(items, items + n);

	int ret = 0, weight = 0, money = 0;

	for (int i = 0; i < n; i ++ ) {
		auto &t = items[i];
		if (weight + t.w <= m && money + t.p <= k) {
			weight += t.w, money += t.p;
			ret ++ ;
		}
	}

	cout << ret;

	return 0;
}
