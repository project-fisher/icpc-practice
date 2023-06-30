// 0.000s/2739
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; scanf("%d", &n);
	int data[n][n]; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) scanf("%d", &data[i][j]);
	int s[n + 1][n + 1]; for (int i = 0; i <= n; ++i) {
		s[i][0] = 0;
		s[0][i] = 0;
	} for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) s[i][j] = s[i - 1][j] + data[i - 1][j - 1];
	int total = INT_MIN;
	for (int i = 0; i < n; ++i) for (int ip = i + 1; ip <= n; ++ip) {
		int temp = 0;
		for (int j = 1; j <= n; ++j) {
			int k = s[ip][j] - s[i][j];
			temp = max(k, temp + k);
			total = max(total, temp);
		}
	}
	printf("%d\n", total);

	return 0;
}
