#include <bits/stdc++.h>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>

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

