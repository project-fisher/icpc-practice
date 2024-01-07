// 0.000s/1429
#include <bits/stdc++.h>
#define iii pair<int, pair<int, int>>

using namespace std;

bool gln(int &v) {
	char c;
	while ((c = getchar()) != '\n' && c != -1 && (c < '0' || c > '9'));
	if (c == '\n' || c == -1) return 0;
	v = c - '0';
	while ((c = getchar()) && c >= '0' && c <= '9') v = v*10 + c - '0';
	ungetc(c, stdin);
	return 1;
}

int main() {
	int n, k, e[5];
	while (scanf("%d%d", &n, &k) == 2) {
		int floors[100] = {0};
		vector<set<int>> elevators(n);
		for (int i = 0; i < n; ++i) scanf("%d", &e[i]);
		while (getchar() != '\n');
		for (int i = 0; i < n; ++i) {
			int x;
			while (gln(x)) {
				elevators[i].insert(x);
				floors[x] |= 1 << i;
			}
		}
		vector<vector<int>> dist(n, vector<int>(100, INT_MAX));
		set<iii> s;
		for (int i = 0; i < n; ++i) if (floors[0]&(1 << i)) {
			s.insert({0, {i, 0}});
			dist[i][0] = 0;
		}
		while (!s.empty()) {
			iii f = *s.begin(); s.erase(s.begin());
			int el = f.second.first, fl = f.second.second;
			if (f.first > dist[el][fl] || fl == k) continue;
			for (int i = 0; i < n; ++i) {
				if (i == el) continue;
				if (elevators[i].count(fl) && dist[el][fl] + 60 < dist[i][fl]) {
					dist[i][fl] =  dist[el][fl] + 60;
					s.insert({dist[i][fl], {i, fl}});
				}
			}
			auto it = elevators[el].find(fl);
			auto it2 = elevators[el].begin();
			auto it3 = elevators[el].end();
			if (it == it3) continue;
			if (it != it2 && dist[el][fl] + e[el]*(fl - (*(--it))) < dist[el][*it]) {
				dist[el][*it] = dist[el][fl] + e[el]*(fl - (*it));
				s.insert({dist[el][*it], {el, *it}});
			}
			it = elevators[el].find(fl);
			if (it != --it3 && dist[el][fl] - e[el]*(fl - (*(++it))) < dist[el][*it]) {
				dist[el][*it] = dist[el][fl] - e[el]*(fl - (*it));
				s.insert({dist[el][*it], {el, *it}});
			}
		}
		int mn = INT_MAX;
		for (int i = 0; i < n; ++i) mn = min(mn, dist[i][k]);
		if (mn == INT_MAX) puts("IMPOSSIBLE");
		else printf("%d\n", mn);
	}
	return 0;
}


