#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int maxN = (int)1e5 + 2;
const double eps =  0.0000001;
 
int main() {
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    double h, u, d, f;
    while(cin >> h >> u >> d >> f && (h != 0)) {
        f = (f * u) / 100.0;
        double currHeight = 0.0;
        int days = 0;
        while(true) {
            ++days;
            if(u >= 0) currHeight += u;
            u -= f;
            if(currHeight > h) break;
            currHeight -= d;
            if(currHeight < 0) break;
//            cout << "CurrHeight " << currHeight << "Curr percentage " << (u * per * days) << endl;
        }
        if(currHeight <= 0) cout << "failure on day ";
        else cout << "success on day ";
        cout << days << endl ;
    }
}