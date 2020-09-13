//
// Created by wbzhang on 2020/8/29.
//

//
// Created by wbzhang on 2020/8/29.
//

//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	unsigned long long num;
	cin>>num;
	if(num<=11){
		cout<<0<<endl;
		return 0;
	}

	//while(cin>>num){

	string str = to_string(num);
	int n = str.length();

	int lastFind = -1;
	int lastSInd = -1;

	int i=0;
	while(i<n){
		if(str[i]!='0'){
			// 从前往后找一个最大的非0数字进行替换
			int maxInd = i;
			char maxC = 0;
			for(int j=i+1;j<n;j++){
				if(str[j]<str[i] && str[j]>maxC){
					maxC = str[j];
					maxInd = j;
				}
			}
			// 如果找到则更新，否则
			if(maxInd!=i && i==0 && str[maxInd]=='0'){
				i++;
				continue; //第一位只能找到后导0，则不计入
			}
			if(maxInd!=i ){
				lastFind = max(lastFind,i);
				lastSInd = maxInd;
			}
		}

		i++;
	}
	if(lastFind!=-1){
		char tmp = str[lastSInd];
		str[lastSInd] = str[lastFind];
		str[lastFind] = tmp;
		cout<<stoull(str)<<endl;
	}
	else cout<<0<<endl;

	//}
	return 0;
}

// 如果找到并且i不为0，且str[j]！='0'，则可以更新；
// 否则