#include <bits/stdc++.h>
#define llu unsigned long long
#define ll long long
#define lu unsigned long
using namespace std;

int main() {
	int n; scanf("%d", &n);
	llu r = 1;
	for (int i = 1; i <= n; ++i) r*=i;
	printf("%llu\n", r);
	return 0;
}
