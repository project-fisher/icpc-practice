// 0.000s/3412
#include <bits/stdc++.h>
#include <string.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	char tex[256];
	string text;
	cin.getline(tex, 256);
	while (strcmp(tex, "DONE")) {
		text = "";
		int l = strlen(tex);
		for (int i = 0; i < l; i++) if (tex[i] != ' ' && tex[i] != '.' && tex[i] != ',' && tex[i] != '?' && tex[i] != '!')
			text.push_back(tex[i] - (tex[i] > 96 ? 32 : 0));
		int init_pos = 0, final_pos = text.length() - 1;
		bool is_palindrome = 1;
		while (init_pos <= final_pos && is_palindrome) {
			is_palindrome &= text[init_pos] == text[final_pos];
			init_pos++;
			final_pos--;
		}
		if (is_palindrome) cout << "You won't be eaten!";
		else cout << "Uh oh..";
		cout << '\n';
		cin.getline(tex, 256);
	}
}
