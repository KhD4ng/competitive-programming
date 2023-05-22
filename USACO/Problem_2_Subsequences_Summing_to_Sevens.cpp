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
void Xuat(int a[], int t, int n) {
    FOR(i, t, n, 1)
        cout << a[i] << ' ';
}
//===================================================//
int pre[50001];
int check[7];
void solve() {
    FOR(i, 0, 6, 1) 
        check[i] = 0;
    int n;
    cin >> n;
    pre[0] = 0;
    FOR(i, 1, n, 1) {
        int x;
        cin >> x;
        pre[i] = (pre[i-1] + x) % 7;
        if(!check[pre[i]]) {
            check[pre[i]] = i;
        }
    }
    //dis = j - i;
    int ans = 0;
    FOD(i, n, 1, 1) {
        ans = max(ans, i - check[pre[i]]);
    }
    cout << ans;
}

int main() {
    fastio;
    setIO("div7");
    int t;
    t = 1;
    //cin >> t;
    while(t--) {
        solve();
    };
    return 0;
}
