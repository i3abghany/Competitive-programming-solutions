#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	vector<string> kp;
	int t = 0;
	while(getline(cin, s) && s != "") {
		for(int i = 0; i < s.length(); i++) {
			if(s[i] == '\"' && t == 0) {
				s[i] = '`';
				s.insert(i, "`");
				t = 1;
			} else if(s[i] == '\"' && t == 1) {
				s[i] = '\'';
				s.insert(i, "\'");
				t = 0;
			}			
		}
		kp.push_back(s);
	}
	for(auto x : kp) {
		cout << x << endl;
	}
}
