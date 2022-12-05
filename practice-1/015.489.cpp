#include <bits/stdc++.h>

using namespace std;

void SET(int * msk, char pos) {
	*msk |= 1 << pos;
}

int TEST(int msk, char pos) {
	return msk & (1 << pos);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int r, msk1, msk2, msk3;
	cin >> r;
	while (r != -1) {
		cout << "Round " << r << '\n';
		string text = "", text1 = "";
		msk1 = 0;
		cin >> text;
		for (auto c : text) {
			SET(&msk1, c - 'a');
		}
		cin >> text1;
		msk2 = 0;
		msk3 = 0;
		r = 0;
		for (auto c : text1) {
			SET(&msk2, c - 'a');
			r += ((msk3 != msk2) && !TEST(msk1, c - 'a')) ? 1 : 0;
			msk3 = msk2;
			if (r == 7 || (msk1 & msk2) == msk1) break;
		}
		msk3 = msk1 & msk2;
		if (r == 7) cout << "You lose.";
		else if (msk3 == msk1) cout << "You win.";
		else cout << "You chickened out.";
		cout << '\n';
		cin >> r;
	}
}
