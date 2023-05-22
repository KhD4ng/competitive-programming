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
int last_true(int lo, int hi, function<bool(int)> f) {

	lo--;

	while (lo < hi) {

		int mid = lo + (hi - lo + 1) / 2;

		if (f(mid)) {

			lo = mid;

		} else {

			hi = mid - 1;

		}

	}

	return lo;

}


void solve() {

	int size;

	int max_ops;

	cin >> size >> max_ops;

	vector<int> arr(size);

	for (int &i : arr) { cin >> i; }


	sort(arr.begin(), arr.end());

	// Use 2e9 instead of INT32_MAX to avoid overflow

	cout << last_true(1, 2e9, [&](int x) {

		// Returns true if the median can be raised to x

		long long ops_needed = 0;

		for (int i = (size - 1) / 2; i < size; i++) {

			ops_needed += max(0, x - arr[i]);

		}

		return ops_needed <= max_ops;

	}) << endl;

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
