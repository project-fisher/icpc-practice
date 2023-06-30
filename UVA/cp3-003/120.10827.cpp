// 1.560s/2806
#include <bits/stdc++.h>

using namespace std;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		int data[n][n]; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) scanf("%d", &data[i][j]);
		int s[n + 1][n + 1]; for (int i = 0; i <= n; ++i) {
			s[i][0] = 0;
			s[0][i] = 0;
		} for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) s[i][j] = s[i - 1][j] + data[i - 1][j - 1];
		int total = INT_MIN;
		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int off = 0; off < n; ++off) {
			int temp = 0;
	
			for (int k = 0; k < n; ++k) {
				int kp = (off + k)%n + 1;
				int p = j >= i ? s[j + 1][kp] - s[i][kp] : s[n][kp] - s[i][kp] + s[j][kp];
				temp = max(p, temp + p);
				total = max(total, temp);
			}
		}
		printf("%d\n", total);
	}
	return 0;
}
