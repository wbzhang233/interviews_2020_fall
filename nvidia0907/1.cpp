//
// Created by wbzhang on 2020/9/7.
//

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

/**
 * 交换数组里n和0的位置
 * array: 存储[0-n)的数组
 * len: 数组长度
 * n: 数组里要和0交换的数
 */
extern void swap_with_zero(int* array, int len, int n);

class Solution {
public:
	/**
	 * 调用方法swap_with_zero来对array进行排序
	 */
	void sort(int* array, int len) {
		if(len<=1) return;
		swap_with_zero(array,len,1);

		for(int i=2;i<len;i++){
			swap_with_zero(array,len,i);
			sort(array+i,len-i);
		}

	}
};

int main(){
	int *array = {2,5,0,1,4,3};
	int len = sizeof(array)/ sizeof(*array);
	Solution solu;
	solu.sort(array,len);
	for(int i=0;i<len;++i){
		cout<<array[i]<<"\t";
	}

	return 0;
}


