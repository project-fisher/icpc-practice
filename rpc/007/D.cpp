#include <bits/stdc++.h>
#define llu unsigned long long
#define ll long long
#define lu unsigned long
using namespace std;

int main() {
	double yp, xp, r; scanf("%lf%lf%lf", &yp, &xp, &r);
	xp = abs(xp);
	if (xp <= r) {
		puts("0");
		return 0;
	}
	double m = -yp/xp;
	double b = yp;
	double d = (2.0*m*b)*(2.0*m*b) - 4.0*(b*b - r*r)*(m*m + 1.0);
	if (d < 0) {
		puts("-1");
		return 0;
	}
	double x = (-(2.0*m*b) + sqrt(d))/(2.0*(m*m + 1.0));
	printf("%.18lf\n", acos(x/r)*180.0/acos(-1.0));
	return 0;
}
