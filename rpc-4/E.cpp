#include <bits/stdc++.h>
using namespace std;

static long double p[31] = {100.0, 0.0, 50.0, 25.0, 37.5, 31.25, 34.375, 32.8125, 33.59375, 33.203125, 33.3984375, 33.30078125, 33.349609375, 33.3251953125, 33.33740234375, 33.331298828125, 33.3343505859375, 33.33282470703125, 33.333587646484375, 33.33320617675781, 33.333396911621094, 33.33330154418945, 33.33334922790527, 33.33332538604736, 33.33333730697632, 33.33333134651184, 33.33333432674408, 33.33333283662796, 33.33333358168602, 33.33333320915699, 33.333333395421505};
int main() {
	unsigned long long n; scanf("%llu", &n);
	--n;
	n = min(n, 30ull);
	printf("%.7Lf %.7Lf\n", p[n], 100 - p[n]);
	return 0;
}
