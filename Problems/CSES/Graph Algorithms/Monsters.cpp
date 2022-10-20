#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll
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
#define yes cout << "Y" << "E" << "S\n";
#define no cout << "N" << "O\n";

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
const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };
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



/*

*/

int n, m;
vector<string> s;
vector<vi> adj;
int sz;
vi monsters;
vector<pi> trad;
void bfs_monsters(vi multi_source) {
    queue<int> q;
    vi d(sz, INF);
    each(x, multi_source) {
        q.push(x);
        d[x] = 0;
        monsters[x] = 0;
    }
    int u = multi_source[0];
    while (!q.empty()) {
        u = q.front(); q.pop();
        each(v, adj[u]) {
            if (monsters[v] <= d[v] && monsters[v] <= d[u] + 1) {
                continue;
            }
            pi x = trad[v];
            if (s[x.f][x.s] == 'M') {
                d[v] = 0;
                monsters[v] = min(monsters[v], d[v]);
                q.push(v);
            }
            else if (d[v] > d[u] + 1) {
                d[v] = d[u] + 1;
                monsters[v] = min(monsters[v], d[v]);
                q.push(v);
            }
        }
    }
}

map<int, bool> borders;

void bfs_me(int u) {
    queue<int> q;
    vi p(sz, -1);
    vi d(sz, INF);
    q.push(u);
    d[u] = 0;
    int idx;
    bool can = 0;
    if (borders[u]) {
        cout << "YES\n0\n";
        return;
    }
    while (!q.empty()) {
        u = q.front(); q.pop();
        each(v, adj[u]) {
            if (monsters[v] <= d[v] && monsters[v] <= d[u] + 1) {
                continue;
            }

            if (d[v] > d[u] + 1) {
                d[v] = d[u] + 1;
                p[v] = u;
                idx = v;
                q.push(v);
                if (borders[v]) {
                    can = 1;
                    break;
                }
            }
        }
        if (can) break;
    }
    if (!can) {
        cout << "NO\n";
        return;
    }
    vi v;
    while (idx != -1) {
        v.pb(idx);
        idx = p[idx];
    }

    reverse(all(v));
    str ans = "";
    cout << "YES\n" << sz(v) - 1 << "\n";
    FOR(i, 1, sz(v)) {
        if (v[i - 1] + m == v[i]) ans += 'D';
        else if (v[i - 1] - m == v[i]) ans += 'U';
        else if (v[i - 1] + 1 == v[i]) ans += 'R';
        else ans += 'L';
    }

    cout << ans << "\n";


}

void solve() {
    cin >> n >> m;
    s.resize(n, string(m, '#'));
    sz = n * m + 5;
    trad.resize(sz);
    adj.resize(sz);
    monsters.assign(sz, INF);
    F0R(i, n) {
        F0R(j, m) {
            trad[i * m + j] = { i, j };
            cin >> s[i][j];
            // cout << s[i][j] << " " << i * m + j << "\n";
        }
    }
    F0R(i, n) {
        int j = 0;
        borders[i * m + j] = 1;
        j = m - 1;
        borders[i * m + j] = 1;
    }

    F0R(j, m) {
        int i = 0;
        borders[i * m + j] = 1;
        i = n - 1;
        borders[i * m + j] = 1;
    }

    F0R(i, n) {
        F0R(j, m) {
            if (s[i][j] == '#') {
                continue;
            }
            if (i && s[i - 1][j] != '#') {
                adj[i * m + j].pb((i - 1) * m + j);
                // cout << (i - 1) * m + j << " " << i * m + j << "\n";
            }
            if (j && s[i][j - 1] != '#') {
                adj[i * m + j].pb(i * m + j - 1);
                // cout << i * m + j - 1 << " " << i * m + j << "\n";
            }
            if (i < n - 1 && s[i + 1][j] != '#') {
                adj[i * m + j].pb((i + 1) * m + j);
                // cout << i * m + j << " " << (i + 1) * m + j << "\n";
            }
            if (j < m + 1 && s[i][j + 1] != '#') {
                adj[i * m + j].pb(i * m + j + 1);
                // cout << i * m + j << " " << i * m + j + 1 << "\n";
            }
        }
        // cout << "\n";
    }
    vi multi_source;
    F0R(i, n) {
        F0R(j, m) {
            if (s[i][j] == 'M') {
                multi_source.pb(i * m + j);
            }
        }
    }

    bfs_monsters(multi_source);

    // F0R(i, n * m) cout << monsters[i] << "\n";

    F0R(i, n) {
        F0R(j, m) {
            if (s[i][j] == 'A') {
                bfs_me(i * m + j);
                return;
            }
        }
    }
    cout << "NO\n";

}

signed main() {
    setIO("");
    int T = 1;
    // cin >> T;
    for (test = 1; test <= T; test++) {
        // cout << "Case #" << test << ": " << a.f << " " << a.s << "\n";
        solve();
    }
}