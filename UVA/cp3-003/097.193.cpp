// 0.000s/1210
#include <bits/stdc++.h>

using namespace std;

int n, mx, cnt;
vector<bitset<100>> g;
bitset<100> current, best;

void backtrack(int i) {
	if (i == n) {
		if (cnt > mx) {
			mx = cnt;
			best = current;
		}
		return;
	}
	if ((current&g[i]).none()) {
		current.set(i);
		++cnt;
		backtrack(i + 1);
		--cnt;
		current.reset(i);
	}		
	backtrack(i + 1);
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int k; scanf("%d%d", &n, &k);
		g.assign(n, 0);
		for (int i = 0; i < k; ++i) {
			int a, b; scanf("%d%d", &a, &b); --a; --b;
			g[a].set(b);
			g[b].set(a);
		}
		mx = 0;
		cnt = 0;
		backtrack(0);
		printf("%d\n", mx);
		bool f = 0;
		for (int i = 0; i < n; ++i) if (best[i]) {
			if (f) printf(" ");
			f = 1;
			printf("%d", i + 1);
		}
		printf("\n");
	}
	return 0;
}

