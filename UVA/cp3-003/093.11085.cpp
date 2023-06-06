// 2.750s/3636
// Good lord what is happening in here
// I decided to check diagonals at each proper leaf???
#include <bits/stdc++.h>

using namespace std;

int c[8];

int backtrack(int n, int cng, int msk) {
	if (n == 8) {
		for (int i = 0; i < 7; ++i) {
			int h = c[i] + 1;
			for (int j = i + 1; j < 8 && h <= 8; ++j, ++h) if (c[j] == h) return 7;
			h = c[i] - 1;
			for (int j = i + 1; j < 8 && h > 0; ++j, --h) if (c[j] == h) return 7;
		}
		return cng;
	}
	int best = 7;
	for (int i = 1; i <= 8; ++i) if (!(msk&(1 << i))) {
		int pc = c[n];
		cng += i != c[n];
		c[n] = i;
		best = min(best, backtrack(n + 1, cng, msk|(1 << i)));
		c[n] = pc;
		cng -= i != c[n];
	}
	return best;
}


int main() {
	int id = 1;
	while (scanf("%d%d%d%d%d%d%d%d", &c[0], &c[1], &c[2], &c[3], &c[4], &c[5], &c[6], &c[7]) == 8) {
		printf("Case %d: %d\n", id++, backtrack(0, 0, 0));
	}
	return 0;
}
