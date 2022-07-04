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
const int MXN = 2e5;

ll st[4 * MXN + 5], a[MXN + 5];
int n, q;
int left(int node) { return 2 * node; }
int right(int node) { return 2 * node + 1; }
void pull(int node) { st[node] = min(st[left(node)], st[right(node)]); }

void build(int node = 1, int tl = 1, int tr = n) {
    if (tl == tr) {
        st[node] = a[tl];
        return;
    }
    int mid = (tl + tr) / 2;
    build(left(node), tl, mid);
    build(right(node), mid + 1, tr);
    pull(node);
}

void modify(int k, int u, int node = 1, int tl = 1, int tr = n) {
    if (tl == tr) {
        st[node] = u;
        return;
    }
    int mid = (tl + tr) / 2;
    if (tl <= k && k <= mid) modify(k, u, left(node), tl, mid);
    else modify(k, u, right(node), mid + 1, tr);
    pull(node);
}

ll query(int ql, int qr, int node = 1, int tl = 1, int tr = n) {
    // cout << tl << " " << tr << "\n";
    if (ql <= tl && tr <= qr) {
        return st[node];
    }
    if (ql > tr || tl > qr) {
        return INF;
    }
    int mid = (tl + tr) / 2;
    return min(query(ql, qr, left(node), tl, mid), query(ql, qr, right(node), mid + 1, tr));
}

void solve() {
    memset(st, INF, sizeof(st));
    cin >> n >> q;
    FOR(i, 1, n + 1) {
        cin >> a[i];
    }

    build();
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int k, u; cin >> k >> u;
            modify(k, u);
        }
        else {
            int l, r; cin >> l >> r;
            cout << query(l, r) << "\n";
        }
    }


}

int main() {
    setIO("");
    int T = 1;
    // cin >> T;
    for (test = 1; test <= T; test++) solve();
    return 0;
}