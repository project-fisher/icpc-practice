#include <bits/stdc++.h>

using namespace std;

typedef struct struct_triple {
	string a;
	double b;
	int c;
} tr;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int req, p, i = 1;
	char c = 0;
	string buffer;
	cin >> req >> p;
	while (req) {
		while (req--) {
			cin.ignore();
			getline(cin, buffer);
		}
		tr mx;
		mx.c = 0;
		mx.b = 0;
		string text;
		double tempd;
		int tempn;
		while (p--) {
			getline(cin, text);
			cin >> tempd >> tempn;
			for (int j = 0; j < tempn; j++) {
				cin.ignore();
				getline(cin, buffer);
			}
			if (tempn > mx.c || (tempn == mx.c && tempd < mx.b)) {
				mx.a = text;
				mx.c = tempn;
				mx.b = tempd;
			}
		}
		if (i - 1) cout << '\n';
		cout << "RFP #" << i << '\n';
		cout << mx.a << '\n';
		cin >> req >> p;
		i++;
	}
}
