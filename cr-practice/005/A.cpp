#include <bits/stdc++.h>
#define llu unsigned long long
#define ll long long
#define sf scanf
#define pf printf
using namespace std;

int main() {
	int n; scanf("%d", &n);
	printf("%d\n", n + (6 - n%4)%4);
	return 0;
}
