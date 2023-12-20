#include <bits/stdc++.h>
#define llu unsigned long long
#define ll long long
#define lu unsigned long
using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<llu> a(n), b(n); for (int i = 0; i < n; ++i) scanf("%llu", &a[i]); for (int i = 0; i < n; ++i) scanf("%llu", &b[i]);
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int ap = 0, bp = 0;
	for (int i = 0; i < n; ++i) {
		ap += distance(b.begin(), upper_bound(b.begin(), b.end(), a[i] - 1));
		bp += distance(a.begin(), upper_bound(a.begin(), a.end(), b[i] - 1));
	}
	if (ap > bp) puts("first");
	else if (ap != bp) puts("second");
	else puts("tie");
	return 0;
}
