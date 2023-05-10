#include <bits/stdc++.h>
using namespace std;
//===================================================//
#define FOR(i,a,b) for(__typeof(b) i=a; i<=b; i++)
#define FOD(i,a,b) for(__typeof(b) i=b; i>=a; i--)
#define EACH(u, v) for(auto& u : v)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
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
        freopen((fileName+".inp").c_str(), "r", stdin);
        freopen((fileName+".out").c_str(), "w", stdout);
    }
}
//===================================================//
const int N = 2e5 + 1;
int a[N];
void solve() {
          int n;
          cin >> n;
          FOR(i, 1, n)
            cin >> a[i];
        sort(a + 1, 1 + a + n);
        int ans = 1;
        FOR(i, 2, n)
            if(a[i] != a[i-1]) ans++;
        cout << ans;
}

int main() {        
          fastio;
          setIO("");
          solve();
          return 0;
}