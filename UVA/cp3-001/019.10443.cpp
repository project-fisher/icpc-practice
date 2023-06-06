// 0.100s/126
#include <bits/stdc++.h>

using namespace std;

static const char data[4] = {
	'R', 0, 'S', 'P'
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, r, c, d;
	char t1, t2;
	cin >> n;
	for (int w = 0; w < n; w++) {
		if (w) cout << '\n';
		cin >> r >> c >> d;
		r++;
		c++;
		char matrix1[r + 1][c + 1];
		char matrix2[r + 1][c + 1];
		for (int i = 1; i < r; i++)
			for (int j = 1; j < c; j++) {
				cin >> matrix1[i][j];
				matrix2[i][j] = matrix1[i][j];
			}
		for (int x = 0; x < d; x++) {
			for (int i = 1; i < r; i++) {
				for (int j = 1; j < c; j++) {
					t1 = matrix1[i][j];
					t2 = data[t1 - 'P'];
					matrix2[i - 1][j] = matrix1[i - 1][j] == t2 ? t1 : matrix2[i - 1][j];
					matrix2[i][j - 1] = matrix1[i][j - 1] == t2 ? t1 : matrix2[i][j - 1];
					matrix2[i][j + 1] = matrix1[i][j + 1] == t2 ? t1 : matrix2[i][j + 1];
					matrix2[i + 1][j] = matrix1[i + 1][j] == t2 ? t1 : matrix2[i + 1][j];
				}
			}
			for (int i = 1; i < r; i++) {
				for (int j = 1; j < c; j++) {
					matrix1[i][j] = matrix2[i][j];
				}
			}

		}
		for (int i = 1; i < r; i++) {
			for (int j = 1; j < c; j++)
				cout << matrix1[i][j];
			cout << '\n';
		}

	}
}
