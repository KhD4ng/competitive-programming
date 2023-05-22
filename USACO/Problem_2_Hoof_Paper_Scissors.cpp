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
struct cow {
    int p, h, s;
} pre[N5];

void solve() {
    int n;
    cin >> n;
    FOR(i, 1, n, 1) {
        char c;
        cin >> c;
        if(c == 'P') {
            pre[i].p = pre[i-1].p + 1;
            pre[i].s = pre[i-1].s;
            pre[i].h = pre[i-1].h;
        }
        if(c == 'S') {
            pre[i].s = pre[i-1].s + 1;
            pre[i].p = pre[i-1].p;
            pre[i].h = pre[i-1].h;
        }
        if(c == 'H') {
            pre[i].h = pre[i-1].h + 1;
            pre[i].s = pre[i-1].s;
            pre[i].p = pre[i-1].p;
        }
    }
    //0
    int ans0;
    FOR(i, 1, n, 1) {
        ans0 = max({pre[n].h, pre[n].p, pre[n].s});
    }
    //1
    int ans1 = 0;   
    FOR(i, 2, n, 1) {
        //[1, i - 1]
        int cnt1 = max({pre[i-1].p, pre[i-1].h, pre[i-1].s});
        //[i, n]
        int cnt2 = max({pre[n].p - pre[i-1].p, pre[n].s - pre[i-1].s, pre[n].h - pre[i-1].h});
        ans1 = max(ans1, cnt1 + cnt2);
    }
    cout << max(ans0, ans1);
}

int main() {
    fastio;
    setIO("hps");
    int t;
    t = 1;
    //cin >> t;
    while(t--) {
        solve();
    };
    return 0;
}
