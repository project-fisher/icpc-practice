// 0.000s/912(1)
// Very interesting bug... When shifting and converting, 1 << 31 = 1111111111111111111111111111111110000000000000000000000000000000 due to 1 being of type long??? In any case, the correct expression to be used here is 1l << 31. Just something to know with bitmasks.
#include <bits/stdc++.h>
#define lu unsigned long
using namespace std;

int main() {
	lu n, l, u;
	while (scanf("%lu%lu%lu", &n, &l, &u) == 3) {
		lu m = l;
		lu nn = ~n;
		lu log2 = 0, t = u;
		while (t) {
			t >>= 1;
			++log2;
		}
		if (log2-- == 0) {
			printf("0\n");
			continue;
		}
		for (lu msk = 1l << log2; msk; msk >>= 1) if ((nn&msk) && !(m&msk)) {
			t = m;
			m &= ~((msk << 1) - 1);
			m |= msk;
			if (m > u) m = t;
		}
		printf("%lu\n", m);
	}
	return 0;
}
