#include <bits/stdc++.h>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <filesystem>
#include <string>

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
		filename = entry.path()
	}
}
