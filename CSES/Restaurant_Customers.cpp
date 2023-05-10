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
//===================================================//
pii a[2*N5];
void solve() {
    int n;
    cin >> n;
    FOR(i, 1, n, 1) {
        int x, y;
        cin >> x >> y;
        a[i] = mp(x, y);
    }
    sort(a + 1, a + 1 + n,
        [](const pii& a, const pii& b) {
            if(a.S == b.S)
                return a.F < b.F;
            return a.S > b.S;
        }
    );
    int ans = 0, cnt = 1;
    FOR(i, 2, n, 1) {
        if(a[i].S <= a[i-1].F) {
            ans = max(ans, cnt);
            cnt = 1;
        } else {
            cnt++;
        }
    }
    cout << max(ans, cnt);
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