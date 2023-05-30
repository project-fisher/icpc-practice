// 0.000s/925
#include <bits/stdc++.h>

using namespace std;

int n, m;
pair<int, int> buffer[14];
pair<int, int> ans[16];

bool backtrack(int i, int msk) {
	if (i == n + 1) return ans[i].first == ans[i - 1].second;
	bool found = 0;
	for (int j = 0; j < m && !found; ++j) if (!(msk&(1 << j))) {
		if (ans[i - 1].second == buffer[j].first) {
			ans[i] = buffer[j];
			found = backtrack(i + 1, msk|(1 << j));
		} else if (ans[i - 1].second == buffer[j].second) {
			ans[i] = {buffer[j].second, buffer[j].first};
			found = backtrack(i + 1, msk|(1 << j));
		}
	}
	return found;
}

int main() {
	while (scanf("%d%d", &n, &m) == 2) {
		int a, b; scanf("%d%d", &a, &b);
		ans[0] = {a, b};
		scanf("%d%d", &a, &b);
		ans[n + 1] = {a, b};
		for (int i = 0; i < m; ++i) {
			scanf("%d%d", &a, &b);
			buffer[i] = {a, b};
		}
		bool possible = backtrack(1, 0);
		printf(possible ? "YES\n" : "NO\n");
	}
	return 0;
}
