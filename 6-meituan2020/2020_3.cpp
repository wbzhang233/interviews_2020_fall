//
// Created by wbzhang on 2020/8/10.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
//void swap(string& a, string& b) {
// string tmp;
// tmp = a;
// a = b;
// b = tmp;
//}

bool operator>=(const string &left, const string &right)
{
	if (left == "" && right != "")
	{
		return true;
	}
	else if (left != "" && right == "")
	{
		return false;
	}
	else if (left.size() <= right.size() && left == right.substr(0, left.size()))
	{
		return true; //left為right的前綴
	}
	else if (left.size() > right.size() && right == left.substr(0, right.size()))
	{
		return false; //right为left的前缀
	}
	else
	{
		return left > right;
	}
}

// 快排
void sortstr(vector<string> &strs, int l, int r)
{

	int left = l, right = r;
	if (l > r)
	{
		return;
	}
	string sign = strs[left];//pivot
	while (left < right)
	{
		while (strs[right].compare(sign) && left<right) {
			right--;
		}
		while (sign.compare(strs[left]) && left < right) {
			left++;
		}
//        while (strs[right] >= sign && left < right)
//        {
//            right--;
//        }
//        while (sign >= strs[left] && left < right)
//        {
//            left++;
//        }
		if (left < right)
		{
			swap(strs[left], strs[right]);
		}
	}
	swap(strs[l], strs[left]);
	sortstr(strs, l, left - 1);
	sortstr(strs, left + 1, r);
}
int main()
{
	vector<string> strs;
	string word, line;
	while (getline(cin, line))
	{
		if (line.size() == 0)
			break;
//        istringstream record(line);
		for (int i = 0; i < line.size(); i++)
		{
			if (line[i] == ',')
			{
				strs.push_back(word);
				word = "";
			}
			else if (i == line.size() - 1)
			{
				word += line[i];
				strs.push_back(word);
				word = "";
				break;
			}
			else
			{
				word += line[i];
			}
		}
		sortstr(strs, 0, strs.size() - 1);
		for (int j = strs.size() - 1; j >= 0; j--)
		{
			if (j > 0)
				cout << strs[j] << ',';
			else
				cout << strs[j] << endl;
		}
	}
}

// abcde,waimai,dache,lvyou,liren,meishi,jiehun,lvyoujingdian,jiaopei,menpiao,jiudian