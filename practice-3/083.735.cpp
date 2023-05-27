// 0.510s/1044
#include <bits/stdc++.h>

using namespace std;

static int v[43] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 24, 26, 27, 28, 30, 32, 33, 34, 36, 38, 39, 40, 42, 45, 48, 50, 51, 54, 57, 60};

int main() {
	int n;
	while (scanf("%d", &n) == 1 && n > 0) {
		long perms = 0;
		set<pair<int, pair<int, int>>> s;
		for (int i : v) for (int j : v) for (int k : v) if (n - i - j - k == 0) {
			++perms;
			s.insert(make_pair(max(i, max(j, k)), make_pair(max(i, k) >= j && j >= min(i, k) ? j : (max(j, k) >= i && i >= min(j, k) ? i : k), min(i, min(j, k)))));
		}
		if (perms) {
			printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %ld.\n", n, s.size());
			printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %ld.\n", n, perms);
		} else printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n);
		printf("**********************************************************************\n");
	}
	printf("END OF OUTPUT\n");
	return 0;
}
