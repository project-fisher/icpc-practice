// 0.000s/7846
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string d;
	while (getline(cin, d) && d[0] - '#') {
		if (next_permutation(d.begin(), d.end())) cout << d << '\n';
		else cout << "No Successor\n";
	}
	return 0;
}
