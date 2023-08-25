// 0.700s/857(1)
#include <bits/stdc++.h>

using namespace std;

int N, K, v[101];
unordered_map<int, int> memo[101][21];
int x, T, w[101];

int dp(int dish, int m, int dish_tot) {
	if (m > x || dish_tot > 2*N) return INT_MIN;
	if (dish == K) return 0;
	if (memo[dish][dish_tot].count(m)) return memo[dish][dish_tot][m];
	return memo[dish][dish_tot][m] = max(max(dp(dish + 1, m + w[dish], dish_tot + 1) + v[dish], dp(dish + 1, m + 2*w[dish], dish_tot + 2) + 2*v[dish]), dp(dish + 1, m, dish_tot));
}

int main() {
	while (scanf("%d%d%d%d", &N, &x, &T, &K) && N != 0) {
		for (int i = 0; i < 101; i++) for (int j = 0; j < 21; ++j) memo[i][j].clear();
		++N;
		x *= 100;
		x -= T*110;
		x *= N;
		for (int i = 0; i < K; ++i) {
			scanf("%d", &w[i]);
			w[i] *= 110;
			int sum;
			v[i] = 0;
			for (int j = 0; j < N; ++j) {
				scanf("%d", &sum);
				v[i] += sum;
			}
		}
		float ans = dp(0, 0, 0)*1.0f/N;
		printf("%.2f\n", ans);
	}
	return 0;
}
