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
	cout << " Current path: " << currentPath << endl;
	for (const auto & entry : filesystem::directory_iterator(currentPath)) {
		string filename = entry.path();
		stringstream test(filename);
		stringstream testT(filename);
		string segment;
		string segmentT;
		vector<string> segList;
		vector<string> lastList;
		while (getline(test, segment, '.')) {
			segList.push_back(segment);
		}
		while (getline(testT, segmentT, '/')) {
			lastList.push_back(segmentT);
		}

		
		stringstream folderTest(currentPath);
		string folderSegment;
		vector<string> folderList;
		while (getline(folderTest, folderSegment, '/')) {
			folderList.push_back(folderSegment);
		}

		if (segList.size() == 1)
			continue;
		string a = segList.back();
		const char *extension = a.c_str();
		createDir(extension);

		//cout << "FILE PATH: " << filename << endl;
		//cout << "Last path: " << currentPath + "/" + extension + "/" + lastList.back() << endl;
		filesystem::rename(filename, currentPath + "/" + extension + "/" + lastList.back());
	}
	cout << "FINISHED WORK" << endl;
}
