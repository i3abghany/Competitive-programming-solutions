#include <bits/stdc++.h>

using namespace std;

int x, y; char dir;
int n, m;
bool flag = false;
vector<vector<bool>> scent;

void change_dir(char c) {
	if(dir == 'N') {
		dir = ((c == 'R') ? 'E' : 'W');
	}
	else if(dir == 'S') {
		dir = ((c == 'R') ? 'W' : 'E');
	}
	else if(dir == 'W') {
			dir = ((c == 'R') ? 'N' : 'S');
	}
	else if(dir == 'E') {
		dir = ((c == 'R') ? 'S' : 'N');
	}
}

int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
char directions[] = {'N', 'S', 'E', 'W'};

void move_forward() {
	int newx = x,  newy = y;

	int idx = 0;
	for(int i = 0; i < 4; i++) {
		if(directions[i] == dir) {
			idx = i;
		}
	}

	newx += dx[idx], newy += dy[idx];
	bool not_valid = (newx > n || newx < 0 || newy > m || newy < 0);
	if(not_valid && !scent[y][x]) {
		flag = true;
		scent[y][x] = true;
		return;
	}
	if(scent[y][x] && not_valid) return;
	x = newx, y = newy;
}

int main() {
	cin >> n >> m;
	scent.assign(m + 1, vector<bool>(n + 1, false));
	while(cin >> x >> y >> dir) {
		flag = false;
		string s;
		cin >> s;
		for(const char c : s) {
			if(c == 'R' || c == 'L') change_dir(c);
			else move_forward();
			if(flag) {
				cout << x << ' ' << y << ' ' << dir << " LOST\n";
				goto zz;
			}
		}
		cout << x << ' ' << y << ' ' << dir << '\n';
		zz: ;
	}


}
