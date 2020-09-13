//
// Created by wbzhang on 2020/8/23.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// 判断是否为回文串
bool isParadin(string s,int l,int h)
{
	while(l<h){
		if(s[l]!=s[h]) return false;
		l++,h--;
	}
	return true;
}

bool bruteForce(string s,int n,int m)
{
	if(s.length()<m) return false;

	for(int i=0;i<n-m-1;i++){
		if( isParadin(s,i,m) ) return true;
	}
	return false;
}



//bool dblptr(string s,int n,int m)
//{
//	//
//
//}


int main()
{
	int T;
	T=1;
//	cin>>T;
	while(T>0){
//		int m,n;
//		cin>>n>>m;
//		string str;
//		cin>>str;
//		getline(cin,str);
//		cout<<str<<endl;

		int n=6,m=3;
		string str = "acdcxb";
		string str = "acdcxb";

		// 寻找回文子串
		bool ans = bruteForce(str,n,m);
		cout<<ans<<endl;

		--T;
	}


	return 0;
}