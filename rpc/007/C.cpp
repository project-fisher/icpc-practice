#include <bits/stdc++.h>
#define llu unsigned long long
#define ll long long
#define lu unsigned long
using namespace std;

int main() {
	int n; scanf("%d", &n);
	char s[363];
	scanf("%s", s);
	int l = strlen(s);
	int nn = n*n;
	for (; l < nn; ++l) s[l] = 0;
	s[l] = 0;
	char c[n][n];
	int n2 = n/2;
	int ring = 1;
	int ring_pos = 0;
	int loops = 3;
	int i = 0, j = 0;
	int k = 0;
	while (k < nn) {
		c[n2 + i][n2 + j] = s[k++];
		++ring_pos;
		if (ring_pos + 1 >= ring) {
			++loops;
			ring_pos = 0;
		}
		if (loops == 4) {
			loops = 0;
			ring += 2;
			--j;
			--i;
		}
		switch (loops) {
			case 0:
				++j;
				break;
			case 1:
				++i;
				break;
			case 2:
				--j;
				break;
			case 3:
				--i;
				break;
		}
	}
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if(c[i][j]) printf("%c", c[i][j]);
	puts("");
	return 0;
}
