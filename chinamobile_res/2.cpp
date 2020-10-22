//
// Created by wbzhang on 2020/10/18.
//

#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int getWordCount(string str)
{
	int res = 0;
	bool f = false;
	for(auto ele:str){
		if(isalpha(ele) ){
			f = true;
			continue;
		}else if(ele==' ' && f){
			res++;
		}
	}
	return res+1;
}

int main()
{
	int N;
	cin >> N;

	string s;
	char c1,c2;
	while(N>0){
		cin>>c1;
		getline(cin,s);
		cout<<getWordCount(s)<<" ";
		--N;
	}

	return 0;
}

//2
//"Hello my name is Xiaoxi"
//"I can do it"