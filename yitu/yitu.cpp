//
// Created by wbzhang on 2020/9/17.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct pose{
	int t,x,y,z;
	pose(int ti,int xi,int yi,int zi):t(ti),x(xi),y(yi),z(zi){};
};

float getDist(const pose& pa,const pose& pb)
{
	float dist = (pa.x-pb.x)*(pa.x-pb.x)+(pa.y-pb.y)*(pa.y-pb.y)
				 +(pa.z-pb.z)*(pa.z-pb.z);
	return sqrt(dist)/(pb.t-pa.t);
}


int main()
{
	int N;
	cin>> N;
	int t,x,y,z;
	vector<pose> poses;
	for(int i=0;i<N;++i){
		cin >> t >> x >> y >> z;
		poses.push_back( pose(t,x,y,z));
	}

	vector<float> vnums;
	for(int i=1;i<poses.size();++i){
		vnums.push_back( getDist(poses[i-1],poses[i]) );
	}

	int ans = 0;
	for(int i=1;i<vnums.size();++i){
		if(vnums[i] > vnums[ans]) ans = i;
	}
	cout<< ++ans <<endl;

	return 0;
}

//3
//2 -9 2 3
//4 9 9 8
//9 2 3 4