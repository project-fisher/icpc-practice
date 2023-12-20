#include <bits/stdc++.h>
#define llu unsigned long long
#define ll long long
#define lu unsigned long

using namespace std;

int main() {
	char s[102]; scanf("%s", s);
	int c = 0;
	int i = 0;
	while (s[i]) c += s[i++] == 'v' ? 1 : 2;
	printf("%d\n", c);
	return 0;
}
