// 0.070s/97
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, r, b, players, player, movers, dice;
	cin >> n;
	while (n--) {
		cin >> players >> movers >> dice;
		char data[106];
		char players_data[players];
		for (int i = 0; i < players; i++) players_data[i] = 1;
		for (int i = 1; i < 100; i++) data[i] = i;
		data[100] = 100;
		data[101] = 100;
		data[102] = 100;
		data[103] = 100;
		data[104] = 100;
		data[105] = 100;
		for (int i = 0; i < movers; i++) {
			cin >> r >> b;
			data[r] = b;
		}
		player = -1;
		for (b = 0; b < dice && (player < 0 || players_data[player] != 100); b++) {
			player = (player + 1)*(player + 1 < players);
			cin >> r;
			players_data[player] = data[players_data[player] + r];
		}
		for (;b < dice; b++) cin >> r;
		for (int i = 1; i <= players; i++) {
			cout << "Position of player " << i;
			cout << " is " << (int)(players_data[i - 1]) << '.';
			cout << '\n';
		}
	}
}
