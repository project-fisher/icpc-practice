// 0.020s/3458
#include <bits/stdc++.h>

using namespace std;

int main() {
	int p, q, r, s, t, u;
	while (scanf("%d%d%d%d%d%d", &p, &q, &r, &s, &t, &u) == 6) {
		long double inf = 0.0, sup = 1.0;
		long double x = (inf + sup)/2.0;
		int iter = 0;
		long double eval = p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u; 
		while (iter++ < 100 && !(-0.000000001 < eval && eval < 0.000000001)) {
			if (eval > 0) inf = x;
			else sup = x;
			x = (inf + sup)/2.0;	       
			eval = p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u; 
		}
		if (iter > 100) printf("No solution\n");
		else printf("%.4Lf\n", x);
	}
	return 0;
}
