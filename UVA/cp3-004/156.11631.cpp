// 0.940s/5144
#include <bits/stdc++.h>
#define lu unsigned long

using namespace std;

class DS {
private:
	vector<lu> p, rank, ss;
public:
	DS(lu n) {
		p.resize(n); iota(p.begin(), p.end(), 0);
		rank.assign(n, 0);
	}

	lu finds(lu i) {
		return p[i] == i ? i : (p[i] = finds(p[i]));
	}

	bool unions(lu i, lu j) {
		lu x = finds(i), y = finds(j);
		if (x == y) return 0;
		if (rank[x] > rank[y]) swap(x, y);
		p[x] = y;
		if (rank[x] == rank[y]) ++rank[y];
		return 1;
	}

};

int main() {
	lu n, k;
	while (scanf("%ld%ld", &n, &k) && (n || k)) {
		lu total = 0;
		set<pair<lu, pair<lu, lu>>> el;
		for (lu i = 0; i < k; ++i) {
			lu v, u, d; scanf("%ld%ld%ld", &v, &u, &d);
			total += d;
			el.insert({d, {v, u}});
		}
		lu cost = 0;
		DS s(n);
		for (auto &i : el) if (s.unions(i.second.first, i.second.second)) cost += i.first;
		printf("%lu\n", total - cost);
	}
	return 0;
}

