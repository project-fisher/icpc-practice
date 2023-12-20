#include <bits/stdc++.h>
#define llu unsigned long long
#define ll long long
#define lu unsigned long
using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<llu> a(n); for (int i = 0; i < n; ++i) scanf("%llu", &a[i]);
	sort(a.begin(), a.end());
	printf("%llu\n", a[0] + a[1]);
	return 0;
}
