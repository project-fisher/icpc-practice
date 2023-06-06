// 0.000s/1124(3)
#include <bits/stdc++.h>
#include <string.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string tex, text;
	int t;
	cin >> t;
	cin.ignore();
	for (int z = 1; z <= t; z++) {
		getline(cin, tex);
		text = "";
		for (int i = 0; i < tex.length(); i++) if (tex[i] >= 'a' && tex[i] <= 'z')
			text += tex[i];
		int root = int(sqrt(float(text.length())));
		bool is_p = root*root == text.length();
		int init = 0, fin = text.length() - 1;
		int initx = 0, finx = text.length() - 1;
		while (init < fin && is_p) {
			is_p &= text[init] == text[fin];
			is_p &= text[initx] == text[finx];
			init++;
			initx += root;
			finx -= root;
			initx = initx >= text.length() ? (initx%text.length()) + 1: initx;
			finx = finx < 0 ? text.length() + finx - 1: finx;
			fin--;
		}
		cout << "Case #" << z << ":\n";
		if (is_p) cout << root;
		else cout << "No magic :(";
		cout << '\n';
	}
}
