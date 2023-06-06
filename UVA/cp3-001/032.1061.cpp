// 0.000s/375(1)
#include <bits/stdc++.h>

using namespace std;

bool TEST(char &msk, int pos) {
	return (msk&(1 << pos)) > 0;
}

void SET(char &msk, int pos) {
	msk |= (1 << pos);
}

char get_data(string in) {
	in.pop_back();
	char msk = 0;
	if (in == "AB") {
		SET(msk, 1);
		SET(msk, 2);
	} else if (in == "O") {
		SET(msk, 0);
	} else if (in == "A") {
		SET(msk, 1);
		SET(msk, 0);
	} else {
		SET(msk, 2);
		SET(msk, 0);
	}
	return msk;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string a, b, c;
	cin >> a >> b >> c;
	int cnt = 1;
	while (a != "E") {
		vector<string> data;
		if (c == "?") {
			bool only_minus = a.back() == '-' && b.back() == '-';
			char msk1 = get_data(a);
			char msk2 = get_data(b);
			if (TEST(msk1, 0) && TEST(msk2, 0)) data.push_back("O-");
			if ((TEST(msk1, 1) && TEST(msk2, 2)) || (TEST(msk1, 2) && TEST(msk2, 1))) data.push_back("AB-");
			if (TEST(msk1, 1) && (TEST(msk2, 1) || TEST(msk2, 0)) || TEST(msk2, 1) && (TEST(msk1, 1) || TEST(msk1, 0))) data.push_back("A-");
			if (TEST(msk1, 2) && (TEST(msk2, 2) || TEST(msk2, 0)) || TEST(msk2, 2) && (TEST(msk1, 2) || TEST(msk1, 0))) data.push_back("B-");
			char am = data.size();
			if (!only_minus) for (int i = 0; i < am; i++) {
				string temp = data[i];
				temp.back() = '+';
				data.push_back(temp);
			}
		} else {
			string d = a, e = b;
			if (d == "?") swap(e, d);
			e = c;
			bool has_minus = !(d.back() == '-' && c.back() == '+');
			d.pop_back();
			e.pop_back();
			if (e == "O") {
				if (d == "O") {
					data.push_back("O+");
					data.push_back("A+");
					data.push_back("B+");
				} else if (d == "A") {
					data.push_back("O+");
					data.push_back("A+");
					data.push_back("B+");
				} else if (d == "B") {
					data.push_back("O+");
					data.push_back("A+");
					data.push_back("B+");
				}
			} else if (e == "A") {
				if (d == "O") {
					data.push_back("AB+");
					data.push_back("A+");
				} else if (d == "A") {
					data.push_back("AB+");
					data.push_back("O+");
					data.push_back("A+");
					data.push_back("B+");
				} else if (d == "B") {
					data.push_back("AB+");
					data.push_back("A+");
				} else {
					data.push_back("AB+");
					data.push_back("O+");
					data.push_back("A+");
					data.push_back("B+");
				}
			} else if (e == "B") {
				if (d == "O") {
					data.push_back("AB+");
					data.push_back("B+");
				} else if (d == "A") {
					data.push_back("AB+");
					data.push_back("B+");
				} else if (d == "B") {
					data.push_back("AB+");
					data.push_back("O+");
					data.push_back("A+");
					data.push_back("B+");
				} else {
					data.push_back("AB+");
					data.push_back("O+");
					data.push_back("A+");
					data.push_back("B+");
				}
			} else {
				if (d == "AB") {
					data.push_back("AB+");
					data.push_back("A+");
					data.push_back("B+");
				} else if (d == "A") {
					data.push_back("AB+");
					data.push_back("B+");
				} else if (d == "B") {
					data.push_back("AB+");
					data.push_back("A+");
				}
			}
			char am = data.size();
			if (has_minus) for (int i = 0; i < am; i++) {
				string temp = data[i];
				temp.back() = '-';
				data.push_back(temp);
			}
			
		}
		cout << "Case " << cnt << ": ";
		if (a == "?") {
			if (data.empty()) cout << "IMPOSSIBLE";
			else {
				if (data.size() > 1) cout << '{';
				for (int i = 0; i < data.size() - 1; i++) {
					cout << data[i];
					cout << ", ";
				}
				cout << data.back();
				if (data.size() > 1) cout << '}';
			}
		} else cout << a;
		cout << ' ';
		if (b == "?") {
			if (data.empty()) cout << "IMPOSSIBLE";
			else {
				if (data.size() > 1) cout << '{';
				for (int i = 0; i < data.size() - 1; i++) {
					cout << data[i];
					cout << ", ";
				}
				cout << data.back();
				if (data.size() > 1) cout << '}';
			}
		} else cout << b;
		cout << ' ';
		if (c == "?") {
			if (data.size() > 1) cout << '{';
			for (int i = 0; i < data.size() - 1; i++) {
				cout << data[i];
				cout << ", ";
			}
			cout << data.back();
			if (data.size() > 1) cout << '}';
		} else cout << c;
		cout << '\n';
		cnt++;
		cin >> a >> b >> c;
	}
}
