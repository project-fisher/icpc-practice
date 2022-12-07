#include <bits/stdc++.h>

using namespace std;

static const char rev[] = {
 0, '1', 'S', 'E', 0, 'Z', 0, 0, '8', 0,
 0, 0, 0, 0, 0, 0, 0,
 'A', 0, 0, 0, '3', 0, 0, 'H', 'I', 'L', 0, 'J', 'M', 0, 'O', 0, 0, 0, '2', 'T', 'U', 'V', 'W', 'X', 'Y', '5'
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string text;
	while (cin >> text) {
		cout << text << " -- is ";
		int init_pos = 0, final_pos = text.length() - 1;
		bool is_palindrome = 1, is_mirror = 1;
		while (init_pos <= final_pos && (is_palindrome || is_mirror)) {
			is_palindrome &= text[init_pos] == text[final_pos];
			is_mirror &= rev[text[init_pos] - '0'] == text[final_pos];
			init_pos++;
			final_pos--;
		}
		if (is_palindrome && is_mirror) cout << "a mirrored palindrome.";
		else if (is_mirror) cout << "a mirrored string.";
		else if (is_palindrome) cout << "a regular palindrome.";
		else cout << "not a palindrome.";
		cout << '\n';
		cout << '\n';
	}
}
