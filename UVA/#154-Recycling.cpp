    #include <bits/stdc++.h>

    using namespace std;


    void fopen() {
        freopen("C:\\Users\\Mohamed\\CLionProjects\\Codeforces\\in.txt", "r", stdin);
        freopen("C:\\Users\\Mohamed\\CLionProjects\\Codeforces\\out.txt", "w", stdout);
    }

    void dance() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }


    map<char, int> colors;

    struct City {
        char b[5];
        int count;
    } Cities[110];

    int main() {
        colors['r'] = 0;
        colors['o'] = 1;
        colors['y'] = 2;
        colors['g'] = 3;
        colors['b'] = 4;
        string inp;
        while(cin >> inp && inp != "#") {
            int n = 0, mnidx, mn;
            do {
                int j = 0;
                for(int i = 0; i < 5; i++, j += 4) {
                    Cities[n].b[colors[inp[j]]] = inp[j + 2];
                }
                Cities[n].count = 0;
                n++;
                cin >> inp;
            }while(inp[0] != 'e');
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    for(int k = 0; k < 5; k++) {
                        if(Cities[i].b[k] != Cities[j].b[k]) Cities[i].count++;
                    }
                }
            }
            if(n >= 1)
                mnidx = 1, mn = Cities[0].count;
            for(int i = 0; i < n; i++) {
                if(Cities[i].count < mn) {
                    mnidx = i + 1;
                    mn = Cities[i].count;
                }
            }
            cout << mnidx << endl;
        }
    }
