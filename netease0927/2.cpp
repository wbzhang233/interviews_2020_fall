//
// Created by wbzhang on 2020/9/27.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

const int maxN = 1e5 + 100;
const int maxNF = 1e6 + 100;

enum OpType {
	open,
	dup,
	dup2,
	close,
	query
};

OpType getOpType(string &command) {
	string com;
	for (auto ele:command) {
		if (ele == ' ') break;
		else com.push_back(ele);
	}
	if (com == "open") return open;
	if (com == "dup") return dup;
	if (com == "dup2") return dup2;
	if (com == "close") return close;
	if (com == "query") return query;
}

void splitCommmand(string &command, OpType &op, int &fd, int &new_fd, string &filename) {
	// 先划分操作符
	string com;
	int i = 0;
	for (auto ele:command) {
		++i;
		if (ele == ' ') break;
		else com.push_back(ele);
	}
	if (com == "open") op = open;
	if (com == "dup") op = dup;
	if (com == "dup2") op = dup2;
	if (com == "close") op = close;
	if (com == "query") op = query;

	// 则为文件名
	if (isalpha(command[command.length() - 1])) {
		while (i <= command.length()) filename.push_back(command[i]);
	} else if (op == dup2) {
		fd = 0, new_fd = 0;
		bool fdF = true;
		while (i <= command.length()) {
			if (isdigit(command[i]) && fdF) {
				fd = fd * 10 + (command[i] - '0');
				fdF = false;
			} else if (isdigit(command[i]) && !fdF) {
				new_fd = new_fd * 10 + (command[i] - '0');
			} else if (command[i] == ' ') continue;
		}
	} else {
		fd = 0;
		while (i <= command.length()) {
			fd = fd * 10 + (command[i] - '0');
		}
	}
}

class Solution {
private:
	int currId = 0;
	map<string, int> file2fds; // 文件名对应的描述符
	map<int, string> fd2file; // 描述符指向的文件名
	multimap<int, string> filelists; //文件描述符->文件名列表

public:

	int open(string &filename) {
		file2fds[filename] = currId;
		fd2file[currId] = filename;
		filelists.insert(make_pair(currId, filename));
		currId++;
		return currId - 1;
	}

	int dup(int &fd) {
		fd2file[currId] = fd2file[fd];
		filelists.insert(make_pair(currId, fd2file[fd]));
		currId++;
		return currId - 1;
	}

	void dup2(int &fd, int &new_fd) {
		fd2file[new_fd] = fd2file[fd];
	}

	void close(int &fd) {
		fd2file.erase(fd);
	}

	string query(int &fd) {
		return fd2file[fd];
	}
};

int main() {
	int T;
	cin >> T;
	string ns;
	int N;
	while (T > 0) {
		cin >> N;

		Solution solu;
		string command;
		char x;

		OpType op;
		string filename;
		int fd, new_fd;

		while (N > 0) {
			// 读取每一行的函数调用
//			cin>>command;

			getline(cin, command);
			// 解读操作
//			splitCommmand(command,op,fd,new_fd,filename);
			// 操作
			switch (op) {
				case open: {
					cout << solu.open(filename) << endl;
					break;
				}
				case dup: {
					cout << solu.dup(fd) << endl;
					break;
				}
				case dup2: {
					solu.dup2(fd, new_fd);
					break;
				}
				case close: {
					solu.close(fd);
					break;
				}
				case query: {
					cout << solu.query(fd) << endl;
					break;
				}
			}

			--N;
		}

		--T;
	}

	return 0;
}

//2
//10
//open libc.so