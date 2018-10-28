#include <bits/stdc++.h>

using ll = long long;

using namespace std;

const string o = "one";
const string tw = "two";

int main() {   
//  	freopen("inp.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
	int t; string s;
	cin >> t;
	while(t--) {
		cin >> s;
		if(s.length() == 5)
			cout << "3" << endl;
		else {
			int c1 = 0;
			for(int i = 0; i < 3; i++) {
				if(s[i] == o[i])
					c1++;
			}
			if(c1 >= 2)
				cout << 1 <<endl;
			else 
				cout << 2 <<endl;	
		}
	}	
}
