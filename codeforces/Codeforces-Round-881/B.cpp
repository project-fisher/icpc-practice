#include <bits/stdc++.h>
#define llu unsigned long long
#define lu unsigned long
#define ll long long

using namespace std;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		vector<ll> a(n); for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
		ll sum = 0;
		int c = 0;
		bool m = 0;
		for (auto &i : a) {
			sum += abs(i);
			if (m && i > 0) m = 0;
			else if (!m && i < 0) {
				m = 1;
				++c;
			}
		}
		printf("%lld %d\n", sum, c);
	}
	return 0;
}
