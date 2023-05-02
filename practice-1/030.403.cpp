// 0.000s/533(1)
#include <bits/stdc++.h>

using namespace std;


const char * chars[5][27] = {{".***..", "****..", ".****.", "****..", "*****.", "*****.", ".****.", "*...*.", "*****.", "..***.", "*...*.", "*.....", "*...*.", "*...*.", ".***..", "****..", ".***..", "****..", ".****.", "*****.", "*...*.", "*...*.", "*...*.", "*...*.", "*...*.", "*****.", "......"},
                              {"*...*.", "*...*.", "*...*.", "*...*.", "*.....", "*.....", "*.....", "*...*.", "..*...", "...*..", "*..*..", "*.....", "**.**.", "**..*.", "*...*.", "*...*.", "*...*.", "*...*.", "*.....", "*.*.*.", "*...*.", "*...*.", "*...*.", ".*.*..", ".*.*..", "...*..", "......"},
                              {"*****.", "****..", "*.....", "*...*.", "***...", "***...", "*..**.", "*****.", "..*...", "...*..", "***...", "*.....", "*.*.*.", "*.*.*.", "*...*.", "****..", "*...*.", "****..", ".***..", "..*...", "*...*.", ".*.*..", "*.*.*.", "..*...", "..*...", "..*...", "......"},
                              {"*...*.", "*...*.", "*.....", "*...*.", "*.....", "*.....", "*...*.", "*...*.", "..*...", "*..*..", "*..*..", "*.....", "*...*.", "*..**.", "*...*.", "*.....", "*..**.", "*..*..", "....*.", "..*...", "*...*.", ".*.*..", "**.**.", ".*.*..", "..*...", ".*....", "......"},
                              {"*...*.", "****..", ".****.", "****..", "*****.", "*.....", ".***..", "*...*.", "*****.", ".**...", "*...*.", "*****.", "*...*.", "*...*.", ".***..", "*.....", ".****.", "*...*.", "****..", ".***..", ".***..", "..*...", "*...*.", "*...*.", "..*...", "*****.", "......"}};
void draw_char(bool s, char c, char (&matrix)[60][60], int x, int y) {
	if (c == ' ' || c == '|') return;
	if (s) {
		c -= 65;
		for (int i = 0; i < 5 && y + i < 60; i++)
			for (int j = 0; i + y >= 0 && j < 6 && x + j < 60; j++) {
				if (j + x < 0 || chars[i][c][j] == '.') continue;
				matrix[y + i][x + j] = chars[i][c][j];
			}
		return;
	}
	if (y > 59 || y < 0 || x > 59 || x < 0) return;
	matrix[y][x] = c;
}

void draw_string(bool s, string ss, char (&matrix)[60][60], int x, int y) {
	for (auto i : ss) {
		draw_char(s, i, matrix, x, y);
		x += 1 + 5*s;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string command, size;
	bool true_size;
	while (cin >> command) {
		char matrix[60][60];
		for (auto &v : matrix) for (auto &e : v) e = '.';
		while (command != ".EOP") {
			cin >> size;
			true_size = size[1] == '5';
			int row, col;
			cin >> row;
			row--;
			if (command[1] == 'P') {
				cin >> col;
				col--;
			}
			string data;
			char r;
			cin >> r;
			getline(cin, data);
			switch (command[1]) {
				case 'L':
					col = 0;
					break;
				case 'R':
					col = 60 - (1 + 5*true_size)*(data.length() - 1);
					break;
				case 'C':
					col = 30 - ((1 + 5*true_size)*(data.length() - 1) >> 1);
			}
			draw_string(true_size, data, matrix, col, row);
			cin >> command;
		}
		for (char i = 0; i < 60; i++) {
			for (char j = 0; j < 60; j++) cout << matrix[i][j];
			cout << '\n';
		}
		cout << '\n';
		for (int i = 0; i < 60; i++) cout << '-';
		cout << '\n' << '\n';
	}
}
