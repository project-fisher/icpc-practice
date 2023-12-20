#include <bits/stdc++.h>
#define llu unsigned long long
#define ll long long
#define lu unsigned long
using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<pair<int, int>> p(n); for (int i = 0; i < n; ++i) scanf("%d%d", &p[i].first, &p[i].second);
	double mat[n][n];
	for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) mat[i][j] = mat[j][i] = sqrt(pow(p[i].first - p[j].first, 2) + pow(p[i].second - p[j].second, 2));
	double mn = 10000;
	for (int i = 0; i < n; ++i) {
		double s = 0;
		for (int j = 0; j < n; ++j) {
			if (j == i) continue;
			s += mat[i][j];
		}
		mn = min(mn, s/(n - 1.0));
	}
	printf("%.13lf\n", mn);
	return 0;
}
