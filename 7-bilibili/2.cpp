//
// Created by wbzhang on 2020/8/13.
//

#include <iostream>
#include <vector>
using namespace std;

// getPrimeNum，可以使用 排除法来生成小于n的质数
void getPrimeBelowN(int N, vector<int>& primes)
{
	int nums[N+1]; //0-2,2-N
	for (int i = 2; i < N; ++i) {
		for (int j = 2; j*i <= N; ++j) {
			nums[i*j]=1; // 2*2开始标记
		}
	}
	for (int k = 2; k <= N; ++k) {
		if(nums[k]!=1 ) primes.push_back(k); //大于等于2且未被标记
	}
}

// 连续的质数之和,采用滑窗法
void getNums(int N,vector<int>& primes,int &ans){
	if(primes.size()==1 ){
		ans = (primes[0]==N);
		return;
	}
	// 从数组头部开始，双指针;记录当前和
	int i=0,j=1;
	int currSum = primes[0]+primes[1];
	// 如果当前和小于N，则j++;如果等于，则ans++;否则i++
	 while(i<=j && j<=primes.size()) {
		if(currSum==N){
			ans++;
			currSum += primes[++j];
		}else if(currSum<N){
			currSum += primes[++j];
		}else{
			currSum -= primes[i++];
		}
	}
	 // 直到，
}

// 双指针法
void getNums2(int N,vector<int>& primes,int &ans)
{
	int sum = 0;
	int i = 0, j = 0;
	while(j<primes.size() )
	{
		sum += primes[j];
		while(sum>=N ){
			if(sum==N) ans++;//计数加1
			sum -=primes[i++];
		} //右移i
		j++; //右移j
	}
}

int main() {
	int n,cnt = 0;
//	cin>>n;
//	n = 41;

	while(	cin>>n){
		cnt = 0;
		vector<int> primes;
		getPrimeBelowN(n,primes);

//		cout<<"---"<<endl;
//		for(auto ele:primes) cout<<ele<<endl;
//		cout<<"---"<<endl;

		getNums2(n, primes,cnt);

		cout<<cnt<<endl;
	}

}