// 0.010s/294(2)
// First interaction with bigint
// https://github.com/vmartinv/eldiego/blob/master/estructuras/bigint.cpp
#include <bits/stdc++.h>

using namespace std;
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef pair<int,int> ii;
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define dprint(v) cout << #v"=" << v << endl //;)

#define BASE 10
#define LMAX 500
struct bint{
    int l;
    int n[LMAX];
    bint(ll x=0){
        l=1;
        forn(i, LMAX){
            if (x) l=i+1;
            n[i]=x%BASE;
            x/=BASE;

        }
    }
    void out(){
		dforn(i, l) printf("%d", n[i]);//6=BASEXP!
	}
	void invar(){
		fill(n+l, n+LMAX, 0);
		while(l>1 && !n[l-1]) l--;
	}
};
bint operator+(const bint&a, const bint&b){
	bint c;
    c.l = max(a.l, b.l);
    ll q = 0;
    forn(i, c.l) q += a.n[i]+b.n[i], c.n[i]=q %BASE, q/=BASE;
    if(q) c.n[c.l++] = q;
    c.invar();
    return c;
}
pair<bint, bool> lresta(const bint& a, const bint& b)   // c = a - b
{
	bint c;
    c.l = max(a.l, b.l);
    ll q = 0;
    forn(i, c.l) q += a.n[i]-b.n[i], c.n[i]=(q+BASE) %BASE, q=(q+BASE)/BASE-1;
    c.invar();
    return make_pair(c, !q);
}
bint& operator-= (bint& a, const bint& b){return a=lresta(a, b).first;}
bint operator- (const bint&a, const bint&b){return lresta(a, b).first;}
bool operator< (const bint&a, const bint&b){return !lresta(a, b).second;}
bool operator<= (const bint&a, const bint&b){return lresta(b, a).second;}
bool operator==(const bint&a, const bint&b){return a <= b && b <= a;}
bint operator*(const bint&a, ll b){
    bint c;
    ll q = 0;
    forn(i, a.l) q += a.n[i]*b, c.n[i] = q %BASE, q/=BASE;
    c.l = a.l;
    while(q) c.n[c.l++] = q %BASE, q/=BASE;
    c.invar();
    return c;
}
bint operator*(const bint&a, const bint&b){
    bint c;
    c.l = a.l+b.l;
    fill(c.n, c.n+b.l, 0);
    forn(i, a.l){
        ll q = 0;
        forn(j, b.l) q += a.n[i]*b.n[j]+c.n[i+j], c.n[i+j] = q %BASE, q/=BASE;
        c.n[i+b.l] = q;
    }
    c.invar();
    return c;
}

int main() {
	long n;
	while (scanf("%ld", &n) == 1) {
		vector<long> a = {n};
		while (scanf("%ld", &n) == 1 && n != -999999) a.push_back(n);
		vector<int> z = {-1}; for (int i = 0; i < a.size(); ++i) if (!a[i]) z.push_back(i);
		z.push_back(a.size());
		vector<vector<int>> neg(z.size() - 1);
		int zz = 0;
		for (int i = 0; i < a.size(); ++i) {
			if (!a[i]) ++zz;
			else if (a[i] < 0) neg[zz].push_back(i);
		}
		ll mxt = *max_element(a.begin(), a.end());
		bool sign = mxt < 0;
		bint mx(abs(mxt));
		for (zz = 0; zz < z.size() - 1; ++zz) {
			if (neg[zz].size()&1) {
				if (z[zz] + 1 != neg[zz].back()) {
					bint mult(1);
					for (int i = z[zz] + 1; i < neg[zz].back(); ++i) mult = mult*a[i];
					if (sign) {
						sign = 0;
						mx = mult;
					} else if (mx < mult) mx = mult;
				}
				if (neg[zz].front() + 1 != z[zz + 1]) {
					bint mult(1);
					for (int i = neg[zz].front() + 1; i < z[zz + 1]; ++i) mult = mult*a[i];
					if (sign) {
						sign = 0;
						mx = mult;
					} else if (mx < mult) mx = mult;
				}
			} else if (z[zz] + 1 != z[zz + 1]) {
				bint mult(1);
				for (int i = z[zz] + 1; i < z[zz + 1]; ++i) mult = mult*a[i];
				if (sign) {
					sign = 0;
					mx = mult;
				} else if (mx < mult) mx = mult;
			}
		}
		if (sign) printf("-");
		mx.out();
		printf("\n");
	}
	return 0;
}
