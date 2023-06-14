// 0.000s/504(5)
#include <bits/stdc++.h>

using namespace std;

int msks[15];
int n;

int mp[10] = {0b1111110, 0b0110000 ,0b1101101 ,0b1111001 ,0b0110011 ,0b1011011 ,0b1011111 ,0b1110000 ,0b1111111 ,0b1111011};

bool backtrack(int c, int pos, int msk) {
	if (pos == n) return 1;
	if (c < 0) return 0;
	int a = msks[pos], b = mp[c];
	for (int i = 0, j = 1; i < 7; ++i, j <<= 1, a >>= 1, b >>= 1) {
		if ((a&1) && !(b&1)) return 0;
		if (!(msk&j) && (a&1)) return 0;
		if ((b&1) && !(a&1)) msk &= ~j;
	}
	return backtrack(c - 1, pos + 1, msk);
}

int main() {
	char c;
	int s = 0;
	while ((s = scanf("%d", &n)) == 1 && n) {
		while (getchar() != '\n');
		for (int i = 0; i < n; ++i) {
			int pos = 1 << 6;
			msks[i] = 0;
			for (int j = 0; j < 7; ++j, pos >>= 1) {
				msks[i] |= ((c = getchar()) == 'Y')*pos;
			}
			getchar();
		}
		bool solv = 0;
		for (int i = n - 1; i < 10 && !solv; ++i) solv = backtrack(i, 0, 0b1111111);
		if (solv) printf("MATCH\n");
		else printf("MISMATCH\n");
	}
	return 0;
}
