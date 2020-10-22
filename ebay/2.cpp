//
// Created by wbzhang on 2020/9/24.
//

#include <iostream>
#include <vector>

using namespace std;


// 路径
void backTrack(bool &ans,vector<int> &nums, vector<int> &path, vector<bool> &vis, int fi, int &m) {
	if (path.size() == m) {
		ans = true;
		return;
	}

	if (ans) return;
	// 做选择
	for (int i = fi; i < nums.size(); ++i) {
		if (vis[i]) continue;
		// 剪枝
		bool isOpt = true;
		for (auto ele:path) {
			if ((ele + nums[i]) % 3 != 0) {
				isOpt = false;
				break;
			}
		}
		//
		if (isOpt) {
			path.push_back(nums[i]);
			vis[i] = true;
			backTrack(ans,nums, path, vis, i + 1, m);
			vis[i] = false;
			path.pop_back();
		}
	}

}

int main() {
	int T;
	cin >> T;
	int n, m, k;

	while (T > 0) {

		cin >> n >> m >> k;
		vector<int> nums;

		int x;
		for (int i = 0; i < n; ++i) {
			cin >> x;
			nums.push_back(x);
		}

		// 回溯
		// 起点为fi找m个数
		bool ans;
		for (int i = 0; i + m <= n - 1; ++i) {
			vector<int> path = {};
			vector<bool> vis(n, false);
			ans = false;
			backTrack(ans,nums, path, vis, i, m);
		}

		string output = ans ? "Yes" : "No";
		cout << output << endl;

		--T;
	}

	return 0;
}


//2
//5 4 3
//3 3 6 9 3
//5 4 3
//3 2 6 9 2