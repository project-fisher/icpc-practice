#include <bits/stdc++.h>
#define llu unsigned long long
#define lu unsigned long
#define ll long long

using namespace std;

int n;
vector<vector<ll>> g;
vector<ll> w(200001);

void build(ll v, ll p) {
	if (v != 0 && g[v].size() == 1) {
		w[v] = 1;
		return;
	}
	w[v] = 0;
	for (auto &i : g[v]) if (i != p) {
		build(i, v);
		w[v] += w[i];
	}
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		g.resize(n);
		for (int i = 1; i < n; ++i) {
			ll a, b; scanf("%lld%lld", &a, &b); --a; --b;
			g[b].push_back(a);
			g[a].push_back(b);
		}
		build(0, 0);
		int q; scanf("%d", &q);
		while (q--) {
			ll a, b; scanf("%lld%lld", &a, &b); --a; --b;
			printf("%lld\n", w[a]*w[b]);
		}
		for (auto &i : g) i.clear();
		g.clear();
	}
	return 0;
}
