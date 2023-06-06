#include <bits/stdc++.h>
#define llu unsigned long long

using namespace std;

int main() {
	int t; scanf("%d", &t);
	char buffer[101];
	while (t--) {
		int n; scanf("%d", &n);
		scanf("%s", buffer);
		char last = 0;
		for (int i = 0; i < n; ++i) {
			if (!last) last = buffer[i];
			else if (last == buffer[i]) {
				printf("%c", last);
				last = 0;
			}
		}
		printf("\n");
	}

	return 0;
}
