//
// Created by wbzhang on 2020/9/20.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Ans{
	bool flag;
	int sum;
	Ans():flag(false),sum(0){};
};

// 从t中进行匹配
Ans isSubString(string &s,string &t)
{
	Ans ans;

	unsigned int i=0,j=0;
	while(i<s.size() && j<t.size() ){
		if(s[i]==t[j]){
			++i;
			++j;
			ans.sum +=i;
		}else{
			++i;
		}
	}

	ans.flag = (j == t.size());

	return ans;
}

int main()
{
	int n,m;
	cin >> n >>m;
	string s,t;
//	getline(cin,s);
	char ch;
	for(int i=0;i<n;++i){
//		scanf("%c",&ch);
		cin>>ch;
		s.push_back(ch);
	}

//	getline(cin,t);
	for(int i=0;i<m;++i){
//		scanf("%c",&ch);
		cin>>ch;
		t.push_back(ch);
	}

	Ans ans;
	if(s.size()>=t.size() ){
		ans = isSubString(s,t);
	}
	if(ans.flag){
		cout<<"Yes"<<endl;
		cout<<ans.sum<<endl;
	}else{
		cout<<"No"<<endl;
	}

	return 0;
}
