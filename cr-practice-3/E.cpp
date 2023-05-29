#include <bits/stdc++.h>
#define ull unsigned long long
#define ul unsigned long
#define ui unsigned int

using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<map<ull, ull>> a(n);
	map<ull, pair<ull, ull>> ps;
	for (int i = 0; i < n; ++i) {
		int m; scanf("%d", &m);
		for (int j = 0; j < m; ++j) {
			ull p, e; scanf("%llu%llu", &p, &e);
			a[i][p] = e;
			if (!ps.count(p)) ps[p] = {e, 0};
			else if (ps[p].first <= e) ps[p] = {e, ps[p].first};
		}
	}
	map<ull, int> prime_id;
	int id = 0;
	for (auto &i : ps) {
		prime_id[i.first] = id;
		if (i.second.first == i.second.second) ++i.second.first;
		++id;
	}
	set<ull> hashes;
	hash<bitset</*10*/200003>> h;
	for (auto &i : a) {
		bitset<200003/*10*/> ans = 0;
		for (auto &j : i) if (j.second == ps[j.first].first) ans.set(prime_id[j.first]);
		// cout << ans << '\n';
		hashes.insert((ull)h(ans));
	}
	printf("%lu\n", hashes.size());		
	return 0;
}
