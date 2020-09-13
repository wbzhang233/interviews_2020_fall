//
// Created by wbzhang on 2020/8/29.
//

//
// Created by wbzhang on 2020/8/29.
//

#include <iostream>
#include <vector>

using namespace std;

bool isIncreased(string s){
	int n = s.size();
	if(n==1) return true;

	for(int i=1;i<n;i++){
		if(s[i]<=s[i-1]){
			return false;
		}
	}
	return true;
}

int main() {
	long long num;
	cin>>num;
	string str = to_string(num);
	int n = str.length();

//	if(!isIncreased(str) ){
	int i=0;
	bool find = false;
	while(i<n && str[i]!='0'){
		// 从后往前找一个最大的非0数字进行替换
		int maxInd = i;
		char maxC = '0';
		for(int j=i+1;j<n;j++){
			if(str[j]<str[i] && str[j]>maxC){
				maxC = str[j];
				maxInd = j;
			}
		}
		// 如果找到则交换，否则
		if(maxInd!=i){
			char tmp = str[maxInd];
			str[maxInd] = str[i];
			str[i] = tmp;
			find = true;
			break;
		}

		i++;
	}
	if(find)
		cout<<stoll(str)<<endl;
	else cout<<0<<endl;
//	}else if(str.size()==1 ){
//		cout<<0<<endl;
//	}


}

/*
 * 思路：差分成字符串，从后往前找一个比最后数字更大的
 * 如果该数字，升序，则不存在
 * 否则从第二位开始，寻找一个比第二位更大的数字;
 *
 * 特判定--前导0
 * 1位：不存在
 * 2位：是否从第1位开始递增； (20的话，也不存在)
 * 3位及以上：
 */


// 对于每一个非0数字，从前往后找一个降序的非0，且最大的数字进行交换
// 753421--? 752431
// 103->不存在
// 1030->1003




///

//
// Created by wbzhang on 2020/8/29.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
	long long num;
//	cin>>num;

	while(cin>>num){

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
			}else{
				int maxInd = i;
				char maxC = 0;
				for(int j=i+1;j<n;j++){
					if(str[j]>str[i] && str[j]>maxC){
						maxC = str[j];
						maxInd = j;
					}
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
			cout<<stoll(str)<<endl;
		}
		else cout<<0<<endl;

	}
	return 0;
}

// 如果找到并且i不为0，且str[j]！='0'，则可以更新；
// 否则
