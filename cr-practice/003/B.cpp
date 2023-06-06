#include <bits/stdc++.h>
#define ull unsigned long long
#define ul unsigned long
#define ui unsigned int

using namespace std;

int main() {
	int a; scanf("%d", &a);
	int b; scanf("%d", &b);
	int d; scanf("%d", &d);
	long double ang = d*4*atanl(1.0)/180.0;
	long double na = a*cos(ang) - b*sin(ang), nb = a*sin(ang) + b*cos(ang);
	printf("%.20Lf %.20Lf\n", na, nb);
	return 0;
}
