// 0.000s/1683
#include <bits/stdc++.h>
#define llu unsigned long long

using namespace std;

class UnionFind {
private: 
	vector<int> p, rank;
public:
	UnionFind(int n) {
		p.resize(n); iota(p.begin(), p.end(), 0);
		rank.assign(n, 0);
	}

	int find(int i) {
		return p[i] == i ? i : (p[i] = find(p[i]));
	}

	bool unions(int i, int j) {
		int x = find(i), y = find(j);
		if (x == y) return 0;
		if (rank[x] > rank[y]) swap(x, y);
		p[x] = y;
		if (rank[x] == rank[y]) ++rank[y];
		return 1;
	}
};

int main() {
	int n, k;
	while (scanf("%d%d", &n, &k) && (n || k)) {
		set<pair<llu, pair<int, int>>> el;
		for (int i = 0; i < k; ++i) {
			int v, u; llu w; scanf("%d%d%llu", &v, &u, &w);
			if (v > u) swap(v, u);
			el.insert({w, {v, u}});
		}
		UnionFind uf(n);
		multiset<llu> edges;
		for (auto &i : el) if (!uf.unions(i.second.first, i.second.second)) edges.insert(i.first);
		if (edges.empty()) puts("forest");
		else {
			bool f = 1;
			for (auto i : edges) {
				if (f) f = 0;
				else printf(" ");
				printf("%llu", i);
			}
			puts("");
		}
	}
	return 0;
}
