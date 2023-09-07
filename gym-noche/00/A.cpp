#include <bits/stdc++.h>
#define llu unsigned long long
#define ll long long
#define lu unsigned long

using namespace std;

lu binpower(lu b, lu ex, lu mod) {
	llu r = 1;
	b %= mod;
	while (ex) {
		if (ex&1) r = (r*b)%mod;
		b = b*b%mod;
		ex >>= 1;
	}
	return r;
}


bool probablyPrimeFermat(int n, int iter = 10) {
	if (n < 4) return n == 2 || n == 3;
	for (int i = 0; i < iter; i++) {
		int a = 2 + rand() % (n - 3);
		if (binpower(a, n - 1, n) != 1) return 0;
	}
	return 1;
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		char str[10];
		scanf("%s", str);
		lu ans = 0lu;
		for (lu msk = 1lu; msk <= 0b111111111lu && !ans; ++msk) {
			lu mskt = msk;
			lu val = 0lu;
			for (int i = 0; i < 9; ++i, mskt >>= 1lu) if (mskt&1lu) {
				val *= 10;
				val += str[i] - '0';	
			}
			if (probablyPrimeFermat(val) && val > 10) ans = val;
		}
		printf("%lu\n", ans);
	}
	return 0;
}
