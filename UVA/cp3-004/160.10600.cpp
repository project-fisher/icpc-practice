// 0.000s/1405(1)
#include <bits/stdc++.h>

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
		int n, k; scanf("%d%d", &n, &k);
		set<pair<int, pair<int, int>>> e;
		for (int i = 0; i < k; ++i) {
			int u, v, c; scanf("%d%d%d", &u, &v, &c); --u; --v;
			if (u > v) swap(u, v);
			e.insert({c, {u, v}});
		}
		UnionFind uf(n);
		int c1 = 0, pos = 0;
		vector<int> ans;
		for (auto &i : e) {
			if (uf.u(i.second.first, i.second.second)) {
				ans.push_back(pos);
				c1 += i.first;
			}
			++pos;
		}
		int c2 = INT_MAX;
		for (auto &j : ans) {
			uf = UnionFind(n);
			int tpos = 0;
			int c = 0;
			for (auto &i : e) {
				if (tpos != j && uf.u(i.second.first, i.second.second)) c += i.first;
				++tpos;
			}
			if (c >= c1) c2 = min(c2, c);
		}
		if (c2 == INT_MAX) c2 = c1;
		printf("%d %d\n", c1, c2);
		
	}
	return 0;
}
