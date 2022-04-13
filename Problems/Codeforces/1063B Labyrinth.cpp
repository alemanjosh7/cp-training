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
const int INF = 1e9;
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
const int MXN = 1e6 + 5;

void solve() {

    int n, m, r, c, x, y;
    cin >> n >> m >> r >> c >> x >> y;
    --r, --c;
    string grid[n];
    //adj[i].s.f = LEFT
    //adj[i].s.f = RIGHT
    vector<pair<int, pair<int, int>>> adj[n * m];

    F0R(i, n) {
        str s;
        cin >> s;
        grid[i] = s;
    }

    int cnt = 0;
    int ori;
    F0R(i, n) {
        F0R(j, m) {
            cnt++;
            if (grid[i][j] == '*') continue;
            int v;
            cnt--;
            if (i == r && j == c) ori = cnt;
            int u = cnt;
            if (i - 1 >= 0 && grid[i - 1][j] != '*') {
                v = cnt - m;
                adj[u].pb({ v, {0, 0} });
            }
            if (j - 1 >= 0 && grid[i][j - 1] != '*') {
                v = cnt - 1;
                adj[u].pb({ v, {1, 0} });
            }
            if (i + 1 < n && grid[i + 1][j] != '*') {
                v = cnt + m;
                adj[u].pb({ v, {0, 0} });
            }
            if (j + 1 < m && grid[i][j + 1] != '*') {
                v = cnt + 1;
                adj[u].pb({ v, {0, 1} });
            }
            cnt++;
        }
    }
    // F0R(i, n * m){
    // 	cout << i << ": ";
    // 	F0R(j, sz(adj[i])){
    // 		cout << adj[i][j].f << " ";
    // 	}
    // 	cout << "\n";
    // }

    vector<pair<int, int>> d(n * m);
    F0R(i, n * m) {
        d[i].f = INF + 1;
        d[i].s = INF + 1;
    }

    d[ori] = { 0, 0 };

    deque<int> q;
    q.push_front(ori);

    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        each(edge, adj[v]) {
            int u = edge.f;
            // cout << v << " -> " << u << "\n";
            pair<int, int> w = edge.s;

            if (d[v].f + w.f < d[u].f && d[v].s + w.s < d[u].s) {
                d[u].f = d[v].f + w.f;
                d[u].s = d[v].s + w.s;
                if (w.f || w.s) {
                    q.push_back(u);
                }
                else q.push_front(u);
            }
        }
    }
    // cout << "\n";
    int ans = 0;
    cnt = 0;
    F0R(i, n) {
        F0R(j, m) {
            // cout << i + 1 << " " << j + 1 << ": ";
            // cout << d[cnt].f << " " << d[cnt].s << "\n";
            if (d[cnt].f <= x && d[cnt].s <= y) ans++;
            cnt++;
        }
    }

    cout << ans << "\n";

}

int32_t main() {
    setIO("");
    int T = 1;
    // cin >> T;
    for (test = 1; test <= T; test++) solve();
    return 0;
}