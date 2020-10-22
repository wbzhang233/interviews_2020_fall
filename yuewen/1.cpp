/*
 * @Date: 2020-10-21 19:27:16
 * @LastEditors: wbzhang
 * @LastEditTime: 2020-10-21 20:03:58
 * @FilePath: \2-interviews\yuewen\1.cpp
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 
     * @param nums int整型一维数组 
     * @param numsLen int nums数组长度
     * @return bool布尔型
     */
    
    int accumulateNums(int* nums,int numsLen)
    {
        int res = 0;
        for(int i=0;i<numsLen;++i){
            res += nums[i];
        }
        return res;
    }

    // 快速排序
    int partition(int* nums,int low,int high)
    {
        int pivot = nums[low];
        while(low <high){
            while(low<high && nums[high]>pivot){
                --high;
            }
            nums[low]=nums[high];
            while(low<high && nums[low]<pivot){
                ++low;
            }
            nums[high]=nums[low];
        }
        nums[low] = pivot;
        return low;
    }

    void quickSort(int* nums,int low,int high)
    {
        if(low<high){
            int pivot = partition(nums,low,high);
            quickSort(nums,0,pivot);
            quickSort(nums,pivot+1,high);
        }
    }

        // 回溯：路径-vector,起点，当前和
    // bool dfs(int* nums,int numsLen,int &tar,int &curr_sum,vector<bool> &vis,int fi){
    //     if(curr_sum==tar){
    //         return true;
    //     }

    //     if(curr_sum>tar){
    //         return;
    //     }

    //     // 做选择
    //     for(int i=fi;nums[i]<tar;i++){
    //         if(!vis[i]){
    //             vis[i] = true;
    //             curr_sum +=nums[i];
    //             dfs(nums,numsLen,tar,curr_sum,vis,i+1);
    //             vis[i]=false;
    //             curr_sum-=nums[i];
    //         }
    //     }
        
    // }


    void dfs(bool &res,int* nums,int numsLen,int &tar,int &curr_sum,int fi){
        if(curr_sum==tar){
            res = true;
        }

        if(curr_sum>tar){
            return;
        }

        // 做选择
        for(int i=fi;nums[i]<tar;i++){
            curr_sum +=nums[i];
            dfs(res,nums,numsLen,tar,curr_sum,i+1);
            curr_sum-=nums[i];
        }
        
    }

    
    bool canPartition(int* nums, int numsLen) {
        int allWeight = accumulateNums(nums,numsLen);
        // 如果总重为奇数，则不能
        if(allWeight%2==1) return false;

        // 否则，排序
        quickSort(nums,0,numsLen-1);
        // 如果最后一件物品的重量超过总重的一半，则不能
        if(nums[numsLen-1]*2>allWeight) return false;
        // 否则回溯
        vector<bool> vis(numsLen,false);
        int curr_sum = 0;
        int tar = allWeight/2;
        bool res = false;
        dfs(res,nums,numsLen,tar,curr_sum,0);

        return res;
    }
};