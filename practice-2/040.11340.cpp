#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k, m;
	unsigned char l;
	cin >> n;
	while (n--) {
		cin >> k;
		short d[255] = {0};
		while (k--) {
			cin >> l;
			cin >> d[l];
		}
		int c = 0;
		cin >> m;
		string s;
		int ns = 0;
		while (ns <= m && (k = cin.get()) != -1) {
			l = (unsigned char)k;
			c += d[l];
			ns += l == '\n' ? 1 : 0;
		}
		cout << c/100 << '.'; cout << setfill('0') << setw(2) << c%100; cout << "$\n";
	}
	return 0;
}
