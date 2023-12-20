#include <bits/stdc++.h>
#define llu unsigned long long
#define ll long long
#define lu unsigned long
using namespace std;

int main() {
	int n; scanf("%d", &n);
	char a[100002], b[100002]; scanf("%s%s", a, b);
	lu d = 0;
	for (int i = 0; i < n; ++i) d += min(abs(a[i] - b[i]), 26 - abs(a[i] - b[i]));
	printf("%lu\n", d);	
	return 0;
}
