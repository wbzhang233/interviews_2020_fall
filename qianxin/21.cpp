//
// Created by wbzhang on 2020/9/2.
//
#include "../commonHeader.h"

class Solution {
public:
	/**
	 *
	 * @param person int整型一维数组
	 * @param personLen int person数组长度
	 * @return int整型
	 */

	int house2(int* person, int personLen) {
		if(personLen<2)
			return personLen;

		vector<int> nums(personLen,1);
		for(int i=0;i<personLen;i++){
			if(i==0 ){
				if(person[0]>person[1])
					nums[i]++;
			}else if(i==personLen-1  ){
				if(person[i]>person[i-1])
					nums[i]++; // 最后一户
			}else{
				if(person[i]>person[i-1] || person[i]>person[i+1])
				{
					nums[i] = max(nums[i-1],nums[i+1])+1;
				}
			}
		}

		vector<int> nums2(personLen,1);
		for(int i=personLen-1;i>=0;i--){
			if(i==0 ){
				if(person[0]>person[1])
					nums2[i]++;
			}else if(i==personLen-1){
				if(person[i]>person[i-1])
					nums2[i]++; // 最后一户
			}else{
				if(person[i]>person[i-1] || person[i]>person[i+1])
				{
					nums2[i] = max(nums2[i-1],nums2[i+1])+1;
				}
			}
		}

		int sum = 0;
		for(int i=0;i<personLen;i++){
			if(i==0 || i==personLen-1)
				nums[i] = max(nums[i],nums2[i]);
			else{
				nums[i] = max(nums[i-1],nums2[i+1]);
			}
			sum +=nums[i];
		}
		return sum;
	}

	int house(int* person, int personLen) {
		if (personLen < 2)
			return personLen;

		vector<int> nums(personLen-1);
		int sum1 = personLen;
		for(int i=1;i<personLen;i++){
			nums[i] = person[i] - person[i-1];
			if(!nums[i]) sum1++;
		}

		vector<int> nums2(personLen-1);
		int sum2= personLen;
		for(int i=personLen-2;i>=0;i--){
			nums2[i] = person[i] - person[i+1];
			if(!nums2[i]) sum2++;
		}

//		int sum = 0;
//		for(int i=0;i<personLen;i++){
//			sum +=nums[i];
//		}
		return max(sum1,sum2);
	}

};

int main()
{
	int person[] = {4,1,3,3,3};
	int n = 5;
	Solution solu;
	cout<<solu.house(person,n)<<endl;

	return 0;
}
