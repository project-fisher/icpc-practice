// 0.020s/352(1)
#include <bits/stdc++.h>

using namespace std;

typedef struct struct_suit {
	char number;
	int msk;
} suit;

void SET(int * msk, char pos) {
	*msk |= 1 << pos;
}

unsigned char TEST(int msk, char pos) {
	return msk & (1 << pos) ? 1 : 0;
}

void judge(string data, suit * s, suit * h, suit * c, suit * d) {
	suit * interest = c;
	switch (data[1]) {
		case 'S':
			interest = s;
			break;
		case 'H':
			interest = h;
			break;
		case 'D':
			interest = d;
	}
	interest->number++;
	switch (data[0]) {
		case 'K':
			SET(&(interest->msk), 12);
			break;
		case 'Q':
			SET(&(interest->msk), 11);
			break;
		case 'J':
			SET(&(interest->msk), 10);
			break;
		case 'T':
			SET(&(interest->msk), 9);
			break;
		case 'A':
			SET(&(interest->msk), 0);
			break;
		default:
			SET(&(interest->msk), data[0] - '0' - 1);
	}
}

void score(suit * a, char * base, char * total) {
	char temp = 4*TEST(a->msk, 0) + 3*TEST(a->msk, 12) + 2*TEST(a->msk, 11) + TEST(a->msk, 10);
	if (TEST(a->msk, 12) && a->number == 1) temp--;
	if (TEST(a->msk, 11) && a->number <= 2) temp--;
	if (TEST(a->msk, 10) && a->number <= 3) temp--;
	*base += temp;
	*total += temp;
	if (a->number == 2) (*total)++;
	if (a->number < 2) *total += 2;
}

char stopped(suit * a) {
	return TEST(a->msk, 0) || (TEST(a->msk, 12) && a->number >= 2) || (TEST(a->msk, 11) && a->number >= 3);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string data;
	while (cin >> data) {
		suit s, h, c, d;
		s.msk = 0; s.number = 0;
		h.msk = 0; h.number = 0;
		d.msk = 0; d.number = 0;
		c.msk = 0; c.number = 0;
		judge(data, &s, &h, &c, &d);
		for (int i = 1; i < 13; i++) {
			cin >> data;
			judge(data, &s, &h, &c, &d);
		}
		char base_score = 0;
		char total = 0;
		score(&s, &base_score, &total);
		score(&h, &base_score, &total);
		score(&c, &base_score, &total);
		score(&d, &base_score, &total);
		if (base_score >= 16 && stopped(&s) && stopped(&h) && stopped(&c) && stopped(&d)) {
			cout << "BID NO-TRUMP\n";
		} else if (total >= 14) {
			cout << "BID ";
			if (s.number >= h.number && s.number >= c.number && s.number >= d.number) cout << 'S'; 
			else if (h.number >= s.number && h.number >= c.number && h.number >= d.number) cout << 'H'; 
			else if (d.number >= h.number && d.number >= c.number && d.number >= s.number) cout << 'D'; 
			else cout << 'C';
			cout << '\n';
		} else {
			cout << "PASS\n";
		}
	}
}
