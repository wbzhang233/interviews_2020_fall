//
// Created by wbzhang on 2020/8/6.
//
#include "../commonHeader.h"

int partition(vector<int> &nums, int low, int high){
    int pivot = nums[low];
    while(low < high)
    {
        while(low<high && nums[high]>=pivot){
            --high;
        }
        nums[low] = nums[high];
        while(low <high && nums[low]<=pivot ){
        ++low;
        }
        nums[high] = nums[low];
    }
    nums[low] = pivot;
    return low;
}


int findKth(vector<int> nums,int k)
{
    // partition函数
    int low = 0,high = nums.size()-1;
    int pivot = partition(nums,low,high);
    while(pivot!=k-1){
        if(pivot>k-1){
            high = pivot-1;
//            pivot = partition(nums,low,high);
        }else{
            low = pivot+1;
        }
        pivot = partition(nums,low,high);
    }
    return nums[pivot];
}

int main()
{
    int m,n,k;
    cin >> m >> n;
    cin>>k;

    vector<int> nums;
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            nums.push_back(i*j);
        }
    }

    //
    cout<<findKth(nums,k)<<endl;

    return 0;
}