// 0.020s/1822(1)
#include <bits/stdc++.h>
#include <numeric>
using namespace std;

short gcd(short a, short b){
	if (a && b) for(;(a %= b) && (b %= a););
	return a | b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	short data;
	cin >> data;
	while (data) {
		int resp;
		vector<short> val;
		val.push_back(data);
		cin >> data;
		while (data) {
			val.push_back(data);
			cin >> data;
		}
		sort(val.begin(), val.end());
		int t = val.size();
		short open = 0;
		for (resp = 0; resp <= val[0] - 5; resp++) {
			int offresp = resp + 5;
			for (auto i : val) {
				open += resp%(2*i) == 0;
				open -= (offresp - i)%(2*i) == 0;
			}
		}
		for (; resp <= 18001 && open != t; resp++) {
			int offresp = resp + 5;
			for (auto i : val) {
				open += resp%(2*i) == 0;
				open -= (offresp - i)%(2*i) == 0;
			}
		}
		if (--resp > 18000) cout << "Signals fail to synchronise in 5 hours" << '\n';
		else {
			cout << '0';
			cout << resp/3600;
			cout << ':';
			cout << setfill('0') << setw(2) << (resp%3600)/60;
			cout << ':';
			cout << setfill('0') << setw(2) << resp%60;
			cout << '\n';
		}
		cin >> data;
	}
}
