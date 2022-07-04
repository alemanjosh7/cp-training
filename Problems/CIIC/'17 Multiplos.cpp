#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
#define f first
#define s second

#define tcT template<class T
#define tcTU tcT, class U
tcT> using V = vector<T>;
tcT, size_t SZ > using AR = array<T, SZ>;
using vi = V<int>;
using vb = V<bool>;
using vl = V<ll>;
using vd = V<db>;
using vs = V<str>;
using vpi = V<pi>;
using vpl = V<pl>;

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define aint(x) bg(x), end(x)
#define raint(x) x.rbegin(), x.rend() 
#define sor(x) sort(aint(x)) 
#define pb push_back

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = ((b)-1); i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)


const db PI = acos((db)-1);
const int ddef[4]{ 1,0,-1,0 }, dataq[4]{ 0,1,0,-1 };
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(name)) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}
void _print(char i) { cerr << i; }
void _print(string i) { cerr << i; }
void _print(float i) { cerr << i; }
void _print(int i) { cerr << i; }
void _print(double i) { cerr << i; }
void _print() { cerr << "\n"; };
template<typename x, typename y> void _print(pair<x, y>& t) { cerr << "{";_print(t.first);cerr << ", ";_print(t.second);cerr << "},"; }
template<typename x> void _print(x& t) { cerr << "{"; for (int i = 0;i < (int)t.size();i++) { _print(t[i]); if (i < (int)t.size() - 1) cerr << ", "; } cerr << "}"; }
template<typename x, typename... y> void _print(x a, y... b) { _print(a);if (sizeof...(b)) cerr << ", ";_print(b...); }
#define dbg(x...) cerr<<"["<<#x<<"] = [";_print(x);cerr<<"]\n";
int test;

void solve() {

    int n, k, q; cin >> n >> k >> q;
    vi a(n);
    each(x, a) cin >> x;

    vi p(n + 1, 0);
    vector<vi> d(n + 1, vi(k, 0));

    F0R(i, n) {
        p[i + 1] = p[i] + a[i];
        p[i + 1] %= k;
    }

    // F0R(i, n + 1){
    //     cout << p[i] << " ";
    // }

    // cout << "\n";

    F0R(i, k) {
        F0R(j, n + 1) {
            d[j][i] = (p[j] == i);
        }
    }

    F0R(i, k) {
        F0R(j, n) {
            d[j + 1][i] += d[j][i];
        }
    }

    // F0R(i, k){
    //     cout << i << ": ";
    //     F0R(j, n + 1){
    //         cout << d[j][i] << " ";
    //     }

    //     cout << "\n";
    // }

    while (q--) {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        F0R(i, k) {
            int v;
            if (l - 2 < 0) {
                v = d[r][i];
            }
            else v = d[r][i] - d[l - 2][i];
            // cout << i << " " << v << "\n";
            ans += ((v - 1) * v) / 2;
        }
        cout << ans << "\n";
        // vl dp(k, 0);
        // int sum = 0, ans = 0;
        // dp[0] = 1;
        // FOR(i, l, r){
        //     sum += a[i];
        //     ans += dp[sum % k];
        //     dp[sum % k]++;
        // }
        // cout << ans << "\n";
    }
}