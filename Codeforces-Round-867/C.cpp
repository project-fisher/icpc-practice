#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	long long n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << (n*n + 2*n + 2) << '\n';
	}
	return 0;
}
