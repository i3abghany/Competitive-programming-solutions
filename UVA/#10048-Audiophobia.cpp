#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int OO = 2147483647;
int F[N][N];

void init(int c) {
	for(int i = 0; i <= c; i++) {
		for(int j = 0; j < c; j++) {
		//	if(i == j) F[i][j] = 0;
			F[i][j] = F[j][i] = OO;
		}
	}
}

int main() {
	int C, S, Q, cases = 1;
	while(scanf("%d %d %d", &C, &S, &Q) && (C || S || Q)) {
		init(C);
		int a, b, c;
		for(int i = 0; i < S; i++) {
			cin >> a >> b >> c;
			F[a][b] = F[b][a] = c;
		//	F[b][a] = F[a][b];
		}
		for(int k = 1; k <= C; k++)
			for(int i = 1; i <= C; i++)
				for(int j = 1; j <= C; j++)
					F[i][j] = F[j][i] = min(F[i][j], max(F[i][k], F[k][j]));
		if(cases > 1) cout << endl;
		cout << "Case #" << cases++ << endl;
		while(Q--) {
			int x, y;
			cin >> x >> y;
			if(F[x][y] == OO) cout << "no path" << endl;
			else cout << F[x][y] << endl;
		}
	}
}
