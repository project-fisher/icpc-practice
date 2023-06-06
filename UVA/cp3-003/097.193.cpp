#include <bits/stdc++.h>

using namespace std;

class UF {
	private: vector<int> p, rank;
	public:
	UF(int n) {
		rank.assign(n, 0);
		p.resize(n);
		iota(p.begin(), p.end(), 0);
	}
	int find(int i) {return p[i] == i ? i : (p[i] = find(p[i]));}
	void us(int i, int j) {
		i = find(i); j = find(j);
		if (i != j) {
			if (rank[i] > rank[j]) p[j] = i;
			else {
				p[i] = j;
				if (rank[i] == rank[j]) ++rank[j];
			}
		}
	}
};

int n, mx, cnt;
vector<vector<int>> g;
bitset<100> sol;
bitset<100> cur;
bitset<100> visited;

void backtrack(int i) {
	visited.set(i);
	bool can_be_black = 1;
	for (int j : g[i]) can_be_black &= !cur[j];
	cur[i] = can_be_black;
	cnt += can_be_black;
	if (cnt > mx) {
		mx = cnt;
		sol = cur;
	}
	for (int z = 0; z < 1 + can_be_black; ++z) {
		for (int j : g[i]) if (!visited[j]) backtrack(j);
		cur[i] = 0;
		cnt -= can_be_black;
	}
	cnt += can_be_black;
	visited.reset(i);
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int k; scanf("%d%d", &n, &k);
		g.resize(n);
		UF c(n);
		for (int i = 0; i < k; ++i) {
			int a, b; scanf("%d%d", &a, &b); --a; --b;
			c.us(a, b);
			g[a].emplace_back(b);
			g[b].emplace_back(a);
		}
		set<int> comp;
		for (int i = 0; i < n; ++i) comp.insert(c.find(i));
		bitset<100> s;
		int best = 0;
		for (int i : comp) {
			cout << i << '\n';
			sol.reset();
			cur.reset();
			visited.reset();
			mx = 0;
			cnt = 0;
			backtrack(i);
			best += mx;
			s |= sol;
		}
		printf("%d\n", best);
		bool nf = 0;
		for (int i = 0; i < 100; ++i) {
			if (s[i]) {
				if (nf) printf(" ");
				nf = 1;
				printf("%d", i + 1);
			}
		}
		printf("\n");
	}
	return 0;
}

