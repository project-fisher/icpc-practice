// 0.000s/692
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, v, y;
	bitset<96> g;
	cin >> n;
	while (n--) {
		bitset<96> rows[5] = {0};
		bitset<96> columns[5] = {0};
		bitset<96> diagonals[2] = {0};
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				j += i == j && i == 2;
				cin >> v;
				rows[i].set(v, 1);
				columns[j].set(v, 1);
				if (i == j) diagonals[0].set(v, 1);
				if (i == 4 - j) diagonals[1].set(v, 1);
			}
		}
		g = 0;
		y = 0;
		int i = 0;
		for (; i < 75 && !y; i++) {
			cin >> v;
			g.set(v, 1);
			for (int j = 0; j < 5 && !y; j++)
				y |= (rows[j] & g) == rows[j] || (columns[j] & g) == columns[j];
			for (int j = 0; j < 2 && !y; j++)
				y |= (diagonals[j] & g) == diagonals[j];
		}
		cout << "BINGO after " << i << " numbers announced" << '\n';
		for (; i < 75; i++) cin >> v;
	}
}
