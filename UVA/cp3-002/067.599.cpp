// 0.220s/1139
#include <bits/stdc++.h>

#define vi vector<int>

using namespace std;

class UnionFind {
	private: vi p, rank; 
	public:
	
	UnionFind(int N) {
		rank.assign(N, 0);
		p.assign(N, 0);
		for (int i = 0; i < N; i++) p[i] = i;
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
				if (rank[x] == rank[y]) rank[y]++;
			}
		}
	}
};

int main() {
	int t; scanf("%d", &t);
	getchar();
	while (t--) {
		set<char> inc;
		UnionFind u(26);
		while (getchar() == '(') {
			char A = getchar() - 'A', B; getchar(); B = getchar() - 'A'; getchar(); getchar();
			inc.insert(A); inc.insert(B);
			u.unionSet(A, B);
		}
		while (getchar() == '*');
		char A = ',';
		int acorns = 0;
		while (A == ',') {
			acorns += 1 - inc.count(A = getchar() - 'A');
			inc.insert(A);
			A = getchar();
		}
		int trees = 0;
		set<int> sets;
		for (const auto &i : inc) sets.insert(u.findSet(i));
		printf("There are %d tree(s) and %d acorn(s).\n", sets.size() - acorns, acorns);
	}
	return 0;
}
