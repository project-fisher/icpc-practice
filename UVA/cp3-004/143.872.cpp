// 0.000s/1510
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> idg;

vector<char> gvs;
bitset<21> yes;

vector<vector<int>> sorts;

void fato(vector<int> &path) {
	if (path.size() == idg.size()) {
		sorts.push_back(vector<int>(idg.size()));
		copy(path.begin(), path.end(), sorts.back().begin());
		return;
	}
	for (int v = 0; v < adj.size(); ++v) if (!(idg[v] || yes[v])) {
		for (int u : adj[v]) --idg[u];
		yes.set(v);
		path.push_back(v);
		fato(path);
		for (int u : adj[v]) ++idg[u];
		path.pop_back();
		yes.reset(v);
	}
}

int main() {
	int n; scanf("%d", &n);
	for (int t = 0; t < n; ++t) {
		vector<char> data;
		unordered_map<char, int> rdata;
		char c;
		while ((c = getchar()) < 'A' || c > 'Z');
		do {
			rdata[c] = data.size();
			data.push_back(c);
			while ((c = getchar()) != '\n' && (c < 'A' || c > 'Z'));
		} while (c != '\n');
		adj.assign(data.size(), vector<int>());
		idg.assign(data.size(), 0);
		while ((c = getchar()) < 'A' || c > 'Z');
		do {
			char a = c;
			getchar();
			c = getchar();
			adj[rdata[a]].push_back(rdata[c]);
			++idg[rdata[c]];
			while ((c = getchar()) != '\n' && c != -1 && (c < 'A' || c > 'Z'));
		} while (c != '\n' && c != -1);
		if (t) puts("");
		sorts.clear();
		yes.reset();
		vector<int> path; fato(path);
		if (sorts.size() == 0) puts("NO");
		else {
			vector<string> ans(sorts.size());
			for (int i = 0; i < sorts.size(); ++i) {
				bool first = 1;
				for (auto j : sorts[i]) {
					if (first) first = 0;
					else ans[i] += ' ';	
					ans[i] += data[j];
				}
			}
			sort(ans.begin(), ans.end());
			for (auto &i : ans) printf("%s\n", i.c_str());
		}
	}
	return 0;
}
