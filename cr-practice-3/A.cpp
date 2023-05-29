#include <bits/stdc++.h>
#define ull unsigned long long
#define ul unsigned long
#define ui unsigned int

using namespace std;

int main() {
	int n; scanf("%d", &n);
	int m; scanf("%d", &m);
	int x; scanf("%d", &x);
	int t; scanf("%d", &t);
	int d; scanf("%d", &d);
	if (m >= x) printf("%d\n", t);
	else printf("%d\n", t - (x - m)*d);
	return 0;
}
