#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k; scanf("%d%d", &n, &k);
	vector<string> a(n);
	for (int i = 0; i < n; ++i) {
		getchar();
		for (int j = 0; j < k; ++j) a[i].push_back(getchar());
	}
	int mat[n][n];
	for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) {
		int diff = 0;
		for (int l = 0; l < k; ++l) diff += abs(a[i][l] - a[j][l]);
		mat[i][j] = diff;
		mat[j][i] = diff;
	}
	bitset<1000> v;
	int mx = INT_MIN;
	v.set();
	v.reset(0);
	int mn[n]; for (int i = 1; i < n; ++i) mn[i] = mat[0][i];
	for (int i = 1; i < n; ++i) {
		int mnl = INT_MAX, mnp = 0;
		for (int j = 0; j < n; ++j) if (v[j] && mn[j] < mnl) {
			mnl = mn[j];
			mnp = j;
		}
		v.reset(mnp);
		mx = max(mx, mnl);
		for (int i = 0; i < n; ++i) mn[i] = min(mn[i], mat[mnp][i]);
	}
	printf("%d\n", mx);
	return 0;
}
