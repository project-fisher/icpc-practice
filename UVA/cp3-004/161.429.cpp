// 0.000s/749(1)
#include <bits/stdc++.h>

using namespace std;

vector<set<int>> adj;

int cntdif(string &a, string &b) {
	int dif = 0;
	for (int i = 0; i < a.size(); ++i) dif += a[i] != b[i];
	return dif;
}

int cdist(int v, int u) {
	vector<int> dist(adj.size(), INT_MAX); dist[v] = 0;
	queue<int> q; q.push(v);
	while (!q.empty()) {
		int i = q.front(); q.pop();
		for (auto j : adj[i]) if (dist[j] == INT_MAX) {
			dist[j] = dist[i] + 1;
			q.push(j);
		}
	}
	return dist[u];
}

int main() {
	int T; scanf("%d", &T);
	for (int t = 0; t < T; ++t) {
		char buffer[11];
		scanf("%s", buffer);
		adj.clear();
		vector<string> pts;
		map<string, int> stp;
		vector<int> sitp[11];
		while (buffer[0] != '*') {
			adj.push_back({});
			string temp(buffer);
			for (auto s : sitp[temp.size()]) if (cntdif(pts[s], temp) == 1) {
				adj[s].insert(pts.size());
				adj[pts.size()].insert(s);
			}
			sitp[temp.size()].push_back(pts.size());
			stp[temp] = pts.size();
			pts.push_back(temp);
			scanf("%s", buffer);
		}
		char c;
		while ('\n' != getchar());
		if (t) puts("");
		while ((c = getchar()) != '\n' && c != -1) {
			ungetc(c, stdin);
			int u, v;
			scanf("%s", buffer);
			u = stp[string(buffer)];
			printf("%s ", buffer);
			scanf("%s", buffer);
			v = stp[string(buffer)];
			printf("%s ", buffer);
			printf("%d\n", cdist(v, u));
			while ('\n' != (c = getchar()) && c != -1);
		}
	}
	return 0;
}
