#include <bits/stdc++.h>

#define ll long long

using namespace std;

int H, W;
bitset<1001> mat[1001];

const ll mod = 1e9 + 7;

ll memo[1001][1001] = {0};

ll dp(int i, int j) {
	if (i > H || j > W || mat[i][j]) return 0;
	if (i == H && j == W) return 1;
	if (memo[i][j]) return memo[i][j] - 1;
	memo[i][j] = 1 + (dp(i + 1, j) + dp(i, j + 1))%mod;
	return memo[i][j] - 1;
}

int main() {
	scanf("%d%d", &H, &W);
	while (getchar() != '\n');
	for (int i = 0; i < H; ++i) {
		char c;
		int j = 0; 
		while ((c = getchar()) != '\n') mat[i][j++] = c != '.';
	}
	--H; --W;
	printf("%lld\n", dp(0, 0));
	return 0;
}
