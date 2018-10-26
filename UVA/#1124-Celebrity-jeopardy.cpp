#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	vector<string> kp;
	int t = 0;
	while(getline(cin, s) && s != "") {
	kp.push_back(s);
	}
	for(auto x : kp) {
		cout << x << endl;
	}
}
