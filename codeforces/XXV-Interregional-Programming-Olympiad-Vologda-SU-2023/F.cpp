#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, sol;
	cin >> n;
	if (n&1 && n <= 2221) sol = 43895 + (n - 1001)*5;
	else if (n&1) sol = 5 + (n - 2223)*5;
	else if (n == 2222) sol = 6;
	else if (n == 2224) sol = 10;
	else if (n == 2226) sol = 20;
	else if (n <= 2220) sol = 4390 + n/2 - 500;
	else sol = 4 + n/2 - 1114;
	cout << sol << '\n';
	return 0;
}
