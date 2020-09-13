//
// Created by wbzhang on 2020/8/6.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 双指针 && 动态规划
/*
8
A B C D E E C A
A C D E E B C F
*/
int maxLength(string s1,string s2){
    int N = s1.length();
    int count =0;
    for(int kk=0;kk<N;kk++){
        int count1 = 0;
        for(int i=kk,j=0;i<N &&j<N;i++){
            // 尝试依次匹配
            int ind = j;
            while(s1[i]!=s2[ind] && ind<N){
                ind++;
            }
            // 匹配成功或者不成功，则下一个
            if(s1[i]==s2[ind]){
                count1++;
                j=ind+1;
            }else{
                j++;
            }
            // 不成功，也下一个
        }
        count = max(count1,count);
    }


    return count;
}


int main(){
    //
    int N =8;
//    cin>>N;
//    string s1 = "",s2 = "";
//    for(int j=0;j<N;j++){
//        char x; cin>>x;
//        s1.push_back(x);
//    }
//    for(int j=0;j<N;j++){
//        char x; cin>>x;
//        s2.push_back(x);
//    }

    string s1 = "ABCDEECA";
    string s2 = "ACDEEBCF";

    // 最长公共子序列
    char res[10];
    int com = maxLength(s1,s2);
//     cout<<com<<endl;
    sprintf(res,"%.2f",double(com)/N );
    string yn;
    if(com<=0.5*N){
        yn = "Yes";
    }else yn= "No";
    cout<<res<<" "<<yn<<endl;
    return 0;
}


// beifen1
/*
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 双指针 && 动态规划

int maxLength(string s1,string s2){
    int N = s1.length();
    int count =0;
    for(int i=0,j=0;i<N &&j<N;i++){
        // 尝试依次匹配
        int ind = j;
        while(s1[i]!=s2[ind] && ind<N){
            ind++;
        }
        // 匹配成功或者不成功，则下一个
        if(s1[i]==s2[ind]){
            count++;
            j=ind+1;
        }else{
            j++;
        }
        // 不成功，也下一个
    }

    return count;
}


int main(){
    //
    int N;
    cin>>N;
    string s1 = "",s2 = "";
    for(int j=0;j<N;j++){
        char x; cin>>x;
        s1.push_back(x);
    }
    for(int j=0;j<N;j++){
        char x; cin>>x;
        s2.push_back(x);
    }

    // 最长公共子序列
    char res[10];
    int com = maxLength(s1,s2);
    // cout<<com<<endl;
    sprintf(res,"%.2f",double(com)/N );
    string yn;
    if(com/N<=0.5){
        yn = "Yes";
    }else yn= "No";
    cout<<res<<" "<<yn<<endl;
    return 0;
}
*/