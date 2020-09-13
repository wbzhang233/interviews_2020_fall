//
// Created by wbzhang on 2020/9/1.
//

#include <iostream>
#include <vector>

using namespace std;

typedef pair<string,int> Pstrint;

int main()
{
	int n,m;
	cin>>n>>m;
	vector<Pstrint> strs;
	for(int i=0;i<n;i++){
		string s;
		int x;
		cin>>s;
		cin>>x;
		strs.push_back( make_pair(s,x) );
	}


	return 0;
}

//3 5
//01101 4
//10100 3
//00011 3