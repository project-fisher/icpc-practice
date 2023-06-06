#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long a, b, n, sol;
	cin >> a >> b >> n;
	if (n == 0) sol = 0;
	else if (b == 0 || n < a) sol = -1;
	else if (a < 2 || (a == 2 && a != b)) sol = n/b + (n%b ? 1 : 0);
	else if (n > b*(n/a) && n%a) sol = -1;
	else sol = n/b + (n%b ? 1 : 0);
	cout << sol << '\n';
	return 0;
}
