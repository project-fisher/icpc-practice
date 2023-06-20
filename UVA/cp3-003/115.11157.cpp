// 0.000s/911(1)
// Didn't consider the fact that we have to consider the interval between normal stones that contain bad stones.
#include <bits/stdc++.h>
#define llu unsigned long long
using namespace std;

int main() {
	int t; scanf("%d", &t);
	for (int T = 1; T <= t; ++T) {
		int n; scanf("%d", &n);
		llu d; scanf("%llu", &d);
		while (getchar() != '\n');
		char c;
		vector<pair<llu, bool>> stones {{0, 1}, {d, 1}};
		for (int i = 0; i < n; ++i) {
			while ((c = getchar()) != 'S' && c != 'B');
			getchar();
			llu p; scanf("%llu", &p);
			if (c == 'B') stones.emplace_back(make_pair(p, 1));
			else stones.emplace_back(make_pair(p, 0));
		}
		sort(stones.begin(), stones.end());
		llu mx = 0;
		for (int i = 0; i < stones.size() - 1; ++i) {
			if (stones[i + 1].second && stones[i].second) mx = max(mx, stones[i + 1].first - stones[i].first);
			else if (!stones[i + 1].second) mx = max(mx, stones[i + 2].first - stones[i].first);
		}
		printf("Case %d: %llu\n", T, mx);
	}
	return 0;
}


