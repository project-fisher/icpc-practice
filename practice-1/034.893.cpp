// 0.000s/220
#include <bits/stdc++.h>

using namespace std;

bool isleap(int y) {
	return (y%400 == 0 || (y%100 && ((y&3) == 0))) ? 1 : 0;
}

void solv(long long int t, short &d, short &m, int &y) {
	d--;
	m--;
	short data[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	short mdata[12] = {365, 334, 306, 275, 245, 214, 184, 153, 122, 92, 61, 31};
	data[1] += isleap(y);
	if (t < data[m] - d) {
		d += t;
		return;
	} else if (d) {
		t -= data[m] - d;
		d = 0;
		m++;
	}
	if (m == 12) {
		m = 0;
		y++;
	}
	data[1] = 28 + isleap(y);
	mdata[1] += isleap(y);
	mdata[0] += isleap(y);
	if (t < mdata[m]) {
		while (t >= data[m]) {
			t -= data[m];
			m++;
		}
		d += t;
		return;	
	} else if (m) {
		t -= mdata[m];
		m = 0;
		y++;
	}
	while (y%400 && t >= 365 + isleap(y)) t -= 365 + isleap(y++);
	y += t/146097*400;
	t %= 146097;
	while (t >= 365 + isleap(y)) t -= 365 + isleap(y++);
	data[1] = 28 + isleap(y);
	while (t >= data[m]) {
		t -= data[m];
		m++;
	}
	d += t;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long int a = 0;
	short b, c;
	int d;
	scanf("%lld %hd %hd %d", &a, &b, &c, &d);
	while (a || b || c || d) {
		solv(a, b, c, d);
		printf("%hd %hd %d\n", ++b, ++c, d);
		a = 0;
		scanf("%lld %hd %hd %d", &a, &b, &c, &d);
	}
}
