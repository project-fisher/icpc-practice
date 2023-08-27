#include <bits/stdc++.h>

#define lu unsigned long long

using namespace std;

int main() {
	lu a; scanf("%llu", &a);
	lu ap = a;
	lu r = 1;
	int total = 0;
	while (a/10) {
		r *= 10;
		r += a%10;
		total += 10;
		a /= 10;
	}
	r *= 10;
	r += a;
	total += a;
	if (ap/10) {
		while (r/100 && r%10 >= (r/10)%10) {
			if (r%10 > (r/10)%10) {
				--total;
				break;
			}
			r /= 10;
		}
	} else ++total;
	printf("%d\n", total);
	return 0;
}
