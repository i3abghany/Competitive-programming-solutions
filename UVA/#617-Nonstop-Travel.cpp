#include <bits/stdc++.h>

using namespace std;

void dance() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    int n, tc = 1;
    while(cin >> n && n != -1) {
        map<int, bool> mp;
        vector<pair<pair<double, double>, pair<double, double>>> traffic;
        double L, G, Y, R;
        for (int i = 0; i < n; i++) {
            cin >> L >> G >> Y >> R;
            traffic.push_back({{L, G},
                               {Y, R}});
        }
        for (int speed = 30; speed <= 60; speed++) {
            bool passes = 1;
            for (auto span : traffic) {
                double daur = span.first.first * 1.0 / speed * 3600.0;
                double traffic_daur = span.first.second + span.second.first + span.second.second;
                passes &= (fmod(daur, traffic_daur) <= (span.first.second + span.second.first) ||
                           fabs(fmod(daur, traffic_daur) - span.first.second + span.second.first) < 1e-7);
            }
            if (passes) mp[speed] = 1;
        }
        printf("Case %d:", tc++);

        if (mp.size() == 0) {
            puts(" No acceptable speeds.");
        } else {
            bool f = 0;
            int cnt = 0;
            for (int i = 30; i <= 60;) {
                if (mp[i]) {
                    f = 1;
                    int low = i, high = i;
                    while (mp[i] && i <= 60) high = i++;
                    if (cnt++)printf(",");
                    if (high == low)printf(" %d", low);
                    else printf(" %d-%d", low, high);
                } else ++i;
            }
            cout << endl;
        }
    }
}
