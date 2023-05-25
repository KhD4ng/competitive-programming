#include <bits/stdc++.h>
using namespace std;
//===================================================//
#define FOR(i,a,b,c) for(__typeof(b) i=a; i<=b; i += (__typeof(b))c)
#define FOD(i,a,b,c) for(__typeof(b) i=a; i>=b; i -= (__typeof(b))c)
#define EACH(u, v) for(auto& u : v)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define F first
#define S second
#define mp make_pair
#define pb push_back
//===================================================//
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
//===================================================//
const int N5 = 1e5 + 1;
const int N6 = 1e6 + 1;
const int N7 = 1e7 + 1;
const int N8 = 1e8 + 1;
const int N9 = 1e9 + 1;
const int MOD = 1e9 + 7;
const int d4x[] = {0, 0, 1, -1}, d4y[] = {1, -1, 0, 0};
const string stepDir = "RLDU";
const int d8x[] = {-1, 0, 1, -1, 1, -1, 0, 1}, d8y[] = {1, 1, 1, 0, 0, -1, -1, -1};
//===================================================//
void setIO(string fileName = "") {
	if(fileName.length()){
		freopen((fileName+".in").c_str(), "r", stdin);
		freopen((fileName+".out").c_str(), "w", stdout);
	}
}
void Nhap(int a[], int& n) {
	FOR(i, 1, n, 1) 
		cin >> a[i];
}
void Xuat(int a[], int n) {
	FOR(i, 1, n, 1)
		cout << a[i] << ' ';
}
//===================================================//
int a[2*N5];
int bin(int l, int r, function<bool(int)> f) {
	while(l < r) {
		int m = l + (r - l + 1) / 2;
		if(f(m)) {
			l = m;
		} else {
			r = m - 1;
		}
	}
	return l;
}
void solve() {
	int n, k;
	cin >> n >> k;
	Nhap(a, n);
	sort(a + 1, a + 1 + n);
	//(n + 1) / 2;
	cout << bin(1, 2e9, [&](int x) {
		ll cnt = 0;
		FOR(i, (n + 1) / 2, n, 1) {
			cnt += max(0, x - a[i]);
		}
		return cnt <= k;
	}) << '\n';
}

int main() {
	fastio;
	setIO("");
	int t;
	t = 1;
	//cin >> t;
	while(t--) {
		solve();
	};
	return 0;
}
