
#include <bits/stdc++.h>

using namespace std;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int step, mod;
  while(cin >> step >> mod) {
    set<int> st;
    int curr = 0;
    do {
      curr += step;
      curr %= mod;
      if(curr != 0) st.insert(curr);
    } while(curr != 0);
    cout << setw(10) << step << setw(10) << mod << "    " << ((st.size() == mod - 1) ? "Good Choice\n" : "Bad Choice\n");
    cout << endl;
    }
}
