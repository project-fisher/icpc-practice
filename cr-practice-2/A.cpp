#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int k; cin >> k;
	int time = (21*60 + k)%(24*60);
	cout << setfill('0') << setw(2) << (time/60) << ':' << setw(2) << (time%60) << '\n';
	return 0;
}
