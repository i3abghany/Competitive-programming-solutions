#include <bits/stdc++.h>

using namespace std;

void rshift( char *s ){
    int n = strlen( s);
    s[ n + 1] = 0;
    while( n ){
       s[ n ] = s[ n-1 ];
       n--;
    } 
}

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