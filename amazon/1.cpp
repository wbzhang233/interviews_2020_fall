// Sample code to read input and write output:

/*
#include <iostream>

using namespace std;

int main()
{
	char name[20];
	cin >> name;                     // Read input from STDIN
	cout << "Hello " << name;        // Write output to STDOUT
	return 0;
}
*/

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string getBiStringFromDec(int x) {
	string res;
	while (x > 0) {
		// res.append(to_string(x%2) );
		res.push_back(x % 2 + '0');
		x /= 2;
	}
	reverse(res.begin(), res.end());
	return res;
}

void getTran(string &str) {
	for (int i = str.size() - 1; i >= 0; --i) {
		if (str[i] == '1') str[i] = '0';
		else str[i] = '1';
	}
//	return str;
}


int getTrans(string &str) {
	int res = 0;

	getTran(str);
	int firstInd = 0;
	for (; firstInd < str.length(); ++firstInd) {
		if (str[firstInd] == '1') break;
	}

	int j = 1;
	for (int i = str.size() - 1; i >= firstInd; --i) {
		res = res + (str[i] - '0') * j;
		j *= 2;
	}
	return res;
}

int main() {
	int n;
	cin >> n;
	vector<string> numstr;

//	int n = 5;
//	vector<string> numstr = {"10","42","170","85","341"};
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		numstr.push_back(getBiStringFromDec(x));
	}

	// trans to
	for (auto &str:numstr) {
		cout << getTrans(str) << " ";
	}

	return 0;
}
//5
//10 42 170 85 341

//5
//20 30 40 50 60