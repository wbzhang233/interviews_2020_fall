//
// Created by wbzhang on 2020/8/29.
//

#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>

using namespace std;

int main(){
	string str,ans;
	getline(cin,str);
	int n = str.length();
	bool tran =false;
	for(int i = 0; i < n; i++){
		if(!isalnum(str[i]) ){
			tran = true;
			continue;
		}
		if(isalnum(str[i])  && tran){
			if(ans.empty() ){
				ans.push_back(tolower(str[i])); //第一个不为大写
			}else{
				ans.push_back(toupper(str[i]));
			}
			tran = false;
		}else if(isalnum(str[i])  && !tran ){

				ans.push_back(tolower(str[i]) );
		}
	}
	cout << ans << endl;
	return 0;
}

/*
 * 如果第一个不为 alnum，则指标职位为1，直到遇到alnum，将其转变成大写，输入
 * 否则，直接输入
 */