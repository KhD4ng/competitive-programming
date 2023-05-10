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
//===================================================//
typedef long long ll;
typedef long double ld;
//===================================================//
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
bool prime(int n) {
    if(n < 2) return 0;
    for(int i = 2; i * i <= n; i++)
        if(n % i == 0) return 0;
    return 1;
}
//===================================================//
const int N = 2e5 + 1;
int a[N];
ll s[N];
void solve() {
    int n, x;
    s[0] = 0;
    cin >> n >> x;
    FOR(i, 1, n, 1) cin >> a[i], s[i] = s[i-1] + a[i];
    int ans = 0;
    int i = 1, j = 1;
    while(j <= n) {
        ll tmp = s[j] - s[i-1];
        if(tmp == x) {
            ans++;
            j++; //> x
            i++; //< x
        }
        if(tmp > x) {
            i++; 
        }
        if(tmp < x) {
            j++;
        }
    }
    cout << ans;
}

int main() {
    fastio;
    setIO("");
    solve();
    return 0;
}
