#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	char c;
	scanf("%d%c%d", &a, &c, &b);
	while (a || b) {
		int m = 55*b, h = a*300, k = abs(h - m), j = min(3600 - k, k);
		printf("%d.%d00\n", j/10, j%10);
		scanf("%d%c%d", &a, &c, &b);
	}
}
