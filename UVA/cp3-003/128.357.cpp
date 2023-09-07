// 0.590s/>10K
#include <bits/stdc++.h>

using namespace std;

long coin_ways(vector<int> &coins, int n) {

	long ways[n + 1];
	memset(ways, 0, sizeof(ways));
	ways[0] = 1;

	for (int i : coins) for (int j = 0; j <= n; ++j) ways[j] += j < i ? 0 : ways[j - i];

	return ways[n];
}


int main() {
	int n;
	vector<int> coins = {1, 5, 10, 25, 50};
	while (scanf("%d", &n) != -1) {
		long v = coin_ways(coins, n);
		if (v - 1) printf("There are %ld ways to produce %d cents change.\n", v, n);
		else printf("There is only 1 way to produce %d cents change.\n", n);
	}
	return 0;
}
