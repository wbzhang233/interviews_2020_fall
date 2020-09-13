//
// Created by wbzhang on 2020/9/2.
//

#include <iostream>
#include <vector>

using namespace std;

int plt(int n){
	if(n==1) return 1;
	if(n==2) return 2;
	return plt(n-1)+plt(n-2);
}

int main()
{
	int n;
	cin>>n;
	if(n>0){
		cout<<plt(n)<<endl;
	}else
	{
		cout<<0<<endl;
	}

	return 0;
}