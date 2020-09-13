//
// Created by wbzhang on 2020/9/6.
//


#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
private:
	vector<int> size;
	vector<int> parent;
	int count;
public:
	UnionFind(int n){
		unionCreate(n);
	}

	// 并查集合，初始化大小
	void unionCreate(int n)
	{
		this->count = n;
		parent.assign(n,0);
		size.assign(n,0);
		for(int i=0;i<n;i++){
			parent[i] = i;
			size[i] = 1;
		}
	}

	// 路径压缩
	int find(int p){
		while(parent[p]!=p){
			parent[p] = parent[parent[p] ];
			p = parent[p];
		}
		return p;
	}

	// 合并两个并查集
	void unionTwo(int p,int q){
		int pRoot = find(p);
		int qRoot = find(q);
		if(pRoot==qRoot) return; //同一个集合，不用合并

		if(size[pRoot]>size[qRoot]){
			parent[qRoot] = pRoot;
			size[pRoot] += size[qRoot];
		}else{
			parent[pRoot] = qRoot;
			size[qRoot] += size[pRoot];
		}
		count--;
	}


	// 是否属于同一个集合
	bool isConnected(int p,int q){
		int pRoot = find(p);
		int qRoot = find(q);
		return pRoot==qRoot;
	}

};

int main() {
	int n, m;
	cin >> n >> m;
	int x;
	vector<vector<int> > group;
	for(int i=0;i<m;i++){
		cin>>x;
		int tmp;
		vector<int> liGroup;
		for(int j=0;i<x;j++){
			cin>>tmp;
			liGroup.push_back(tmp);
		}
		group.push_back(liGroup);
	}

	// 使用并查集
	UnionFind uf(m);//m个团队
	int fInd = -1;
	for(int i =0;i<m;i++){
		for(int j=0;j<group[i].size();j++){
			uf.unionTwo(i,group[i][j]);
			if(group[i][j] = 0 && ){

			}
		}
	}
	uf.find();
	// 建立并查集，每个团队编号的福编号均为i,进行路径压缩
	// 找到输入0所在的并查集，
	// 然


}