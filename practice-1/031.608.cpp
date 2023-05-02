// 0.010s/207
#include <bits/stdc++.h>

using namespace std;

int msk(string j) {
	int data = 0;
	for (auto i : j) data |= 1 << (i - 'A');
	return data;
}

char det(string j) {
	if (j == "even") return 0;
	if (j == "up") return 1;
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string data;
	cin >> n;
	while (n--) {
		int msks[6];
		bool r[3] = {0};
		int nc = 0;
		int pc = -1;
		int appear = 0;
		int rights = -1;
		int lefts = -1;
		for (int i = 0; i < 3; i++) {
			cin >> data;
			msks[i << 1] = msk(data);
			appear |= msks[i << 1];
			cin >> data;
			msks[(i << 1) + 1] = msk(data);
			appear |= msks[(i << 1) + 1];
			cin >> data;
			if (data == "up") {
				r[i] = 1;
				lefts &= msks[i << 1];
				rights &= msks[(i << 1) + 1];
			} else if (data == "down") {
				r[i] = 1;
				swap(msks[i << 1], msks[(i << 1) + 1]);
				lefts &= msks[i << 1];
				rights &= msks[(i << 1) + 1];
			} else {
				nc |= msks[i << 1];
				nc |= msks[(i << 1) + 1];
			}
		}
		pc &= ~nc;
		pc &= appear;
		pc &= 4095;
		rights &= pc;
		lefts &= pc;
		// cout << 'p' << (bitset<32>)pc << '\n';
		if (!(lefts & (lefts - 1)) && !rights) {
			char pos = 0;
			while (!(lefts&(1 << pos))) pos++;
			pos += 'A';
			cout << pos;
			cout << " is the counterfeit coin and it is ";
			cout << "heavy";
			cout << ".\n";
		} else if (!lefts && !(rights & (rights - 1))) {
			char pos = 0;
			while (!(rights&(1 << pos))) pos++;
			pos += 'A';
			cout << pos;
			cout << " is the counterfeit coin and it is ";
			cout << "light";
			cout << ".\n";
		}

	}
}
