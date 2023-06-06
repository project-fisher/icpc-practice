#include <bits/stdc++.h>

using namespace std;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			int a; scanf("%d", &a);
			printf((i ? " %d" : "%d"), n - a + 1);
		}
		printf("\n");
	}
	return 0;
}
