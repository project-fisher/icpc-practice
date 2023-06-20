// 0.020s/1836(1)
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	while (scanf("%d", &n) == 1 && n) {
		bool p = 0;
		for (int i = 0; i < n; ++i) {
			int t; scanf("%d", &t);
			if (t) {
				if (p) printf(" ");
				p = 1;
				printf("%d", t);
			}
		}
		if (!p) printf("0");
		printf("\n");
	}
	return 0;
}
