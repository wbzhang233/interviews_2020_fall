//
// Created by wbzhang on 2020/9/19.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<vector<char> > nums(3,vector<char>(3,'0'));
	char ch;
	int i = 0;
	while(i<9){
		cin>>ch;
		if(ch==' ') continue;
		else{
			nums[i/3][i%3] = ch;
			i++;
		}
	}

	string res;
	for(int c=0;c<3;++c){
		for(int r=0;r<3;++r){
			res.push_back(nums[r][c]);
		}
	}
	cout<<res<<endl;

	return 0;
}