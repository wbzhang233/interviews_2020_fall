//
// Created by wbzhang on 2020/8/13.
//


#include <iostream>
#include <cstdio>
#include <string>
#include <unordered_map>

using namespace std;

bool isAnSame(string s1,string s2)
{
	unordered_map<char,int> hist1,hist2;
	for(auto ele:s1) hist1[ele]++;
	for(auto ele:s2) hist2[ele]++;

	auto iter =hist1.begin();
	while(iter!=hist1.end() ){
		// 查找该数
		auto finder = hist2.find(iter->first);
		if(finder == hist2.end() ){
			return false;
		}else if(finder->second!=iter->second){
			return false;
		}
		iter++;
	}
	return true;
}

bool isAnnSame(string s1,string s2)
{
	int hist1[256] = {0};
	int hist2[256] = {0};
	for(auto ele:s1) hist1[ele]++;
	for(auto ele:s2) hist2[ele]++;

	for(int i=0;i<256;i++){
		if(hist1[i]!=hist2[i]) return false;
	}
	return true;
}

int main(){
	string str1,str2;
//	getline(cin,str1);
//	getline(cin,str2);

	str1 = "bcbc";
	str2 = "cbcb";

	bool ans = isAnnSame(str1,str2);
	cout<<ans<<endl;

	return 0;
}