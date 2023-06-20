#include <bits/stdc++.h>
#define llu unsigned long long
#define lu unsigned long
#define ll long long

using namespace std;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		llu n; scanf("%llu", &n);
		llu sum = n;
		while (n >>= 1) sum += n;
		printf("%llu\n", sum);
	}
	return 0;
}
