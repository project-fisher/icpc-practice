#include <bits/stdc++.h>

#define llu unsigned long long

using namespace std;

int main() {
	llu a, b; scanf("%llu%llu", &a, &b);
	llu bx = a/b + (a%b ? 1 : 0);
	printf("%llu\n", a/bx);
	return 0;
}
