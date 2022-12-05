#include <bits/stdc++.h>
#include <string.h>

using namespace std;

int valid(int a, int b) {
	return a >= 1 && a < 9 && b >= 1 && b < 9;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	char data[256];
	int pos, amount, k, l;
	while (cin >> data) {
		char matrix[9][9] = {0};
		char attacked[10][10] = {0};
		l = strlen(data);
		pos = 0;
		for (int i = 1; i < 9; i++) {
			int j = 1;
			while (pos < l && data[pos] != '/') {
				if (data[pos] <= 56) j += data[pos] - '0';
				else if (data[pos] >= 95 && data[pos] != 'p') matrix[i][j++] = data[pos] - 32;
				else matrix[i][j++] = data[pos];
				pos++;
			}
			pos++;
		}
		for (int i = 1; i < 9; i++) {
			for (int j = 1; j < 9; j++) {
				if (!matrix[i][j]) continue;
				attacked[i][j] = 1;
				switch (matrix[i][j]) {
					case 'K':
						attacked[i + 1][j + 1] = 1;
						attacked[i + 1][j] = 1;
						attacked[i + 1][j - 1] = 1;
						attacked[i][j + 1] = 1;
						attacked[i][j - 1] = 1;
						attacked[i - 1][j + 1] = 1;
						attacked[i - 1][j] = 1;
						attacked[i - 1][j - 1] = 1;
						break;
					case 'Q':
						for (k = 1; k < 8 && valid(i + k, j + k) && !matrix[i + k][j + k]; k++) 
							attacked[i + k][j + k] = 1;
						attacked[i + k][j + k] = 1;
						for (k = 1; k < 8 && valid(i + k, j - k) && !matrix[i + k][j - k]; k++) 
							attacked[i + k][j - k] = 1;
						attacked[i + k][j - k] = 1;
						for (k = 1; k < 8 && valid(i - k, j + k) && !matrix[i - k][j + k]; k++) 
							attacked[i - k][j + k] = 1;
						attacked[i - k][j + k] = 1;
						for (k = 1; k < 8 && valid(i - k, j - k) && !matrix[i - k][j - k]; k++) 
							attacked[i - k][j - k] = 1;
						attacked[i - k][j - k] = 1;
						for (k = 1; k < 8 && valid(i + k, j) && !matrix[i + k][j]; k++) 
							attacked[i + k][j] = 1;
						attacked[i + k][j] = 1;
						for (k = 1; k < 8 && valid(i - k, j) && !matrix[i - k][j]; k++) 
							attacked[i - k][j] = 1;
						attacked[i - k][j] = 1;
						for (k = 1; k < 8 && valid(i, j + k) && !matrix[i][j + k]; k++) 
							attacked[i][j + k] = 1;
						attacked[i][j + k] = 1;
						for (k = 1; k < 8 && valid(i, j - k) && !matrix[i][j - k]; k++) 
							attacked[i][j - k] = 1;
						attacked[i][j - k] = 1;
						break;
					case 'R':
						for (k = 1; k < 9 && valid(i + k, j) && !matrix[i + k][j]; k++) 
							attacked[i + k][j] = 1;
						attacked[i + k][j] = 1;
						for (k = 1; k < 9 && valid(i - k, j) && !matrix[i - k][j]; k++) 
							attacked[i - k][j] = 1;
						attacked[i - k][j] = 1;
						for (k = 1; k < 9 && valid(i, j + k) && !matrix[i][j + k]; k++) 
							attacked[i][j + k] = 1;
						attacked[i][j + k] = 1;
						for (k = 1; k < 9 && valid(i, j - k) && !matrix[i][j - k]; k++) 
							attacked[i][j - k] = 1;
						attacked[i][j - k] = 1;
						break;
					case 'B':
						for (k = 1; k < 9 && valid(i + k, j + k) && !matrix[i + k][j + k]; k++) 
							attacked[i + k][j + k] = 1;
						attacked[i + k][j + k] = 1;
						for (k = 1; k < 8 && valid(i + k, j - k) && !matrix[i + k][j - k]; k++) 
							attacked[i + k][j - k] = 1;
						attacked[i + k][j - k] = 1;
						for (k = 1; k < 8 && valid(i - k, j + k) && !matrix[i - k][j + k]; k++) 
							attacked[i - k][j + k] = 1;
						attacked[i - k][j + k] = 1;
						for (k = 1; k < 8 && valid(i - k, j - k) && !matrix[i - k][j - k]; k++) 
							attacked[i - k][j - k] = 1;
						attacked[i - k][j - k] = 1;
						break;
					case 'N':
						attacked[i + 2][j + 1] = 1;
						attacked[i + 2][j - 1] = 1;
						attacked[i + 1][j + 2] = 1;
						attacked[i + 1][j - 2] = 1;
						attacked[i - 1][j + 2] = 1;
						attacked[i - 1][j - 2] = 1;
						attacked[i - 2][j + 1] = 1;
						attacked[i - 2][j - 1] = 1;
						break;
					case 'P':
						attacked[i - 1][j - 1] = 1;
						attacked[i - 1][j + 1] = 1;
						break;
					case 'p':
						attacked[i + 1][j - 1] = 1;
						attacked[i + 1][j + 1] = 1;
				}
			}
		}
		amount = 64;
		for (int i = 1; i < 9; i++) for (int j = 1; j < 9; j++) amount -= attacked[i][j];
		cout << amount << '\n';
	}
	return 0;
}
