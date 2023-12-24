// 0.000s/1986(1)
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> idg;
vector<int> ans;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	int n;
	char data[100][51];
	int t = 1;
	while (scanf("%d", &n) == 1) {
		map<string, int> rdata;
		for (int i = 0; i < n; ++i) {
			scanf("%s", data[i]);
			rdata[string(data[i])] = i;
		}	
		int k; scanf("%d", &k);
		idg.assign(n, 0);
		adj.assign(n, vector<int>());
		char a[51], b[51];
		for (int i = 0; i < k; ++i) {
			scanf("%s%s", a, b);
			adj[rdata[string(a)]].push_back(rdata[string(b)]);
			++idg[rdata[string(b)]];
		}
		ans.clear();
		for (int i = n - 1; i >= 0; --i) if (!idg[i]) pq.push(i);
		while (!pq.empty()) {
			int v = pq.top(); pq.pop();
			ans.push_back(v);
			for (auto i : adj[v]) if (!(--idg[i])) pq.push(i);
		}
		printf("Case #%d: Dilbert should drink beverages in this order:", t++);
		for (int i = 0; i < n; ++i) printf(" %s", data[ans[i]]);
		printf(".\n\n");
	}
	return 0;
}
