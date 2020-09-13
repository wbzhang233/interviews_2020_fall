//
// Created by wbzhang on 2020/8/24.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

#define EPISLON 0.00000000000001

vector<double> splitStr(string s,char delimeter)
{
	vector<double> res;
	string tmp;
	for(auto ele:s){
		if( ele!= delimeter){
			tmp.push_back(ele);
		}else{
			res.push_back(stod(tmp));
			tmp.clear();
		}
	}
	res.push_back(stod(tmp));
	return res;
}

// 45,60,100,98,80,80,45,75.5,90,95 //zice
int main()
{
	string s;
	getline(cin,s);
	vector<double> nums = splitStr(s,',');

	sort(nums.begin(),nums.end() );
	double minV = nums[0];
	int ans = 1;
	for(int i=1;i<10;i++){
		if( abs(nums[i]-minV)<EPISLON ){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}