// 0.000s/836(2)
#include <bits/stdc++.h>

using namespace std;

const long INF = LONG_MAX - INT_MAX;

struct edge {
	int a, b; long c;
};

int main() {
	int n;
	int t = 1;
	while (scanf("%d", &n) == 1) {
		vector<int> c(n); for (int i = 0; i < n; ++i) scanf("%d", &c[i]);
		int m; scanf("%d", &m);
		vector<edge> es(m);
		for (int i = 0; i < m; ++i) {
			scanf("%d%d", &es[i].a, &es[i].b);
			es[i].c = pow(c[--es[i].b] - c[--es[i].a], 3);
		}
		vector<long> d(n, INF); d[0] = 0;
		for (int i = 1; i < n; ++i) for (auto e : es) if (d[e.a] < INF && d[e.b] > d[e.a] + e.c) d[e.b] = max(-INF, d[e.a] + e.c);
		// Remember: this marks all of the nodes affected by a negative cycle.
		for (auto e : es) if (d[e.a] < INF && d[e.b] > d[e.a] + e.c) d[e.b] = -INF;
		int q; scanf("%d", &q);
		printf("Set #%d\n", t++);
		while (q--) {
			int t; scanf("%d", &t);
			long dd = d[--t];
			if (dd < 3 || dd == INF) puts("?");
			else printf("%ld\n", dd);
		}
	}
	return 0;
}

