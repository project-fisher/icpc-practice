// 0.000s/1939(1)
#include <bits/stdc++.h>
#define llu unsigned long long
using namespace std;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		vector<llu> c(n); for (int i = 0; i < n; ++i) scanf("%llu", &c[i]);
		int unq = 1;
		bitset<1000> used = 0;
		llu s = 0;
		for (int i = 0; i < n - 1; ++i) {
			s += c[i];
			if (s < c[i + 1]) ++unq;
			else s -= c[i];
		}
		printf("%d\n", unq);
	}
	return 0;
}
