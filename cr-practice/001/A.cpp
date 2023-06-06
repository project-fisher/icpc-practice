#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, x;
	cin >> n >> x;
	cout << (char)('A' + x/n + (x%n ? 0 : -1)) << '\n';
	return 0;
}
