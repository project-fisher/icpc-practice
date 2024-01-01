// 0.240s/4177
#include <bits/stdc++.h>
#define lu unsigned long

using namespace std;

class UnionFind {
private:
	vector<int> p, rank;
public:
	UnionFind(int n) {
		p.resize(n); iota(p.begin(), p.end(), 0);
		rank.assign(n, 0);
	}

	int f(int i) {
		return p[i] == i ? i : (p[i] = f(p[i]));
	}

	bool u(int i, int j) {
		int x = f(i), y = f(j);
		if (x == y) return 0;
		if (rank[x] > rank[y]) swap(x, y);
		p[x] = y;
		if (rank[x] == rank[y]) ++rank[y];
		return 1;
	}
};

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int s, n; scanf("%d%d", &s, &n);
		set<pair<lu, pair<int, int>>> edges;
		vector<pair<lu, lu>> ps;
		for (int i = 0; i < n; ++i) {
			lu x, y; scanf("%lu%lu", &x, &y);
			for (int j = 0; j < i; ++j) {
				lu d1 = x > ps[j].first ? x - ps[j].first : ps[j].first - x;
				lu d2 = y > ps[j].second ? y - ps[j].second : ps[j].second - y;
				lu d = d1*d1 + d2*d2;
				edges.insert({d, {i, j}});
			}
			ps.push_back({x, y});
		}
		UnionFind uf(n);
		int g = s == 1 ? n : n - s;
		lu cost = 0;
		for (auto i : edges) if (uf.u(i.second.first, i.second.second)) {
			cost = max(cost, i.first);
			if (!(--g)) break;
		}
		printf("%.2Lf\n", sqrt(1.0L*cost));

	}
	return 0;
}
