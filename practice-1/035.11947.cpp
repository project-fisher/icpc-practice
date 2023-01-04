#include <bits/stdc++.h>

using namespace std;

bool isleap(int y) {
	return (y%400 == 0 || (y%100 && ((y&3) == 0))) ? 1 : 0;
}

void solv(short &d, short &m, int &y) {
	short data[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	data[1] = 28 + isleap(y);
	for (int i = 0; i < 40; i++) {
		d = (d + 6)%data[m - 1] + 1;
		if (d < 8) {
			m = m%12 + 1;
			if (m == 1) {
				y++;
				data[1] = 28 + isleap(y);
			}
		}
	}
}

void show(short d, short m) {
	switch (m) {
		case 0:
			if (d <= 20) printf("capricorn");
			else printf("aquarius");
			break;
		case 1:
			if (d <= 19) printf("aquarius");
			else printf("pisces");
			break;
		case 2:
			if (d <= 20) printf("pisces");
			else printf("aries");
			break;
		case 3:
			if (d <= 20) printf("aries");
			else printf("taurus");
			break;
		case 4:
			if (d <= 21) printf("taurus");
			else printf("gemini");
			break;
		case 5:
			if (d <= 21) printf("gemini");
			else printf("cancer");
			break;
		case 6:
			if (d <= 22) printf("cancer");
			else printf("leo");
			break;
		case 7:
			if (d <= 21) printf("leo");
			else printf("virgo");
			break;
		case 8:
			if (d <= 23) printf("virgo");
			else printf("libra");
			break;
		case 9:
			if (d <= 23) printf("libra");
			else printf("scorpio");
			break;
		case 10:
			if (d <= 22) printf("scorpio");
			else printf("sagittarius");
			break;
		case 11:
			if (d <= 22) printf("sagittarius");
			else printf("capricorn");
			break;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int c;
	scanf("%d", &c);
	c++;
	short m, d;
	int y;
	for (int j = 1; j < c; j++) {
		getchar();
		m = (getchar() - '0')*10 + getchar() - '0';
		d = (getchar() - '0')*10 + getchar() - '0';
		y = (getchar() - '0')*1000 + (getchar() - '0')*100 + (getchar() - '0')*10 + getchar() - '0';
		solv(d, m, y);
		printf("%d %02hd/%02hd/%04d ", j, m, d, y%10000);
		show(d, m - 1);
		printf("\n");
	}
}
