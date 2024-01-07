// 0.200s/502(1)
#include <bits/stdc++.h>

using namespace std;

map<string, int> sti;
vector<string> its;

int gs() {
	char buffer[51]; scanf("%s", buffer);
	string t(buffer);
	if (!sti.count(t)) {
		sti[t] = its.size();
		its.push_back(t);
	}
	return sti[t];
}


int main() {
	int n;
	while (scanf("%d", &n) && n) {
		sti.clear();
		its.clear();
		vector<set<pair<int, int>>> adj(n*2 + 2);
		map<int, int> u = {{0, 0}, {1, 1}};
		gs(); gs();
		int cnt = 2;
		for (int i = 0; i < n; ++i) {
			int a = gs(), b = gs(), c = gs();
			if (!u.count(a)) u[a] = cnt++;
			if (!u.count(b)) u[b] = cnt++;
			a = u[a]; b = u[b];
			adj[a].insert({b, c});
			adj[b].insert({a, c});
		}
		vector<vector<int>> dist(adj.size(), vector<int>(27, INT_MAX));
		dist[0][26] = 0;
		set<pair<int, pair<int, int>>> s = {{0, {0, 26}}};
		while (!s.empty()) {
			auto f = *s.begin(); s.erase(s.begin());
			int a = f.first, b = f.second.first, c = f.second.second;
			if (a > dist[b][c] || b == 1) continue;
			for (auto i : adj[b]) {
				int d = i.first, e = i.second;
				int ee = its[e][0] - 'a';
				if (ee != c && dist[b][c] + its[e].size() < dist[d][ee]) {
					dist[d][ee] = dist[b][c] + its[e].size();
					s.insert({dist[d][ee], {d, ee}});
				}
			}
		}
		int mn = INT_MAX;
		for (int i = 0; i < 26; ++i) mn = min(mn, dist[1][i]);
		if (mn == INT_MAX) puts("impossivel");
		else printf("%d\n", mn);
	}
	return 0;
}
