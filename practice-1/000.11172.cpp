// 0.000s/>10K(1)
#include <bits/stdc++.h>
using namespace std;

char solv(long int a, long int b) {
	return (a == b)*'=' + (a < b)*'<' + (a > b)*'>';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	long int a, b;
	cin >> n;
	while (n--) {
		cin >> a >> b;
		cout << solv(a, b) << '\n';
	}
}
