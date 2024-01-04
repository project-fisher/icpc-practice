// 0.000s/352
#include <bits/stdc++.h>
#define u unsigned int

using namespace std;

u cost[10000], o[10], q[10001], qs, qe;
bitset<10000> sq;


int main() {
	u s, e, n;
	int t = 1;
	while (scanf("%u%u%u", &s, &e, &n) && n) {
		memset(cost, 255, sizeof(cost));
		for (u i = 0; i < n; ++i) scanf("%u", &o[i]);
		cost[s] = 0;
		qs = 0; qe = 1; q[0] = s;
		sq.reset(); sq.set(s);
		u ans = UINT_MAX;
		while (qs != qe) {
			u c = q[qs++];
			for (u i = 0; i < n; ++i) {
				u a = (c + o[i])%10000;
				if (a == e) {
					ans = cost[c] + 1;
					qs = qe;
					break;
				}
				if (!sq[a]) {
					cost[a] = cost[c] + 1;
					sq.set(a);
					q[qe++] = a;
				}
			}
		}
		printf("Case %d: ", t++);
		if (ans == UINT_MAX) puts("Permanently Locked");
		else printf("%d\n", ans);
	}
	return 0;
}
