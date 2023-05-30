// 0.220s/3884
#include <bits/stdc++.h>

using namespace std;

int n;
int buffer[16] = {1};
unsigned long long primes = 0xa08a28ac;

void backtrack(int i, int msk) {
	if (i == n) if (primes&(1 << (buffer[i - 1] + buffer[0]))) {
		printf("%d", 1);
		for (i = 1; i < n; ++i) printf(" %d", buffer[i]);
		printf("\n");
		return;
	}
	for (int j = 0; j < n; ++j) if (!(msk&(1 << j)) && (primes&(1 << (buffer[i - 1] + j + 1)))) {
		buffer[i] = j + 1;
		backtrack(i + 1, msk|(1 << j));
	}
}

int main() {
	int run = 0;
	while (scanf("%d", &n) == 1) {
		if (run) printf("\n");
		printf("Case %d:\n", ++run);
		backtrack(1, 1);
	}
	return 0;
}
