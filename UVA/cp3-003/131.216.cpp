// 0.000s/776(2)
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	int t = 0;
	while (scanf("%d", &n) && n) {
		vector<pair<int, int>> p(n); for (int i = 0; i < n; ++i) scanf("%d%d", &p[i].first, &p[i].second);
		double adj[8][8] = {0};
		for (int i = 0; i < n; ++i) for (int j = 1; j < n; ++j) adj[i][j] = adj[j][i] = sqrt(1.0*(p[i].first - p[j].first)*(p[i].first - p[j].first) + (p[i].second - p[j].second)*(p[i].second - p[j].second)) + 16.0;
		vector<int> ord(n);
		iota(ord.begin(), ord.end(), 0);
		int num = 1;
		for (int i = 1; i <= n; ++i) num *= i;
		double mn = DBL_MAX;
		vector<int> best(n);
		for (int i = 0; i < num; ++i) {
			double r = 0;
			for (int i = 1; i < n; ++i) r += adj[ord[i]][ord[i - 1]];
			if (r < mn) {
				mn = r;
				for (int i = 0; i < n; ++i) best[i] = ord[i];
			}
			next_permutation(ord.begin(), ord.end());
		}
		puts("**********************************************************");
		printf("Network #%d\n", ++t);
		for (int i = 1; i < n; ++i) printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", p[best[i - 1]].first, p[best[i - 1]].second, p[best[i]].first, p[best[i]].second, adj[best[i - 1]][best[i]]);
		printf("Number of feet of cable required is %.2lf.\n", mn);
	}
	return 0;
}
