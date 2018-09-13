#include <bits/stdc++.h>

using namespace std;

long long C[100][100];

void nCr(int n, int r)
{
    for (int i=0; i<=n; i++)
    {
        for (int k=0; k<=r && k<=i; k++)
            if (k==0 || k==i)
                C[i][k] = 1;
            else
                C[i][k] = (C[i-1][k-1] + C[i-1][k]);
    }
}
 
int main() {
	long long n, m, t;
	cin >> n >> m >> t;
	long long int res = 0;
	nCr(50, 50);
	for(int i = 4; i <=n; i++) {
		if(t - i >= 1) {
			res += C[n][i] * C[m][t-i];
		}
	}
	cout << res;
}
