//
// created by wbzhang on 2020/8/13.
//

#include <iostream>
using namespace std;
const int maxp=2000,n=10000;
int prime[maxp],total=0;
bool isprime(int k)//bool函数用来求素数
{
	for(int i=0;i<total;i++)
		if(k%prime[i]==0)//判断素数的一种方法（用这个数对数组当中所有的 素数 进行取余；
			return false;
	return true;
}
int main()
{
	for(int i=2;i<n;i++)
		if(isprime(i))
			prime[total++]=i;//total++是先用后加。此处之前的代码是把2~n之间的素数全部都存储到prime[total]数组中。
	prime[total]=n+1;
	int m;
	cin>>m;
	while(m)
	{
		int ans=0;//用于计算个数
		for(int i=0;prime[i]<=m;i++)//外层循环用来枚举所有的可能性
		{
			int cnt=0;//求和
			for(int j=i;j<total,cnt<m;j++)//内循环用来判断所求和的大小是否符合
				cnt+=prime[j];
			if(cnt==m)
				++ans;
		}
		cout<<ans<<endl;
		cin>>m;
	}
	return 0;
}