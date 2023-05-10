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

struct ST
{
    ll x;
    int y;
};


ST a[N];
bool cmp(const ST& a, const ST& b) {
    return a.x < b.x;
}
void solve() {
    int n; ll x;
    cin >> n >> x;

    FOR(i, 1, n, 1) {
        cin >> a[i].x;
        a[i].y = i;
    }
    sort(a + 1, a + 1 + n, cmp);
    int i = 1, j = n;
    while(i < j) {
        if(a[i].x + a[j].x == x) {
            cout << a[j].y << ' ' << a[i].y;
            return;
        }
        if(a[i].x + a[j].x > x)
            j--;
        if(a[i].x + a[j].x < x)
            i++;
    }
    cout << "IMPOSSIBLE";
}

int main() {
    fastio;
    setIO("");
    solve();
    return 0;
}
