//
// Created by wbzhang on 2020/9/19.
//

#include <iostream>
#include <vector>

using namespace std;

bool getAns(vector<int> &nums)
{
	int fn = 0,tn = 0,twn = 0;
	for(auto ele:nums){
		if(ele==5){
			++fn;
			continue;
		}else if(ele==10){
			if(fn<1) return false;
			--fn;
			++tn;
		}else if(ele==20){
			if(fn<1) return false; //没有5块的,false
			else if(tn>=1){
				--tn; // 先用十块的
				--fn;
				++twn;
				continue;
			}else if(tn<1){
				if(fn<3) return false;
				else{
					fn-=3;
					twn+=1;
				}
			}

		}
	}

	return true;
}

int main()
{
	string string1;
	getline(cin,string1);

	vector<int> nums;
	int x = 0;
	for(auto ch:string1)
	{
		if(ch=='[' || ch==']') continue;
		else if(ch==','){
			nums.push_back(x);
			x = 0;
		}
		else if( isdigit(ch) ){
			x = 10*x + (ch-'0');
		}
	}

	bool res = getAns(nums);
	if(res) cout<<"true"<<endl;
	else cout<<"false"<<endl;

	return 0;
}