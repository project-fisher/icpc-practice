#include <bits/stdc++.h>

using namespace std;

class DisjSet {
	int *rank, *parent, n;
public:
   
	DisjSet(int n) {
		rank = new int[n];
		parent = new int[n];
		this->n = n;
		makeSet();
	}
	 
	void makeSet() {
		for (int i = 0; i < n; i++) parent[i] = i;
	}
	 
	int find(int x) {
		if (parent[x] != x) parent[x] = find(parent[x]);
		return parent[x];
	}
	 
	void Union(int x, int y) {
		int xset = find(x);
		int yset = find(y);
		 
		if (xset == yset) return;
		 
		if (rank[xset] < rank[yset]) parent[xset] = yset;
		else if (rank[xset] > rank[yset]) parent[yset] = xset;
		else {
			parent[yset] = xset;
			rank[xset] = rank[xset] + 1;
		}
	}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> r(n);
		DisjSet d(n);
		for (int i = 0; i < n; ++i) {
			int v; cin >> v;
			--v;
			r[i] = v;
			d.Union(i, v);
		}
		map<int, set<int>> k;
		map<int, int> kp;
		for (int i = 0; i < n; ++i) {
			k[d.find(i)].insert(r[i]);
			kp[d.find(i)]++;
			//cout << d.find(i) << ' ';
		}
		int mx = k.size();
		int mn = 0;
		int no2 = 0;
		for (auto &i : k) {
			mn += kp[i.first] == i.second.size();
			no2 += kp[i.first] == 2;
		}
		if (mn == mx && no2) mn = mx - no2 + 1;
		cout << max(1, mn) << ' ' << mx << '\n';
	}
}
