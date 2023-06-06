#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n;
	while (n--) {
		long long mx = -10e9, mxp = -10e9;
		long long mn = 10e9, mnp = 10e9;
		cin >> k;
		long long v;
		while (k--) {
			cin >> v;
			if (v > mx) {
				mxp = mx;
				mx = v;
			} else if (v > mxp) {
				mxp = v;
			}
			if (v < mn) {
				mnp = mn;
				mn = v;
			} else if (v < mnp) {
				mnp = v;
			}
		}
		cout << max(mx*mxp, mn*mnp) << '\n';
	}
	return 0;
}
