// 0.000s/2821
#include <bits/stdc++.h>

using namespace std;

int main() {
	int t; scanf("%d", &t);
	for (int run = 1; run <= t; ++run) {
		int n; scanf("%d", &n);
		while (getchar() != '\n');
		bitset<102> field; for (int i = 0; i < n; ++i) field[i] = getchar() == '.';
		int s = 0;
		for (int i = 0; i < n; ++i) if (field[i]) {
			++s;
			field[i + 2] = field[i + 1] = 0;
		}
		printf("Case %d: %d\n", run, s);
	}
	return 0;
}

