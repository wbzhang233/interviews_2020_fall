//
// Created by wbzhang on 2020/10/16.
//

#include <iostream>
#include <vector>
#include <stack>
#include <cstdio>
using namespace std;

bool isCouple(char c1,char c2)
{
	if(c1=='(' && c2==')') return true;
	if(c1=='[' && c2==']') return true;
	if(c1=='{' && c2=='}') return true;
	return false;
}

bool isValidBracket(string s)
{
	stack<int> lst;
	for(auto c:s){
		// 当前是否为左括号
		if(c=='(' || c=='[' ||c=='{'){
			lst.push(c);
		}else{
			if(lst.empty() ){
				// 栈为空，并且遇到右括号
				return false;
			}else if( !isCouple(lst.top(),c) ){
				return false;
			}else{
				lst.pop();
			}
		}
	}
	return lst.empty();
}

int main()
{
	int T;
	cin>>T;
//	scanf("%d",&T);
	string s;
	while(T>0){
		cin>>s;
//		getline(cin,s);
		if(isValidBracket(s) ){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
		--T;
	}

	return 0;
}