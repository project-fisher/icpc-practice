#include <bits/stdc++.h>
#define llu unsigned long long
#define ll long long
using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<int> a(n); for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	long cnt = 0, coins = 0;
	for (int i = 0; i < n; ++i) {
		--a[i];
		if (a[i] == i) ++coins;
		else if (a[a[i]] - 1 == i && a[i] > i) ++cnt;
	}
	cnt += coins*(coins - 1)/2;
	printf("%ld\n", cnt);

	return 0;
}
