// 0.010s/1620
#include <bits/stdc++.h>

using namespace std;

char value(string card) {
	if (card[0] == 'A' || card[0] == 'K' || card[0] == 'Q' || card[0] == 'J' || card[0] == 'T') return 10;
	return card[0] - '0';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		vector<string> cards;
		string temp;
		for (int j = 0; j < 52; j++) {
			cin >> temp;
			cards.push_back(temp);
		}
		int y = 0;
		int top = 26;
		for (int j = 0; j < 3; j++) {
			string card = cards.at(top);
			cards.erase(cards.begin() + top);
			int x = value(card);
			y += x;
			top--;
			for (int k = 0; k < 10 - x; k++) cards.erase(cards.begin() + top--);
		}
		cout << "Case " << i << ": " << cards.at(--y) << '\n';
	}
}
