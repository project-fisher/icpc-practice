#include <bits/stdc++.h>
typedef long long int ll;

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<ll> values;
	ll v;
	int s = 0;
	while (cin >> v) {
		++s;
		values.insert(lower_bound(values.begin(), values.end(), v), v);
		if (s&1) cout << values[s >> 1];
		else cout << ((values[s >> 1] + values[(s >> 1) - 1]) >> 1);
		cout << '\n';
	}
	return 0;
}
