//
// Created by wbzhang on 2020/9/20.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//6 6 20 10
//S#++O#
//OXX#X#
//++++++
//###XX#
//++#O#+
//OXO++X
//SSDDDDDAWWSSSAWSSSADDD

int countScore(vector<vector<char> > &mp,string &path,int sx,int sy,int P,int Q)
{
	int score = 0;

	int n = mp.size(), m= mp[0].size();
	int cx = sx,cy = sy;
	for(auto ch:path){
		switch (ch){
			case 'W':{
				// 判断是否越界或者碰壁，如果越界或碰壁，则原地不动，跳过
				if(cx-1>=0 && mp[cx-1][cy]!='#'){
					if(mp[cx-1][cy]=='X') score -= Q;
					if(mp[cx-1][cy]=='O') score += P;
					mp[cx-1][cy]='+';
					cx--;
				}
				break;
			}
			case 'A':{
				// 判断是否越界或者碰壁，如果越界或碰壁，则原地不动，跳过
				if(cy-1<0 || mp[cx][cy-1]=='#'){
					break;
				}else{
					if(mp[cx][cy-1]=='X') score -= Q;
					if(mp[cx][cy-1]=='O') score += P;
					mp[cx][cy-1]='+';
					cy--;
				}
				break;
			}
			case 'S':{
				// 判断是否越界或者碰壁，如果越界或碰壁，则原地不动，跳过
				if(cx+1>=n || mp[cx+1][cy]=='#'){
					break;
				}else{
					if(mp[cx+1][cy]=='X') score -= Q;
					if(mp[cx+1][cy]=='O') score += P;
					mp[cx+1][cy]='+';
					cx++;
				}
				break;
			}
			case 'D':{
				// 判断是否越界或者碰壁，如果越界或碰壁，则原地不动，跳过
				if(cy+1>=m || mp[cx][cy+1]=='#'){
					break;
				}else {
					if(mp[cx][cy+1]=='X') score -= Q;
					if(mp[cx][cy+1]=='O') score += P;
					mp[cx][cy+1]='+';
					cy++;
				}
				break;
			}
		}
	}
	return score;
}

int main()
{
	int N,M,P,Q;
	cin >> N >> M >> P>> Q;

	vector<vector<char> > mp;
	int sx = -1,sy = -1;
	char ch;
	for(int i = 0; i < N; ++i){
		vector<char> chVec;
		for (int j = 0; j < M; ++j) {
			cin>>ch;
			chVec.push_back(ch);
			if(ch=='S'){
				sx = i;
				sy = j;
			}
		}
		mp.push_back(chVec);
	}

	string path;
	cin>>path;

	int score = countScore(mp,path,sx,sy,P,Q);
	cout<<score<<endl;

	return 0;
}