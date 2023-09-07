#include <bits/stdc++.h>
#define llu unsigned long long
#define ll long long
#define lu unsigned long
using namespace std;

int main() {
	llu n; int k; scanf("%llu%d", &n, &k);
	llu x = n;
	int kp = k;
	llu ap = 1, acu;
	while (k--) {
		ap *= 10;
		acu = x%ap;
		x /= ap;
		x *= ap;
		x += ap*(ap >> 1 <= acu);
	}
	printf("%llu\n", x);	
	return 0;
}
