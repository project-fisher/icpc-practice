// 0.000s/1401(1)
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; scanf("%d", &n);
	while (n--) {
		long long A, B, C; scanf("%lld%lld%lld", &A, &B, &C);
		long long sqrtC = (long long)sqrt((float)C);
		long long x = -sqrtC, y, z;
		bool yes = 0;
		for (; x <= sqrtC; ++x)
			for (y = -sqrtC; y <= sqrtC; ++y) {
				z = A - x - y;
				if (B == x*y*z && C == x*x + y*y + z*z && x - y && x - z && y - z) {
					yes = 1;
					goto end;
				}
			}
		end:
		if (yes) printf("%lld %lld %lld\n", x, y, z);
		else printf("No solution.\n");
	}
	return 0;
}
	
