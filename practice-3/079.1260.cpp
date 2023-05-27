// 0.010s/1831
#include <bits/stdc++.h>

using namespace std;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		vector<int> a(n);
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		int sum = 0;
		for (int i = 1; i < n; ++i) for (int j = 0; j < i; ++j) sum += a[j] <= a[i];
		printf("%d\n", sum);
	}
	return 0;
}
