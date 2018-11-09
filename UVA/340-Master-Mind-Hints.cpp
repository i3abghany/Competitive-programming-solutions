#include <bits/stdc++.h>

using namespace std;


int main() {
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
#endif

    int tt, c = 0;
    while(cin >> tt && tt) {
        vector<int> p(tt);
        for(int i = 0; i < tt; i++)
            cin >> p[i];
        cout << "Game " << ++c << ":" << endl;
        while(true) {
            int strong = 0, weak = 0, zeros = 0;
            vector<int> sol(tt);
            vector<bool> visi(tt, false), visj(tt, false);
            for(int i = 0; i < tt; i++) {
                cin >> sol[i];
                if(sol[i] == 0)
                    ++zeros;
            }
            if(zeros == tt)
                break;
            for(int i = 0; i < tt; i++) {
                if (sol[i] == p[i]) {
                    ++strong;
                    visi[i] = true, visj[i] = 1;
                }
            }
            for(int i = 0; i < tt; i++) {
                for(int j = 0; j < tt; j++) {
                    if(visi[i] || visj[j]) continue;
                    if(p[i] == sol[j]) {
                        ++weak;
                        visi[i] = true, visj[j] = true;
                    }
                }
            }
            cout << "    (" << strong << "," << weak << ")" << endl;
         }
    }
}
