//
// Created by wbzhang on 2020/9/27.
//

#include <iostream>
#include <vector>

using namespace std;

const int maxN = 100;


void printMat(vector<vector<int> > &mat)
{
	for(auto vec:mat){
		for(auto ele:vec){
			cout<<ele<<" ";
		}
		cout<<endl;
	}
}

void setCircle(vector<vector<int> > &mat, int N, int s, int &startNum, bool flag) {
	// 根据方向，依次填入值
	int r = s, c = s;

	if (flag) {
		// 从左往右填入一行
		while (c < N - 1 - s) {
			mat[r][c++] = startNum++;
		}
		// 从上往下填入一列
		while (r < N - 1 - s) {
			mat[r++][c] = startNum++;
		}
		// 从右往左填入一行
		while (c > s) {
			mat[r][c--] = startNum++;
		}
		// 从下往上填入一列
		while (r > s) {
			mat[r--][c] = startNum++;
		}

	} else {
		// 从上往下填入一列
		while (r < N - 1 - s) {
			mat[r++][c] = startNum++;
		}
		// 从左往右填入一行
		while (c < N - 1 - s) {
			mat[r][c++] = startNum++;
		}
		// 从下往上填入一列
		while (r > s) {
			mat[r--][c] = startNum++;
		}
		// 从右往左填入一行
		while (c > s) {
			mat[r][c--] = startNum++;
		}
	}


}

void getMatrix(vector<vector<int> > &mat, int N) {
	bool clockWise = true;
	int s = 0, startNum = 1;
	while (s <= (N+1) / 2) {
		setCircle(mat, N, s, startNum, clockWise);
		clockWise = !clockWise;
//		startNum += 4 * (N - s * 2) - 3 - 1;
		s++;
	}
	if(N%2==1)
		mat[(N-1)/2][(N-1)/2] = startNum;
}

int main() {
	int C, N, M;
	cin >> C;
	while (C > 0) {
		cin >> N >> M;
		// 生成大小为N*N的仿真
		vector<vector<int> > mat(N, vector<int>(N, 0));
		getMatrix(mat, N);
//		printMat(mat);

		int x = 0, y = 0;

		while (M > 0) {
			cin >> x >>y;
			cout<<mat[x][y]<<endl;
			--M;
		}

		--C;
	}


	return 0;
}