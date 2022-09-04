#include <bits/stdc++.h>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <filesystem>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int createDir(const char *a) {
	if (mkdir(a, 0777) == -1) {
		cout << "Error : " << strerror(errno) << endl;
		return -1;
	} else {
		cout << "Directory created!";
		return 0;
	}
}

int main() {
	string currentPath = filesystem::current_path();

	for (const auto & entry : filesystem::directory_iterator(currentPath)) {
		string filename = entry.path();
		stringstream test(filename);
		string segment;
		vector<string> segList;
		while (getline(test, segment, '.')) {
			segList.push_back(segment);
		}
		string a = segList.back();
		const char *extension = a.c_str();
		createDir(extension);
	}
}
