// 0.000s/718(1)
#include <bits/stdc++.h>

using namespace std;

const long INF = LONG_MAX - INT_MAX;

struct edge {
	int a, b; long c;
};

int main() {
	int n;
	while (scanf("%d", &n) && n != -1) {
		vector<long> c(n);
		vector<edge> es;
		for (int i = 0; i < n; ++i) {
			long cc; int k; scanf("%ld%d", &cc, &k);
			c[i] = cc;
			for (int j = 0; j < k; ++j) {
				int f; scanf("%d", &f); --f;
				es.push_back({i, f, 0});
			}
		}
		for (auto &e : es) e.c = -c[e.b];
		vector<long> d(n, INF); d[0] = -100;
		for (int i = 1; i < n; ++i) for (auto &e : es) if (d[e.a] < INF && d[e.b] > max(-INF, d[e.a] + e.c) && d[e.a] + e.c < 0) d[e.b] = max(-INF, d[e.a] + e.c);
		// due to our limiting the answer if the energy level ever gets below zero, we have to propagate the negative cycles
		for (int i = 1; i < n; ++i) for (auto &e : es) if (d[e.a] < INF && d[e.b] > d[e.a] + e.c && d[e.a] + e.c < 0) d[e.b] = -INF;
		if (d[n - 1] >= 0) puts("hopeless");
		else puts("winnable");
	}
	return 0;
}
		

