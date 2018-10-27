#include <bits/stdc++.h>

using ll = long long;

using namespace std;

int a[1005];

int main() {   
  	//freopen("inp.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, res = 0, lin = 0;
    while(cin >> t && t) {
    	for(int i = 0; i < t; i++) {
    		cin >> a[i];
    		if(a[i] > 0) res++;
    		else res--;
    	}
    	cout << "Case " << ++lin << ": " << res <<endl;
    	res = 0;
    }
}
