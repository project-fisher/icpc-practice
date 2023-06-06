// 0.000s/7374
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int r, c, cnt = 0;
	cin >> r >> c;
	while (r) {
		if (cnt) cout << '\n';
		r++;
		c++;
		char matrix[r + 1][c + 1];
		for (int i = 1; i < r; i++) {
			for (int j = 1; j < c; j++) {
				cin >> matrix[i][j];
				matrix[i][j] = matrix[i][j] == '.' ? 0 : '*';
			}
		}
		for (int i = 1; i < r; i++) {
			for (int j = 1; j < c; j++) {
				if (matrix[i][j] != '*') continue;
				matrix[i - 1][j - 1] += matrix[i - 1][j - 1] != '*';
				matrix[i - 1][j] += matrix[i - 1][j] != '*';
				matrix[i - 1][j + 1] += matrix[i - 1][j + 1] != '*';
				matrix[i][j - 1] += matrix[i][j - 1] != '*';
				matrix[i][j + 1] += matrix[i][j + 1] != '*';
				matrix[i + 1][j - 1] += matrix[i + 1][j - 1] != '*';
				matrix[i + 1][j] += matrix[i + 1][j] != '*';
				matrix[i + 1][j + 1] += matrix[i + 1][j + 1] != '*';
			}
		}
		cout << "Field #" << ++cnt << ':' << '\n';
		for (int i = 1; i < r; i++) {
			for (int j = 1; j < c; j++) {
				cout << (char)(matrix[i][j] + (matrix[i][j] == '*' ? 0 : '0'));
			}
			cout << '\n';
		}
		cin >> r >> c;
	}
}
