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
int n;
vi adj[MXN];
int L[MXN];
int jump[21][MXN];

void dfs(int u, int p, int l) {
    L[u] = l;
    jump[0][u] = p;
    each(v, adj[u]) {
        if (v != p) {
            dfs(v, u, l + 1);
        }
    }
}

void preprocess_LCA() {
    dfs(3, -1, 0);
    for (int i = 1; (1 << i) <= n; i++) {
        for (int j = 0; j <= n; j++) {
            jump[i][j] = jump[i - 1][jump[i - 1][j]];
        }
    }
}

int LCA(int p, int q) {
    int p_path = L[p], q_path = L[q];
    if (L[p] < L[q]) swap(p, q);
    int diff = L[p] - L[q];
    for (int i = 20; i >= 0; i--) {
        if (diff & (1 << i)) {
            p = jump[i][p];
        }
    }
    // cout << p_path << " " << q_path << " " << L[p] << "\n";
    if (p == q) {
        return abs(p_path - L[p]) + abs(q_path - L[p]);
    }
    for (int i = 20; i >= 0; i--) {
        if (jump[i][p] != jump[i][q]) {
            p = jump[i][p];
            q = jump[i][q];
        }
    }
    // cout << p_path << " " << q_path << " " << L[jump[0][p]] << "\n";
    return abs(p_path - L[jump[0][p]]) + abs(q_path - L[jump[0][p]]);
}

void solve() {
    int q; cin >> n >> q;
    F0R(i, n - 1) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    preprocess_LCA();
    // FOR(i, 1, n + 1){
    //     cout << L[i] << " ";
    // }

    // cout << "\n";

    while (q--) {
        int u, v; cin >> u >> v;
        cout << LCA(u, v) << "\n";
    }

}

int main() {
    setIO("");
    int T = 1;
    // cin >> T;
    for (test = 1; test <= T; test++) solve();
    return 0;
}