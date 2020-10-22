//
// Created by wbzhang on 2020/9/20.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const long long int limit = 1000000000;

int getAns(int A,int B,int C,int X,int Y)
{
	if(X<2 && Y <2){
		if(X==1 &&Y==1) return 0;
		if(X==1 &&Y==2) return A;
		if(X==2 &&Y==1) return B;
		if(X==2 &&Y==2) return C;
	}

	int n;
	while(pow(2,n)<X || pow(2,n)<Y){
		++n;
	}

	if( X<pow(2,n-1) && Y<pow(2,n-1)){
		return getAns(A,B,C,X/2,Y/2)%limit;
	}else if( X<pow(2,n-1) && Y>=pow(2,n-1)){
		return getAns(A,B,C,X/2,Y/2)%limit+A;
	}else if( X>=pow(2,n-1) && Y<pow(2,n-1)){
		return getAns(A,B,C,X/2,Y/2)%limit+B;
	}

	return getAns(A,B,C,X/2,Y/2)%limit +C;
}

int main()
{
	int A,B,C,N;
	cin >>A>>B>>C>>N;

	int X,Y;
	for(int i=0;i<N;++i){
		cin>>X>>Y;
		cout<<getAns(A,B,C,X,Y)<<endl;
	}

}