// 题目来源，pdd真题 ：https://www.nowcoder.com/question/next?pid=23354036&qid=967825&tid=35431702

#include <iostream>
#include <vector>

using namespace std;

struct Point{
    int min,max;
    Point(int a,int b):min(a),max(b){};
};

struct MyPair{
    vector<int> line;
    Point p;
    MyPair(vector<int> _l,Point _p):line(_l),p(_p){};
};

// 计算全排列
int maxV = INT32_MIN, minV= INT32_MAX;
vector<MyPair> lines;


Point getResForOne(vector<int> path){
    Point res(INT32_MAX,INT32_MIN);
    if(path.size()==0) return res;
    vector<int> f(path.size());
    f[0] = path[0];
    for(int i=1;i<path.size();++i){
        f[i] = abs(f[i-1]-path[i]);
    }
    res.min = f.back()<res.min? f.back() :res.min;
    res.max = f.back()>res.max? f.back() :res.max;
    return res;
}

void backTrack(int N,vector<bool> &path,vector<int> &res){
    // 截止条件
    if(res.size()==N){
        // 计算当前路径的最大最小值
        Point p = getResForOne(res);
        maxV = p.max > maxV ? p.max : maxV;
        minV = p.min < minV ? p.min : minV;
        lines.push_back(MyPair{res,Point(minV,maxV)});
        return;
    }

    // 选择
    for(int i=1;i<N+1;i++){
        if(path[i]) continue;
        // 选择
        path[i] = true;
        res.push_back(i);
        backTrack(N, path,res);
        // 撤销选择
        path[i] = false;
        res.pop_back();
    }
}

int main(int argc,char** argv){
    int T;
    cin>>T;
    int N;
    for(int i=0;i<T;i++){
        cin>>N;
        // 计算当前全排列中最值
        // 计算全排列，并计算最值
        vector<bool> path(N,false);
        vector<int> res;
        maxV = INT32_MIN, minV= INT32_MAX;
        backTrack(N,path,res);
        cout<<minV<<" "<<maxV<<endl;
    }

    return 0;
}
