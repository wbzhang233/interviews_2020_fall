//
// Created by wbzhang on 2020/9/2.
//
#include <vector>

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
		int sum = personLen; //

		for(int i=0;i<personLen;i++){
			if(i==0 && person[0]>person[1]){
				sum++; //第一户
			}else if(i==personLen-1 && person[i]>person[i-1]){
				sum++; // 最后一户
			}else{
				if(person[i]>person[i-1] || person[i]>person[i+1]) sum++;
				//if(person[i]>person[i+1]) sum++;
				// 中间的
			}
		}
		return sum;
	}

	int house(int* person, int personLen) {
		if(personLen<2)
			return personLen;

		vector<int> nums(personLen,1);
		for(int i=0;i<personLen;i++){
			if(i==0 && person[0]>person[1]){
				nums[i]++;
			}else if(i==personLen-1 && person[i]>person[i-1]){
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
			if(i==0 && person[0]>person[1]){
				nums2[i]++;
			}else if(i==personLen-1 && person[i]>person[i-1]){
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
			nums[i] = max(nums[i],nums2[i]);
			sum +=nums[i];
		}
		return sum;
	}


	int house(int* person, int personLen) {
		if(personLen<2)
			return personLen;
		int sum = 0;
		vector<int> nums(personLen,1);

		int i = 0,j = personLen-1;
		while(i<j){
			if(person[i]){

			}
		}


	}

};