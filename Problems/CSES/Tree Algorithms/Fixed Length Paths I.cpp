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
#define int ll

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
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sor(x) sort(all(x)) 
#define pb push_back

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = ((b)-1); i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

const ll MOD = 1e9 + 7;
const ll MX = 1e9;
const ll INF = 1e18;
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
const int MXN = 2e5 + 5;
bitset<MXN> r;
int sz[MXN];
vi adj[MXN];
int n, k, ans = 0;

int dfs(int u, int p = -1) {
    sz[u] = 1;
    each(v, adj[u]) {
        if (v != p && !r[v]) {
            sz[u] += dfs(v, u);
        }
    }
    return sz[u];
}

int get_centroid(int u, int sz_subtree, int p = -1) {
    each(v, adj[u]) {
        if (v != p && !r[v]) {
            if (sz[v] * 2 > sz_subtree) {
                return get_centroid(v, sz_subtree, u);
            }
        }
    }
    return u;
}
vi c;
void find_d(int u, int p, int d = 1) {
    if (d <= k) c.pb(d);
    // cout << u + 1 << " " << p + 1 << "a\n";
    each(v, adj[u]) {
        if (!r[v] && p != v) {
            find_d(v, u, d + 1);
        }
    }
}

void centroid(int u = 0) {
    u = get_centroid(u, dfs(u));
    // cout << u + 1 << "\n";
    vl dp(k + 1, 0);
    dp[0] = 1;
    each(v, adj[u]) {
        if (!r[v]) {
            find_d(v, u);
            each(x, c) {
                // cout << x << " ";
                ans += dp[k - x];
            }
            // cout << "\n";
            each(x, c) dp[x]++;
            c.clear();
        }
    }
    r[u] = 1;
    each(v, adj[u]) {
        if (!r[v]) centroid(v);
    }
}

void solve() {

    cin >> n >> k;
    F0R(i, n - 1) {
        int u, v; cin >> u >> v;
        --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    centroid();
    cout << ans << "\n";
}

signed main() {
    setIO("");
    int T = 1;
    // cin >> T;
    for (test = 1; test <= T; test++) solve();
}