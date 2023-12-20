#include <bits/stdc++.h>
#define llu unsigned long long
#define ll long long
#define lu unsigned long
using namespace std;

int main() {
	llu n; scanf("%llu", &n);
	bool db7 = n%7 == 0;
	bool h7 = 0;
	while (!h7 && n) {
		h7 = n%10 == 7;
		n /= 10;
	}
	if (db7 && h7) puts("3");
	else if (db7) puts("1");
	else if (h7) puts("2");
	else puts("0");
	return 0;
}
