#include <bits/stdc++.h>
#define llu unsigned long long
#define ll long long
#define lu unsigned long
using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<int> a(n); for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	n = 2*n + 1;
	vector<int> b(n + 10);
	fill(b.begin(), b.end(), 0);
	for (int i = 0; i < a.size(); ++i) {
		b[2*(i + 1)] = a[i];
		b[2*(i + 1) + 1] = a[i];
	}
	vector<int> memo(n + 10); fill(memo.begin(), memo.end(), 0);
	for (int i = 1; i <= n; ++i) {
		int dst = 0;
		int p = i;
		while (p > 1) {
			if (memo[p]) {
				dst += memo[p];
				break;
			}
			++dst;
			p = b[p];
		}
		memo[i] = dst;
		printf("%d\n", dst);
	}
	return 0;
}
