#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k; scanf("%d%d", &n, &k);
	char buffer[1001]; scanf("%s", buffer);
	char exp = 'L';
	for (int i = 0; i < n; ++i) {
		if (exp != buffer[i]) --k;
		else exp = exp == 'L' ? 'R' : 'L';
	}
	printf("%d\n", k > 0 ? k : 0);
	return 0;
}
