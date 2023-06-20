#include <bits/stdc++.h>
#define llu unsigned long long
#define lu unsigned long
#define ll long long

using namespace std;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		vector<int> a(n); for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		sort(a.begin(), a.end());
		int cost = 0;
		int l = -1, r = n;
		while (++l < --r) cost += a[r] - a[l];
		printf("%d\n", cost);
	}
	return 0;
}
