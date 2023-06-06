// 0.000s/758(1)
#include <bits/stdc++.h>
#define ui unsigned int

using namespace std;

int n;
int m[8][8];
ui msk = 0;
long long total = 0;

int manim(int i) {
	if (i < 0) return 0;
	int mn = 8000;
	for (int j = 0; j < n; ++j) {
		if (msk&(1 << j)) continue;
		msk |= (1 << j);
		mn = min(manim(i - 1) + m[i][j], mn);
		msk &= ~(1 << j);
	}
	return mn;
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) scanf("%d", &m[i][j]);
		printf("%d\n", manim(n - 1));
	}
	return 0;
}
