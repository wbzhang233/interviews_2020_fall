//
// Created by wbzhang on 2020/8/23.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iomanip>

using namespace std;

string getNthStr(string s,int k)
{
	int n= s.length();
	// 统计字符串中个字母出现的次数；
	unordered_map<char,int> mp;
	for(auto ele:s) mp[ele]++;

	// 子串长度为s,



}

int main()
{
	string s;
	cin>>s;
	int k;
	cin>>k;

	cout<<getNthStr(s)<<endl;

	return 0;
}