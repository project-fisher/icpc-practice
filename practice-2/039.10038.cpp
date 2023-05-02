// 0.000s/>10K
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, prev, act, w;
	while (cin >> n) {
		set<int> f;
		cin >> prev;
		bool sol = 1;
		for (int i = 1; i < n; i++) {
			cin >> act;
			if ((w = abs(act - prev)) > 0 && w < n) f.insert(w);
			else sol = 0;
			prev = act;
		}
		if (sol && f.size() == n - 1) cout << "Jolly\n";
		else cout << "Not jolly\n";
	}
	return 0;
}
