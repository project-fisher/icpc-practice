#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	cin >> a >> b;
	while (a || b) {
		bool data[a + 2][b + 2];
		for (auto &i : data) for (auto &j : i) j = 1;
		int c[6] = {0};
		for (int i = 1; i < a + 1; i++) {
			char t;
			for (int j = 1; j < b + 1; j++) {
				cin >> t;
				data[i][j] = t != '0';
				c[0] += t == '0';
			}
		}
		int mdata[a + 2][b + 2];
		for (auto &i : mdata) for (auto &j : i) j = 0;
		int x = 1, y = a;
		char vx = 0, vy = 0;
		char d = 0;
		do {
			d -= 2;
			do {
				d++;
				d &= 3;
				vx = (~d)&1;
				vx = d&2 ? -vx : vx;
				vy = d&1;
				vy = d&2 ? vy : -vy;
			} while (data[y + vy][x + vx]);
			y += vy;
			x += vx;
			if (mdata[y][x] < 5) {
				c[mdata[y][x]]--;
				c[++mdata[y][x]]++;
			}
		} while (x != 1 || y != a);
		for (int i = 0; i < 5; i++) cout << right << setw(3) << fixed << c[i];
		cout << '\n';
		cin >> a >> b;
	}
}
