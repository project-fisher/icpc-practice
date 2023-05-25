// 0.030s/531
#include <bits/stdc++.h>
#define vi vector<int>

using namespace std;

class UnionFind {
private: vi p, rank;
public:
	UnionFind(int N) {
		rank.assign(N, 0);
		p.resize(N);
		iota(p.begin(), p.end(), 0);
	}

	int findSet(int i) {
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}

	bool isSameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}

	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) {
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) p[y] = x;
			else {
				p[x] = y;
				if (rank[x] == rank[y]) ++rank[y];
			}
		}
	}
};

int main() {
	int t; scanf("%d", &t);
	for (int z = 0; z < t; ++z) {
		if (z) printf("\n");
		int n; scanf("%d", &n);
		UnionFind u(n + 1);
		char c;
		getchar();
		int s = 0, tot = 0;
		while ((c = getchar()) != '\n' && c != -1) {
			int n1, n2; scanf("%d%d", &n1, &n2);
			if (c == 'c') u.unionSet(n1, n2);
			else {
				++tot;
				s += u.isSameSet(n1, n2);
			}
			getchar();
		}
		printf("%d,%d\n", s, tot - s);
	}
	return 0;
}
